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

int64_t flen(int64_t n) {
  if (n < 2) {
    return 1;
  }
  return 2 * flen(n / 2) + 1;
}

int64_t f(int64_t n, int64_t len) {
  if (len == 0) {
    return 0;
  }
  if (n < 2) {
    return n;
  }
  int64_t l = flen(n / 2);
  if (len <= l) {
    return f(n / 2, len);
  }
  if (len == l + 1) {
    return (n / 2) + (n % 2);
  }
  return (n / 2) + (n % 2) + f(n / 2, len - l - 1);
}

void run(std::istream &in, std::ostream &out) {
  int64_t n;
  int64_t l, r;
  in >> n >> l >> r;
  out << f(n, r) - f(n, l - 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}