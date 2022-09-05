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
#include <array>

const int Dirs = 17;
const int CubeSize = 1 << Dirs;
const int mod = 1000000007;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

int sub32(int x, int y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
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

using Cube = std::array<int, CubeSize>;

inline bool next(uint32_t& x, uint32_t m) {
  uint32_t d = m - x;
  if (d == 0) return false;
  uint32_t lowest = d ^ (d - 1);
  x = (x ^ lowest) & m;
  return true;
}

Cube andf(Cube x, Cube y) {
  for (int i = 0; i < Dirs; i++) {
    uint32_t dm = 1 << i;
    for (uint32_t m = 0; m < x.size(); m++) {
      if ((m & dm) == 0) {
        x[m] = add32(x[m], x[m + dm]);
        y[m] = add32(y[m], y[m + dm]);
      }
    }
  }
  Cube res = {};
  for (uint32_t m = 0; m < res.size(); m++) {
    res[m] = mul32(x[m], y[m]);
  }
  for (int i = 0; i < Dirs; i++) {
    uint32_t dm = 1 << i;
    for (uint32_t m = 0; m < res.size(); m++) {
      if ((m & dm) == 0) {
        res[m] = sub32(res[m], res[m + dm]);
      }
    }
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  Cube c = {};
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    c[x]++;
  }
  Cube fib = {};
  fib[1] = 1;
  for (size_t i = 2; i < fib.size(); i++) {
    fib[i] = add32(fib[i - 1], fib[i - 2]);
  }

  Cube ab = {};
  for (uint32_t m = 0; m < c.size(); m++) {
    uint32_t x = 0;
    int res = 0;
    do {
      res = add32(res, mul32(c[x], c[m - x]));
    } while (next(x, m));
    ab[m] = res;
  }
  Cube de = {};
  {
    Cube f = c;
    for (size_t i = 0; i < Dirs; i++) {
      uint32_t dm = 1 << i;
      for (uint32_t m = 0; m < f.size(); m++) {
        if ((m & dm) == 0) {
          int a0 = add32(f[m], f[m + dm]);
          int a1 = sub32(f[m], f[m + dm]);
          f[m] = a0;
          f[m + dm] = a1;
        }
      }
    }

    int invSize = inv(1 << Dirs, mod);
    for (uint32_t m = 0; m < f.size(); m++) {
      de[m] = mul32(mul32(f[m], f[m]), invSize);
    }
    for (size_t i = 0; i < Dirs; i++) {
      uint32_t dm = 1 << i;
      for (uint32_t m = 0; m < f.size(); m++) {
        if ((m & dm) == 0) {
          int a0 = add32(de[m], de[m + dm]);
          int a1 = sub32(de[m], de[m + dm]);
          de[m] = a0;
          de[m + dm] = a1;
        }
      }
    }
  }
  for (uint32_t m = 0; m < ab.size(); m++) {
    ab[m] = mul32(ab[m], fib[m]);
    c[m] = mul32(c[m], fib[m]);
    de[m] = mul32(de[m], fib[m]);
  }
  Cube res = andf(andf(ab, c), de);
  int result = 0;
  for (int i = 0; i < Dirs; i++) {
    result = add32(result, res[1 << i]);
  }
  out << result << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}