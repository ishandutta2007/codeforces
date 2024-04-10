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
  int cur = 0;
  for (size_t i = 0; i < s.length() && cur < 26; i++) {
    if (s[i] - 'a' <= cur) {
      s[i] = (char)('a' + cur);
      cur++;
    }
  }
  if (cur < 26) {
    out << -1 << "\n";
  } else {
    out << s << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}