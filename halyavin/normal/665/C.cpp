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

void run(std::istream& in, std::ostream& out) {
  std::string s;
  in >> s;
  for (size_t i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      char c;
      for (c = 'a'; c <= 'c'; c++) {
        if (c != s[i - 1] && (i + 1 >= s.length() || c != s[i + 1])) {
          break;
        }
      }
      s[i] = c;
    }
  }
  out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}