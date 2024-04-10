#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s;
    in >> s;
    int ones = 0;
    int zeros = 0;
    for (char c : s) {
        if (c == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
    if (ones != zeros) {
        out << 1 << "\n";
        out << s << "\n";
    } else {
        out << 2 << "\n";
        std::string p1 = s.substr(0, 1);
        std::string p2 = s.substr(1);
        out << p1 << " " << p2 << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}