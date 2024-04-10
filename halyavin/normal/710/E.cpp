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
#include <queue>

const int64_t inf = 1LL << 60;

int64_t rec(std::vector<int64_t>& dyn, int n, int x, int y) {
  if (dyn[n] != inf) {
    return dyn[n];
  }
  int64_t res = n *int64_t(x);
  if (n % 2 == 0) {
    res = std::min(res, y + rec(dyn, n / 2 , x, y));
  } else {
    res = std::min(res, x + y + rec(dyn, (n - 1)/2, x, y));
    res = std::min(res, x + y + rec(dyn, (n + 1)/2, x, y));
  }
  dyn[n] = res;
  return res;
}

int64_t solve2(int n, int x, int y) {
  std::vector<int64_t> dyn(2 * n + 1, inf);
  dyn[0] = 0;
  dyn[1] = x;
  return rec(dyn, n, x, y);
}

void run(std::istream &in, std::ostream &out) {
  int n, x, y;
  in >> n >> x >> y;
  out << solve2(n, x, y);
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}