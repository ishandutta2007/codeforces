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

const int p = 1000000007;

int mul(int64_t x, int64_t y) {
  return int(((x % p) * (y % p)) % p);
}

int64_t isqrt(int64_t n) {
  int64_t left = 0;
  int64_t right = 10000000;
  while (right - left > 1) {
    int64_t middle = (left + right) / 2;
    if (middle * middle <= n) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return left;
}

void run(std::istream& in, std::ostream& out) {
  int64_t n, m;
  in >> n >> m;
  int64_t res = 0;
  int limit = isqrt(n);
  int cur;
  for (cur = 1; cur <= m && cur <= limit; cur++) {
    res = (res + n % cur) % p;
  }
  if (cur > m) {
    out << res << std::endl;
    return;
  }
  int64_t cur2 = cur;
  int s = n / cur2;
  for (; s > 0 && cur2 <= m; s--) {
    int64_t nxt = std::min(m + 1, n / s + 1);
    int64_t len = nxt - cur2;
    if (len & 1) {
      res = (res - mul(s, mul(len, (cur2 + nxt - 1) / 2))) % p;
    } else {
      res = (res - mul(s, mul(len / 2, cur2 + nxt - 1))) % p;
    }
    res = (res + mul(n, len)) % p;
    cur2 = nxt;
  }
  res = (res + mul(n, m - cur2 + 1)) % p;
  if (res < 0) { res += p; }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}