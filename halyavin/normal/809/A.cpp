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

int mul32(int x, int y) {
  return int(int64_t(x) * y % p);
}

int add32(int x, int y) {
  int res = x + y;
  if (res >= p) res -= p;
  return res;
}

int sub32(int x, int y) {
  int res = x - y;
  if (res < 0) res += p;
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    in >> xs[i];
  }
  std::sort(xs.begin(), xs.end());
  std::vector<int> pow2(n + 1);
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = (pow2[i - 1] * 2) % p;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = add32(res, mul32(xs[i], pow2[i]));
    res = sub32(res, mul32(xs[i], pow2[n - i - 1]));
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}