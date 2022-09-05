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

void calc(int64_t n, int digits, int64_t cur, int mask, std::vector<int>& ns) {
  if (digits == 0) {
    if (cur < n) {
      ns[mask]++;
    }
    return;
  }
  for (int i = 0; i < 7; i++) {
    if ((mask & (1 << i)) == 0) {
      calc(n, digits - 1, cur * 7 + i, mask + (1 << i), ns);
    }
  }
}

void run(std::istream &in, std::ostream &out) {
  int64_t n, m;
  in >> n >> m;
  int digits1 = 1;
  int64_t mult1 = 7;
  while (mult1 < n) {
    digits1++;
    mult1 *= 7;
  }
  int digits2 = 1;
  int64_t mult2 = 7;
  while (mult2 < m) {
    digits2++;
    mult2 *= 7;
  }
  if (digits1 + digits2 > 7) {
    out << 0 << std::endl;
    return;
  }
  std::vector<int> n1(128);
  std::vector<int> n2(128);
  calc(n, digits1, 0, 0, n1);
  calc(m, digits2, 0, 0, n2);
  int ans = 0;
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      if ((i & j) == 0) {
        ans += n1[i] * n2[j];
      }
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