#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int n;
        in >> n;
        std::string s;
        in >> s;
        if (n < 11) {
            out << "NO\n";
            continue;
        }
        bool ans = false;
        for (int i = 0; i <= n - 11; i++) {
            if (s[i] == '8') {
                ans = true;
                break;
            }
        }
        if (ans) {
            out << "YES\n";
        } else {
            out << "NO\n";
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}