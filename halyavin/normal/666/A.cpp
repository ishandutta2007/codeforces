#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

void run(std::istream& in, std::ostream& out) {
  std::string s;
  in >> s;
  std::vector<std::array<bool, 2>> dyn(s.length() + 1);
  dyn[s.length() - 2][0] = true;
  dyn[s.length() - 3][1] = true;
  for (size_t i = s.length() - 4; i >= 5; i--) {
    dyn[i][0] = (dyn[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2)) ||
        dyn[i + 2][1];
    dyn[i][1] = (dyn[i + 3][1] && i + 6 <= s.length() && s.substr(i, 3) != s.substr(i + 3, 3)) ||
        dyn[i + 3][0];
  }
  std::vector<std::string> suffixes;
  for (size_t i = 5; i < s.length(); i++) {
    if (dyn[i][0]) {
      suffixes.push_back(s.substr(i, 2));
    }
    if (dyn[i][1]) {
      suffixes.push_back(s.substr(i, 3));
    }
  }
  std::sort(suffixes.begin(), suffixes.end());
  auto it = std::unique(suffixes.begin(), suffixes.end());
  suffixes.erase(it, suffixes.end());
  out << suffixes.size() << std::endl;
  for (std::string suffix : suffixes) {
    out << suffix << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}