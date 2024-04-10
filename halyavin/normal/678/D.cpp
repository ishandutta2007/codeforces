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

using trans = std::pair<int64_t, int64_t>;

trans mul(trans f1, trans f2) {
  return {f1.first * f2.first % p, (f1.second * f2.first + f2.second) % p};
}

trans pow(trans f, int64_t n) {
  trans cur = {1, 0};
  trans ff = f;
  while (n > 0) {
    if (n % 2 != 0) {
      cur = mul(cur, ff);
    }
    n /= 2;
    ff = mul(ff, ff);
  }
  return cur;
}

void run(std::istream &in, std::ostream &out) {
  int64_t A, B, n, x;
  in >> A >> B >> n >> x;
  trans t = pow(trans(A, B), n);
  out << (t.first * x + t.second) % p << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}