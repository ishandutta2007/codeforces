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
  int n;
  in >> n;
  std::vector<int64_t> p(n);
  for (int i = 0; i < n; i++) {
    in >> p[i];
  }
  std::string s;
  in >> s;
  int64_t sumA = 0;
  int64_t sumB = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      sumA += p[i];
    } else {
      sumB += p[i];
    }
  }
  int64_t ans = 0;
  int64_t xA = 0;
  int64_t xB = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      xA += p[i];
    } else {
      xB += p[i];
    }
    ans = std::max(std::max(ans, sumA - xA + xB), sumB - xB + xA);
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}