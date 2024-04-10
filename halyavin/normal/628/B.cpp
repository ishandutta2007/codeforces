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
  int64_t ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (((s[i] - '0') % 4) == 0) {
      ans++;
    }
  }
  for (int i = 0; i + 2 <= s.length(); i++) {
    int num = (s[i] - '0') * 10 + s[i + 1] - '0';
    if (num % 4 == 0) {
      ans += i + 1;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}