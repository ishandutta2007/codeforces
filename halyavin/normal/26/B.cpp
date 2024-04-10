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

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  int res = s.length();
  int level = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      level++;
    } else {
      if (level == 0) {
        res--;
      } else {
        level--;
      }
    }
  }
  res -= level;
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}