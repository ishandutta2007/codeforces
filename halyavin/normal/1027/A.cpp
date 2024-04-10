#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int T;
    in >> T;
    for (int test = 0; test < T; test++) {
        int n; std::string s;
        in >> n >> s;
        bool good = true;
        for (int i = 0; i < n/ 2; i++) {
            if (s[i] == s[n - 1 - i]) continue;
            if (s[i] - s[n - 1 - i] == 2 || s[i] - s[n - 1 - i] == -2) continue;
            good = false;
        }
        if (good) {
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