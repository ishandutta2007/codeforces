#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    std::string s;
    in >> s;
    int res = s.length();
    for (char c = 'a'; c <= 'z'; c++) {
        int prev = -1;
        int maxV = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                maxV = std::max(maxV, i - prev);
                prev = i;
            }
        }
        maxV = std::max<int>(maxV, s.length() - prev);
        res = std::min(res, maxV);
    }
    out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}