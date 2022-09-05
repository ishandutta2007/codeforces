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

struct point {
  double x, y;
  point() : x(0), y(0) {}
  point(double x, double y) : x(x), y(y) {}
  double distance(const point& other) const {
    return hypot(x - other.x, y - other.y);
  }
};

void getBest(const point& a, const point& t, const std::vector<point>& ps, int& idx1, double& opt1, int& idx2, double& opt2) {
  idx1 = -1;
  opt1 = 0;
  idx2 = 0;
  opt2 = ps[0].distance(a) - ps[0].distance(t);
  if (opt2 < opt1) {
    std::swap(opt1, opt2);
    std::swap(idx1, idx2);
  }
  for (size_t i = 1; i < ps.size(); i++) {
    double diff = ps[i].distance(a) - ps[i].distance(t);
    if (diff < opt1) {
      idx2 = idx1;
      opt2 = opt1;
      idx1 = i;
      opt1 = diff;
    } else if (diff < opt2) {
      idx2 = i;
      opt2 = diff;
    }
  }
}

void run(std::istream &in, std::ostream &out) {
  point a, b, t;
  in >> a.x >> a.y;
  in >> b.x >> b.y;
  in >> t.x >> t.y;
  double da = a.distance(t);
  double db = b.distance(t);
  int n;
  in >> n;
  std::vector<point> ps(n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    in >> ps[i].x >> ps[i].y;
    sum += 2 * ps[i].distance(t);
  }
  int idxA[2];
  double optA[2];
  int idxB[2];
  double optB[2];
  getBest(a, t, ps, idxA[0], optA[0], idxA[1], optA[1]);
  getBest(b, t, ps, idxB[0], optB[0], idxB[1], optB[1]);
  double opt = 1e+100;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (idxA[i] != idxB[j]) {
        opt = std::min(opt, optA[i] + optB[j]);
      }
    }
  }
  sum += opt;
  out.precision(12);
  out << sum << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}