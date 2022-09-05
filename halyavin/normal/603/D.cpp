#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct point {
  double x;
  double y;
  point(double x, double y) :
      x(x), y(y) {
  }
};

struct lpoint {
  int64_t x;
  int64_t y;
  int64_t q;
  lpoint(int64_t x, int64_t y, int64_t q) : x(x), y(y), q(q) {}
};

std::pair<int64_t, int64_t> inv2(int64_t x, int64_t p) {
  if (x == 1) {
    return {1, 0};
  }
  if (x == 0) {
    return {0, 1};
  }
  int64_t s = p / x;
  std::pair<int64_t, int64_t> res = inv2(p % x, x);
  return {res.second - s * res.first, res.first};
}

int64_t inv(int64_t x, int64_t p) {
  if (x < 0) {
    x += p;
  }
  std::pair<int64_t, int64_t> res = inv2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

const int64_t p1 = 1000000000000000003;
const int64_t p2 = 1000000000000000009;

std::pair<int32_t, int32_t> inv2(int32_t x, int32_t p) {
  if (x == 1) {
    return {1, 0};
  }
  if (x == 0) {
    return {0, 1};
  }
  int32_t s = p / x;
  std::pair<int32_t, int32_t> res = inv2(p % x, x);
  return {res.second - s * res.first, res.first};
}

int32_t inv(int32_t x, int32_t p) {
  if (x < 0) {
    x += p;
  }
  std::pair<int32_t, int32_t> res = inv2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

const int32_t q1 = 1000000000 + 7;
const int32_t q2 = 1000000000 + 9;
const int32_t q3 = 1000000000 + 21;
const int32_t q4 = 1000000000 + 33;

int64_t mul(int64_t x, int64_t y, int64_t p) {
  if (x < 0) x += p;
  if (y < 0) y += p;
  int64_t res = 0;
  while (x > 0) {
    if (x & 1) {
      res += y;
      if (res >= p) {
        res -= p;
      }
      x--;
    }
    x /= 2;
    y *= 2;
    if (y >= p) {
      y -= p;
    }
  }
  return res;
}

int getRatioMod(int64_t x, int64_t y, int p) {
  int ys = y % p;
  if (ys == 0) {
    return p + 1;
  }
  int res = ((x % p) * inv(ys, p)) % p;
  if (res < 0) {
    res += p;
  }
  return res;
}

int64_t gcd(int64_t x, int64_t y) {
  if (x == 0) {
    return y;
  }
  return gcd(y % x, x);
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<point> p;
  std::vector<lpoint> lp;
  int zero = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    in >> a >> b >> c;
    if (c == 0) {
      zero++;
      continue;
    }
    p.emplace_back(double(a * c) / double(a * a + b * b),
        double(b * c) / double(a * a + b * b));
    lp.emplace_back(a*c, b*c, a*a + b*b);
  }
  int64_t res = zero == 2 ? (n - 2) : 0;
  for (size_t i = 0; i < lp.size(); i++) {
    if (lp[i].x == 0 && lp[i].y == 0) {
      continue;
    }
    std::vector<std::array<int32_t, 4>> dp;
    for (size_t j = 0; j < i /* lp.size() */; j++) {
      if (j != i){
        int64_t x = lp[i].x*lp[j].q-lp[j].x*lp[i].q;
        int64_t y = lp[i].y*lp[j].q-lp[j].y*lp[i].q;
        int64_t d = gcd(std::abs(x), std::abs(y));
        x /= d;
        y /= d;
        if (y == 0) {
          dp.push_back({q1 + 1, q2 + 1, q3 + 1, q4 + 1});
          // dp.emplace_back(p1 + 1, p2 + 1);
        } else {
          dp.push_back({getRatioMod(x, y, q1), getRatioMod(x, y, q2), getRatioMod(x,y,q3), getRatioMod(x, y, q4)});
//          int32_t mod1 = y % q1 == 0 ? q1 + 1 : ((x % q1) * inv(y % q1, q1)) % q1;
//          int64_t mod1 = mul(x % p1, inv(y % p1, p1), p1);
//          int64_t mod2 = mul(x % p2, inv(y % p2, p2), p2);
////          std::cerr << inv(y % p1, p1) << " " << inv(y % p2, p2) << std::endl;
////          std::cerr << j << " " << i << " " << x << " " << y << " " << mod1 << " " << mod2 << std::endl;
//          dp.emplace_back(mod1, mod2);
        }
      }
    }
    std::sort(dp.begin(), dp.end());
    int group = 1;
    for (size_t j = 1; j < dp.size(); j++) {
      if (dp[j] == dp[j - 1]) {
        group++;
      } else {
        res += group * (group - 1) / 2;
        group = 1;
      }
    }
    res += group * (group - 1) / 2;
  }
  // res /= 3;
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}