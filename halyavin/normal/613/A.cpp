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

const double pi = 3.14159265358979323;

struct dpoint {
  double x, y;

  dpoint() : x(0), y(0) { }

  dpoint(double x, double y) : x(x), y(y) { }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  dpoint p;
  in >> n >> p.x >> p.y;
  std::vector<dpoint> points(n);
  for (int i = 0; i < n; i++) {
    in >> points[i].x >> points[i].y;
  }
  double maxR = 0;
  double minR = 1e10;
  for (int i = 0; i < n; i++) {
    double dist1 = hypot(points[i].x - p.x, points[i].y - p.y);
    maxR = std::max(maxR, dist1);
    minR = std::min(minR, dist1);
    dpoint& p1 = points[i];
    dpoint& p2 = points[(i + 1) % n];
    if ((p2.x - p1.x) * (p.x - p1.x) + (p2.y - p1.y) * (p.y - p1.y) > 0.5 &&
        (p1.x - p2.x) * (p.x - p2.x) + (p1.y - p2.y) * (p.y - p2.y) > 0.5) {
      double a = p1.y - p2.y;
      double b = p2.x - p1.x;
      double dist = a * p.x + b * p.y - a * p1.x - b * p1.y;
      dist /= hypot(a, b);
      minR = std::min(minR, std::abs(dist));
    }
  }
  out.precision(20);
  out << std::fixed;
  out << (maxR * maxR - minR * minR) * pi << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}