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
  int x;
  int y;

  ipoint() : x(0), y(0) { }

  ipoint(int x, int y) : x(x), y(y) { }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  int p, q;
  in >> n >> p >> q;
  std::vector<ipoint> ps(n);
  for (int i = 0; i < n; i++) {
    in >> ps[i].x >> ps[i].y;
  }
  std::sort(ps.begin(), ps.end(), [](const ipoint& left, const ipoint& right) {
    int64_t l = int64_t(left.x) * right.y;
    int64_t r = int64_t(right.x) * left.y;
    return l < r || (l == r && left.x < right.x);
  });
  std::vector<ipoint> qs;
  qs.push_back(ps[0]);
  for (int i = 1; i < n; i++) {
    while (qs.size() >= 2) {
      ipoint& before = qs[qs.size() - 2];
      ipoint& last = qs.back();
      if (int64_t(last.x - before.x) * (ps[i].y - before.y) - int64_t(last.y - before.y) * (ps[i].x - before.x) >= 0) {
        qs.resize(qs.size() - 1);
      } else {
        break;
      }
    }
    qs.push_back(ps[i]);
  }
  double opt = 1e+100;
  for (int i = 0; i < qs.size(); i++) {
    opt = std::min(opt, std::max(p / double(qs[i].x), q / double(qs[i].y)));
    if (i > 0 && int64_t(qs[i].x) * q > int64_t(qs[i].y) * p && int64_t(qs[i - 1].x) * q < int64_t(qs[i - 1].y) * p) {
      int64_t det = int64_t(qs[i].x) * qs[i - 1].y - int64_t(qs[i].y) * qs[i - 1].x;
      int64_t sum1 = int64_t(p) * qs[i - 1].y - int64_t(q) * qs[i - 1].x;
      int64_t sum2 = int64_t(q) * qs[i].x - int64_t(p) * qs[i].y;
      double res = (sum1 + sum2) / double(det);
      opt = std::min(opt, res);
    }
  }
  out.precision(15);
  out << opt << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}