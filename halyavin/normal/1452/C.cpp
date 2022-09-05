#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

int maxOperations(const std::string &s) {
    if (s.empty()) {
        return 0;
    }
    int result = 0;
    int i = 0;
    int j = 0;
    while (true) {
        while (i < s.length() && s[i] != '(') {
            i++;
        }
        if (i == s.length()) {
            break;
        }
        j = std::max(j, i);
        while (j < s.length() && s[j] != ')') {
            j++;
        }
        if (j == s.length()) {
            break;
        }
        result++;
        i++;
        j++;
    }
    return result;
}

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        std::string s;
        in >> s;
        std::string sRound;
        std::string sSquare;
        for (char c : s) {
            switch (c) {
                case '(':
                    sRound.push_back('(');
                    break;
                case ')':
                    sRound.push_back(')');
                    break;
                case '[':
                    sSquare.push_back('(');
                    break;
                case ']':
                    sSquare.push_back(')');
                    break;
                default:
                    break;
            }
        }
        int answer = maxOperations(sRound) + maxOperations(sSquare);
        out << answer << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}