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

int mul32(int x, int y, int p) {
  return int(int64_t(x) * y % p);
}

int add32(int x, int y, int p) {
  int res = x + y;
  if (res >= p) res -= p;
  return res;
}

const int mod = 1000000007;

void fillBin(int f, std::vector<int>& bin) {
  if (f == 0) {
    bin[0] = 1;
    return;
  }
  bin[0] = 0;
  bin[1] = 1;
  int cur = 1;
  for (int i = 2; i <= f; i++) {
    cur = mul32(cur, f - i + 1, mod);
    cur = mul32(cur, inv(i - 1, mod), mod);
    bin[i] = cur;
  }
}

void run(std::istream &in, std::ostream &out) {
  int f, w, h;
  in >> f >> w >> h;
  std::vector<int> fBin(f + 1);
  std::vector<int> wBin(w + 1);
  fillBin(f, fBin);
  fillBin(w, wBin);
  std::vector<int> fact(w + 1);
  fact[0] = 1;
  for (int i = 1; i <= w; i++) {
    fact[i] = mul32(i, fact[i - 1], mod);
  }
  std::vector<int> whBin(w + 1);
  if (w == 0) whBin[0] = 1;
  for (int i = 1; i * (h + 1) <= w; i++) {
    whBin[i] = mul32(fact[w - h * i - 1], mul32(inv(fact[i - 1], mod), inv(fact[w - (h + 1) * i], mod), mod), mod);
  }
  int res1 = 0;
  int res2 = 0;
  for (int i = 0; i <= std::min(f, w); i++) {
    int add1 = mul32(fBin[i], wBin[i], mod);
    res1 = add32(res1, add1, mod);
    res1 = add32(res1, add1, mod);
    if (i + 1 <= f) {
      res1 = add32(res1, mul32(fBin[i + 1], wBin[i], mod), mod);
    }
    if (i + 1 <= w) {
      res1 = add32(res1, mul32(fBin[i], wBin[i + 1], mod), mod);
    }
  }
  for (int i = 0; i <= std::min(f, w); i++) {
    int add1 = mul32(fBin[i], whBin[i], mod);
    res2 = add32(res2, add1, mod);
    res2 = add32(res2, add1, mod);
    if (i + 1 <= f) {
      res2 = add32(res2, mul32(fBin[i + 1], whBin[i], mod), mod);
    }
    if (i + 1 <= w) {
      res2 = add32(res2, mul32(fBin[i], whBin[i + 1], mod), mod);
    }
  }
  int res = mul32(res2, inv(res1, mod), mod);
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}