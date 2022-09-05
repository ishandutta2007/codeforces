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

bool bad(std::pair<int64_t, int64_t>& p1, std::pair<int64_t, int64_t>& p2, std::pair<int64_t, int64_t>& p3) {
  return (p3.first - p2.first) * (p2.second - p1.second) - (p2.first - p1.first) * (p3.second - p2.second) < 0;
}

int64_t getMax(int64_t a, int64_t b, std::vector<std::pair<int64_t, int64_t>>& points) {
  int left = 0;
  int right = points.size() - 1;
  while (right - left >= 3) {
    int middle1 = (2 * left + right) / 3;
    int middle2 = (left + 2 * right) / 3;
    // int64_t v1 = a * points[left].first + points[left].second;
    int64_t v2 = a * points[middle1].first + points[middle1].second;
    int64_t v3 = a * points[middle2].first + points[middle2].second;
    // int64_t v4 = a * points[right].first + points[right].second;
    if (v2 >= v3) {
      right = middle2;
    } else {
      left = middle1;
    }
  }
  int64_t opt = a * points[left].first + points[left].second;
  for (int i = left + 1; i <= right; i++) {
    opt = std::max(opt, a * points[i].first + points[i].second);
  }
  return opt + b;
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int64_t> as(n);
  int64_t opt = 0;
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int64_t a = 0;
  int64_t b = 0;
  std::vector<std::pair<int64_t, int64_t>> points;
  points.emplace_back(0, as[0]);
  opt = std::max(opt, (int64_t)as[0]);
  for (int i = 1; i < n; i++) {
    a -= as[i];
    b += as[i] * (i + 1);
    points.emplace_back(i, as[i] - a * int64_t(i) - b);
    while (points.size() > 2 &&
        bad(points[points.size() - 3], points[points.size() - 2], points[points.size() - 1])) {
      points[points.size() - 2] = points[points.size() - 1];
      points.resize(points.size() - 1);
    }
    opt = std::max(opt, getMax(a, b, points));
    if (i % 100 == 0) {
      for (size_t j = 0; j < points.size(); j++) {
        points[j].second += a * points[j].first;
      }
      a = 0;
    }
  }
  out << opt << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}