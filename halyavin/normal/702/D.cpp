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
  int64_t d, k, a, b, t;
  in >> d >> k >> a >> b >> t;
  int64_t ans;
  if (k >= d) {
    out << d * a << std::endl;
    return;
  } else {
    ans = k * a + (d - k) * b;
  }
  int64_t ks = (d - 1) / k;
  int64_t first = ks * (k * a + t);
  int64_t rest = d - k * ks;
  int64_t secondOpt = std::min(rest * a, rest * b - t);
  ans = std::min(ans, first + secondOpt);
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}