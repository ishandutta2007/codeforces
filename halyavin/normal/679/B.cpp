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



struct Solution {
  const static int precalcSize = 1000000;
  std::vector<int> f;
  std::vector<std::pair<int, int>> opt;


  void precalc() {
    f.resize(precalcSize);
    f[0] = 0;
    f[1] = 1;
    int prevCube = 1;
    for (int i = 2; prevCube < precalcSize; i++) {
      f[prevCube] = 1;
      int nextCube = std::min(precalcSize, i * i * i);
      for (int j = prevCube + 1; j < nextCube; j++) {
        f[j] = f[j - prevCube] + 1;
      }
      prevCube = nextCube;
    }
    opt.resize(precalcSize);
    opt[0] = std::make_pair(0, 0);
    for (int i = 1; i < opt.size(); i++) {
      if (f[i] >= opt[i - 1].first) {
        opt[i].first = f[i];
        opt[i].second = i;
      } else {
        opt[i] = opt[i - 1];
      }
    }
  }

  std::pair<int, int64_t> calc(int64_t m) {
    if (m < precalcSize) {
      return opt[m];
    }
    int64_t c = 0;
    while (c * c * c <= m) {
      c++;
    }
    c--;
    std::pair<int, int64_t> res = calc(m - c * c * c);
    res.first++;
    res.second += c * c * c;
    if (c > 0) {
      int64_t c1 = c - 1;
      int64_t m1 = c * c * c - c1 * c1 * c1 - 1;
      std::pair<int, int64_t> res2 = calc(m1);
      res2.first++;
      res2.second += c1 * c1 * c1;
      if (res2.first > res.first || (res2.first == res.first && res2.second > res.second)) {
        res = res2;
      }
    }
    return res;
  };

  void run(std::istream& in, std::ostream& out) {
    int64_t m;
    in >> m;
    precalc();
    std::pair<int, int64_t> res = calc(m);
    out << res.first << " " << res.second << std::endl;
  }
};

const int Solution::precalcSize;

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}