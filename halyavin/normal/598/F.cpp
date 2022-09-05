#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

struct ipoint {
  int x;
  int y;
};

void priv(std::vector<ipoint>& poly) {
  int idx = 2;
  for (size_t i = 2; i < poly.size(); i++) {
    int d1x = poly[idx - 1].x - poly[idx - 2].x;
    int d1y = poly[idx - 1].y - poly[idx - 2].y;
    int d2x = poly[i].x - poly[idx - 1].x;
    int d2y = poly[i].y - poly[idx - 1].y;
    if (int64_t(d1x) * d2y != int64_t(d1y) * d2x) {
      poly[idx] = poly[i];
      idx++;
    } else {
      poly[idx - 1] = poly[i];
    }
  }
  poly.resize(idx);
  int d1x = poly[1].x - poly[0].x;
  int d1y = poly[1].y - poly[0].y;
  int d2x = poly[0].x - poly[poly.size() - 1].x;
  int d2y = poly[0].y - poly[poly.size() - 1].y;
  if (int64_t(d1x) * d2y == int64_t(d1y) * d2x) {
    poly.resize(poly.size() - 1);
  }
}

double intersect(std::vector<ipoint>& poly, int64_t cx, int64_t cy,
    int64_t cc) {
  int n = poly.size();
  double result = 0;
  std::vector<int> sign(n);
  std::vector<int64_t> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = cx * poly[i].x + cy * poly[i].y - cc;
    if (diff[i] > 0) {
      sign[i] = 1;
    } else if (diff[i] < 0) {
      sign[i] = -1;
    } else {
      sign[i] = 0;
    }
  }
  std::vector<std::pair<double, double>> intervals;
  for (int i = 0; i < n; i++) {
    int inext = i < n - 1 ? i + 1 : 0;
    int signLeft = sign[i];
    int signRight = sign[inext];
    if (signLeft == -signRight && signLeft != 0) {
      double t = diff[inext] / (double) (diff[inext] - diff[i]);
      double px = poly[i].x * t + poly[inext].x * (1 - t);
      double py = poly[i].y * t + poly[inext].y * (1 - t);
      double p = px * cy - py * cx;
      intervals.emplace_back(p, p);
      continue;
    }
    if (signLeft == signRight && signLeft != 0) {
      continue;
    }
    if (signLeft == 0 && signRight == 0) {
      int iPrev = i > 0 ? i - 1 : n - 1;
      int iNext2 = inext < n - 1 ? inext + 1 : 0;
      double pLeft = int64_t(poly[i].x) * cy - int64_t(poly[i].y) * cx;
      double pRight = int64_t(poly[inext].x) * cy - int64_t(poly[inext].y) * cx;
      if (pLeft > pRight) {
        std::swap(pLeft, pRight);
      }
      if (sign[iPrev] == sign[iNext2]) {
        intervals.emplace_back(pLeft, pRight);
        intervals.emplace_back(pRight, pRight);
      } else {
        intervals.emplace_back(pLeft, pRight);
      }
      continue;
    }
    if (signLeft == 0) {
      continue;
    }
    if (signRight == 0) {
      int inext2 = inext < n - 1 ? inext + 1 : 0;
      if (sign[inext2] == -sign[i]) {
        int64_t p = int64_t(poly[inext].x) * cy - int64_t(poly[inext].y) * cx;
        intervals.emplace_back(p, p);
      }
      continue;
    }
  }
//  for (int i = 0; i < intervals.size(); i++) {
//    std::cout << intervals[i].first << " " << intervals[i].second << ";";
//  }
//  std::cout << std::endl;
  std::sort(intervals.begin(), intervals.end());
  for (size_t i = 0; i < intervals.size(); i += 2) {
    result += intervals[i + 1].second - intervals[i].first;
  }
  return result / hypot(cx, cy);
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<ipoint> poly;
  for (int i = 0; i < n; i++) {
    double x, y;
    in >> x >> y;
    poly.push_back( { lround(x * 100), lround(y * 100) });
  }
  priv(poly);
  out.precision(20);
  out << std::fixed;
  for (int i = 0; i < m; i++) {
    double x, y;
    in >> x >> y;
    ipoint a { lround(x * 100), lround(y * 100) };
    in >> x >> y;
    ipoint b { lround(x * 100), lround(y * 100) };
    int64_t cx = b.y - a.y;
    int64_t cy = a.x - b.x;
    int64_t cc = cx * a.x + cy * a.y;
    double res = intersect(poly, cx, cy, cc);
    out << (res * 1e-2) << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}