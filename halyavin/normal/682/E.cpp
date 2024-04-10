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
#include <cmath>
#include <array>

struct ipoint {
  int64_t x, y;
  ipoint() = default;
  ipoint(int64_t x, int64_t y) : x(x), y(y) {}
  bool operator==(const ipoint& other) const {
    return other.x == x && other.y == y;
  }
  bool operator!=(const ipoint& other) const {
    return other.x != x || other.y != y;
  }
};

std::vector<ipoint> convexHull(std::vector<ipoint>& points) {
  std::vector<ipoint> res;
  ipoint o = points[0];
  for (ipoint p : points) {
    if (p.y < o.y || (p.y == o.y && p.x < o.x)) {
      o = p;
    }
  }
  res = points;
  std::sort(res.begin(), res.end(), [&o](const ipoint& left, const ipoint& right) {
    if (left == o) {
      return right != o;
    }
    int64_t area = (left.x - o.x) * (right.y - o.y) - (left.y - o.y) * (right.x - o.x);
    if (area > 0) {
      return true;
    }
    if (area < 0) {
      return false;
    }
    return (left.x - o.x) * (left.x - o.x) + (left.y - o.y) * (left.y - o.y) < (right.x - o.x) * (right.x - o.x) + (right.y - o.y) * (right.y - o.y);
  });
  int last = 1;
  for (size_t i = 2; i < res.size(); i++) {
    while (last >= 1) {
      int64_t area = (res[last].x - res[last - 1].x) * (res[i].y - res[last].y) - (res[last].y - res[last - 1].y) * (res[i].x - res[last].x);
      if (area <= 0) {
        last--;
      } else {
        break;
      }
    }
    last++;
    res[last] = res[i];
  }
  res.resize(last + 1);
  return res;
}

#include <random>

void run(std::istream &in, std::ostream &out) {
  int n;
  int64_t s;
  in >> n >> s;
  std::vector<ipoint> points(n);
  for (int i = 0; i < n; i++) {
    in >> points[i].x >> points[i].y;
  }
//  n = 5000;
//  points.resize(5000);
//  std::mt19937 rnd;
//  for (int i = 0; i < 5000; i++) {
//    points[i].x = rnd() % 100u;
//    points[i].y = rnd() % 100u;
//  }
  std::vector<ipoint> hull = convexHull(points);
  std::array<int, 3> optTriangle = {};
  int64_t optArea = 0;
  int m = hull.size();
  for (int i = 0; i < m; i++) {
    int k = (i + 1) % m;
    for (int j = (i + 2) % m; j != i; j = (j + 1) % m) {
      ipoint dij(hull[j].x - hull[i].x, hull[j].y - hull[i].y);
      int64_t area = std::abs(dij.x * (hull[k].y - hull[i].y) - dij.y * (hull[k].x - hull[i].x));
      while ((k + 1) % m != j) {
        int nk = (k + 1) % m;
        int64_t narea = std::abs(dij.x * (hull[nk].y - hull[i].y) - dij.y * (hull[nk].x - hull[i].x));
        if (narea < area) break;
        k = nk;
        area = narea;
      }
      if (area > optArea) {
        optArea = area;
        optTriangle = std::array<int, 3> {i, k, j};
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    out << hull[optTriangle[i]].x + hull[optTriangle[(i + 1) % 3]].x - hull[optTriangle[(i + 2) % 3]].x;
    out << " ";
    out << hull[optTriangle[i]].y + hull[optTriangle[(i + 1) % 3]].y - hull[optTriangle[(i + 2) % 3]].y;
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}