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

struct ipoint {
  int64_t x, y;
  ipoint() : x(0), y(0) {}
  ipoint(int64_t x, int64_t y) : x(x), y(y) {}
};

struct point {
  double x, y;
  point() : x(0), y(0) {}
  point(double x, double y) : x(x), y(y) {}
};

struct Solution {
  ipoint origin;
  int64_t v, t;
  int64_t vt;
  double pi2 = 2 * 3.14159265358979323;
  std::vector<std::pair<double, double>> intervals;

  void createIntervals(ipoint center, int64_t r) {
    int64_t sqDist = (center.x - origin.x) * (center.x - origin.x) +
        (center.y - origin.y) * (center.y - origin.y);
    if (sqDist <= r * r) {
      intervals.emplace_back(0, pi2);
      return;
    }
    if (uint64_t(sqDist) >= uint64_t(vt + r) * uint64_t(vt + r)) {
      return;
    }
    double alpha = atan2(center.y - origin.y, center.x - origin.x) + pi2 / 2;
    double beta;
    if (uint64_t(sqDist) <= uint64_t(vt * vt) + uint64_t(r * r)) {
      double sinBeta = r / sqrt(sqDist);
      beta = asin(sinBeta);
    } else {
      double cosBeta = ((double)(vt * vt) - (double)(r * r) + (double)sqDist) / (2 * vt * sqrt(sqDist));
      beta = acos(std::min(std::max(cosBeta, -1.0), 1.0));
    }
    double from = alpha - beta;
    double to = alpha + beta;
    if (from < 0) {
      intervals.emplace_back(from + pi2, pi2);
      from = 0;
    }
    if (to > pi2) {
      intervals.emplace_back(0, to - pi2);
      to = pi2;
    }
    intervals.emplace_back(from, to);
  }

  void run(std::istream& in, std::ostream& out) {
    in >> origin.x >> origin.y;
    in >> v >> t;
    vt = v * t;
    intervals.clear();
    int n;
    in >> n;
    vt = std::min(vt, 2828427125);
    for (int i = 0; i < n; i++) {
      ipoint center;
      int64_t r;
      in >> center.x >> center.y >> r;
      createIntervals(center, r);
    }
    std::sort(intervals.begin(), intervals.end());
    double p = 0;
    double last = 0;
    for (std::pair<double, double> cur : intervals) {
      last = std::max(last, cur.first);
      p += std::max(0.0, cur.second - last);
      last = std::max(last, cur.second);
    }
    out.precision(11);
    out << std::fixed;
    out << p / pi2 << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}