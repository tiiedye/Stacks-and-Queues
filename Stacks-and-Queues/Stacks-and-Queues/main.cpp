#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s) {
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.

    std::stack<char> stack;
    std::queue<char> queue;

    for (char c : s) {
        c = std::toupper(c);
        queue.push(c);
        stack.push(c);
    }

    char char1{};
    char char2{};

    while (!queue.empty()) {
        char1 = queue.front();
        queue.pop();
        char2 = stack.top();
        stack.pop();
        
        if (char1 != char2) {
            return false;
        }
    }

    return true;
}

void run_palindrome() {
    std::string user_string;
    char cont;

    std::cout << "Enter a word, and I'll tell you if it's a palindrome: ";
    std::cin >> user_string;

    std::cout << std::setw(8) << std::left << is_palindrome(user_string) << user_string << std::endl;

    std::cout << "\nWould you like to enter another word? (Y/N): ";
    std::cin >> cont;
    std::cout << std::endl;

    if (std::toupper(cont) == 'Y') {
        run_palindrome();
    }
    else if (std::toupper(cont) == 'N') {
        std::cout << "Goodbye!" << std::endl;
    }
    else {
        std::cout << "Unknown selection. Terminating Program. Goodbye!" << std::endl;
    }
}

int main() {
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;

    run_palindrome();

    return 0;
}
