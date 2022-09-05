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

template<class T>
T gcd(T x, T y) {
  while (y != T()) {
    T t = y;
    y = x % y;
    x = t;
  }
  return x;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
  if (x == 0) {
    return {0, 1};
  }
  T s = y / x;
  std::pair<T, T> res = gcd2(y % x, x);
  return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
  x = x % p;
  if (x < 0) {
    x += p;
  }
  std::pair<T, T> res = gcd2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

int64_t mathDiv(int64_t x, int64_t y) {
  if (x >= 0) {
    return x / y;
  }
  return (x - (y - 1)) / y;
}

int64_t solve(int64_t a1, int64_t a2, int64_t b1, int64_t b2, int64_t l, int64_t r) {
  l = std::max({l, b1, b2});
  if (l > r) {
    return 0;
  }
  b1 = b1 % a1;
  if (b1 < 0) b1 += a1;
  b2 = b2 % a2;
  if (b2 < 0) b2 += a2;
  int64_t d = gcd<int64_t>(a1, a2);
  if (b1 % d != b2 % d) {
    return 0;
  }
  int64_t c = (b2 - b1) % a2;
  if (c < 0) c += a2;
  c /= d;
  int aa2 = a2 / d;
  int aa1 = a1 / d;
  c = (c * inv<int64_t>(aa1, aa2)) % aa2;
  int64_t b = b1 + a1 * c;
  int64_t a = a1 * aa2;
  r -= b;
  l -= b;
  return mathDiv(r, a) - mathDiv(l - 1, a);
}

void run(std::istream &in, std::ostream &out) {
  int64_t a1, a2, b1, b2, l, r;
  in >> a1 >> b1 >> a2 >> b2 >> l >> r;
  out << solve(a1, a2, b1, b2, l, r) << std::endl;
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}