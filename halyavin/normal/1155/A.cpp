#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s;
    in >> s;
    for (size_t i = 0; i + 1 < s.length(); i++) {
        if (s[i] > s[i + 1]) {
            out << "YES\n";
            out << (i + 1) << " " << (i + 2) << "\n";
            return;
        }
    }
    out << "NO\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}