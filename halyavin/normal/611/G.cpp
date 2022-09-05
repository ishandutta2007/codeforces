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

const int mod = 1000000007;

struct point {
  int x, y;
};

struct Solution {
  int n;
  std::vector<point> p;

  int64_t allArea;
  int64_t ans;

  std::vector<int64_t> sumX;
  std::vector<int64_t> sumY;

  int64_t getSumX(int from, int to) {
    if (to >= from) {
      return sumX[to + 1] - sumX[from];
    }
    return sumX[n] - sumX[from] + sumX[to + 1] - sumX[0];
  }

  int64_t getSumY(int from, int to) {
    if (to >= from) {
      return sumY[to + 1] - sumY[from];
    }
    return sumY[n] - sumY[from] + sumY[to + 1] - sumY[0];
  }

  int64_t area(int i1, int i2, int i3) {
    return int64_t(p[i2].x - p[i1].x) * int64_t(p[i3].y - p[i1].y) -
           int64_t(p[i2].y - p[i1].y) * int64_t(p[i3].x - p[i1].x);
  }

  std::array<int64_t, 3> areaC(int i1, int i2) {
    std::array<int64_t, 3> res;
    res[2] = int64_t(p[i2].x - p[i1].x);
    res[1] = -int64_t(p[i2].y - p[i1].y);
    res[0] = int64_t(p[i2].x - p[i1].x) * -p[i1].y - int64_t(p[i2].y - p[i1].y) * -p[i1].x;
    return res;
  };

  int prev(int x) {
    if (x > 0) {
      return x - 1;
    }
    return n - 1;
  }

  int next(int x) {
    if (x < n - 1) {
      return x + 1;
    }
    return 0;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
      in >> p[i].x >> p[i].y;
    }
    allArea = 0;
    for (int i = 2; i < n; i++) {
      allArea += area(0, i - 1, i);
    }
    if (allArea < 0) {
      std::reverse(p.begin(), p.end());
      allArea = -allArea;
    }
    sumX.resize(n + 1);
    sumY.resize(n + 1);
    for (int i = 0; i < n; i++) {
      sumX[i + 1] = sumX[i] + p[i].x;
      sumY[i + 1] = sumY[i] + p[i].y;
    }
    ans = (int64_t(n) * int64_t(n - 3) / 2) % mod;
    ans = (ans * (allArea % mod)) % mod;
    int curb = 0;
    int64_t curArea = 0;
    int64_t sumArea = 0;
    int cure;
    for (cure = 2; cure < n; cure++) {
      int64_t newArea = curArea + area(0, cure - 1, cure);
      if (newArea > allArea - newArea) break;
      curArea = newArea;
      sumArea = (sumArea + curArea) % mod;
    }
    cure--;
    while (true) {
      ans = (ans - 2 * sumArea) % mod;
      if (curArea * 2 == allArea) {
        ans = (ans + curArea) % mod;
      }
      int k = (cure - curb + n) % n - 1;
      std::array<int64_t, 3> coeff = areaC(curb, curb + 1);
      if (k > 0) {
        sumArea = (sumArea - (coeff[0] % mod) * k) % mod;
        sumArea = (sumArea - (coeff[1] % mod) * (getSumX(curb + 2, cure) % mod)) % mod;
        sumArea = (sumArea - (coeff[2] % mod) * (getSumY(curb + 2, cure) % mod)) % mod;
      }
      curArea -= area(curb, next(curb), cure);
      curb++;
      if (curb == n) break;
      while (true) {
        int nexte = next(cure);
        int64_t newArea = curArea + area(curb, cure, nexte);
        if (newArea > allArea - newArea) break;
        curArea = newArea;
        sumArea = (sumArea + curArea) % mod;
        cure = nexte;
      }

    }
    if (ans < 0) {
      ans += mod;
    }
    out << ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}