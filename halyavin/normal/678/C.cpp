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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

void run(std::istream &in, std::ostream &out) {
  int64_t n, a, b, p, q;
  in >> n >> a >> b >> p >> q;
  int64_t na = n / a;
  int64_t nb = n / b;
  int64_t nab = n / (a * b / gcd(a, b));
  na -= nab;
  nb -= nab;
  out << na * p + nb * q + nab * std::max(p, q) << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}