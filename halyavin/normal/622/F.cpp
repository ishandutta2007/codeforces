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

int add32(int x, int y) {
  return (x + y) % p;
}

int mul32(int x, int y) {
  return int(int64_t(x) * y % p);
}

int pow32(int x, int k) {
  int res = 1;
  int mul = x;
  while (k > 0) {
    if (k & 1) {
      res = mul32(res, mul);
    }
    mul = mul32(mul, mul);
    k /= 2;
  }
  return res;
}

void run(std::istream& in, std::ostream& out) {
  int n, k;
  in >> n >> k;
  int points = k + 2;
  std::vector<int> values(points);

  int sum = 0;
  for (int i = 1; i <= k + 1; i++) {
    sum = add32(sum, pow32(i, k));
    values[i] = sum;
  }
  if (n <= k + 1) {
    out << values[n] << std::endl;
    return;
  }
  int multiplier = 1;
  for (int i = 0; i < points; i++) {
    multiplier = mul32(multiplier, n - i);
  }
  std::vector<int> coeffMult(points);
  int cur = 1;
  for (int i = 1; i < points; i++) {
    cur = mul32(p - i, cur);
  }
  coeffMult[0] = cur;
  for (int i = 1; i < points; i++) {
    cur = mul32(cur, inv<int>(p - (points - i), p));
    cur = mul32(cur, i);
    coeffMult[i] = cur;
  }
  int res = 0;
  for (int i = 0; i < points; i++) {
    int nPoly = mul32(multiplier, inv<int>(n - i, p));
    int lagrangePoly = mul32(nPoly, inv<int>(coeffMult[i], p));
    res = add32(res, mul32(lagrangePoly, values[i]));
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}