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
  int max = 0;
  for (int len = s.length(); len > 0; len--) {
    for (int i = 0; i <= (int)s.length() - len; i ++) {
      for (int j = i + 1; j <= (int)s.length() - len; j++) {
        if (s.substr(i, len) == s.substr(j, len)) {
          out << len << std::endl;
          return;
        }
      }
    }
  }
  out << 0 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}