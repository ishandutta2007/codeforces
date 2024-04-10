#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <array>

struct point {
  int x, y;
};

bool collinear(const point& a, const point& b) {
  return int64_t(a.x) * int64_t(b.y) == int64_t(a.y) * int64_t(b.x);
}

int64_t scalar(const point& a, const point& b) {
  return int64_t(a.x) * int64_t(b.x) + int64_t(a.y) * int64_t(b.y);
}

bool check(const std::array<point, 2>& interval1,
           const std::array<point, 2>& interval2,
           const std::array<point, 2>& interval3) {
  int c1 = -1, c2 = -1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (interval1[i].x == interval2[j].x &&
          interval1[i].y == interval2[j].y) {
        c1 = i;
        c2 = j;
      }
    }
  }
  if (c1 < 0) {
    return false;
  }
  point origin = interval1[c1];
  point dir1 = interval1[1 - c1];
  point dir2 = interval2[1 - c2];
  point d1 {dir1.x - origin.x, dir1.y - origin.y};
  point d2 {dir2.x - origin.x, dir2.y - origin.y};
  if (scalar(d1, d2) < 0) {
    return false;
  }
  if (collinear(d1, d2)) {
    return false;
  }
  bool flag1 = false;
  bool flag2 = false;
  for (int i = 0; i < 2; i++) {
    const point& p = interval3[i];
    point dp {p.x - origin.x, p.y - origin.y};
    if (collinear(dp, d1)) {
      if (scalar(dp, d1) < 0) {
        return false;
      }
      int64_t dist1 = int64_t(d1.x) * int64_t(d1.x) + int64_t(d1.y) * int64_t(d1.y);
      int64_t dist2 = int64_t(dp.x) * int64_t(dp.x) + int64_t(dp.y) * int64_t(dp.y);
      if (25 * dist2 < dist1) {
        return false;
      }
      if (25 * dist2 > 16 * dist1) {
        return false;
      }
      flag1 = true;
    }
    if (collinear(dp, d2)) {
      if (scalar(dp, d2) < 0) {
        return false;
      }
      int64_t dist1 = int64_t(d2.x) * int64_t(d2.x) + int64_t(d2.y) * int64_t(d2.y);
      int64_t dist2 = int64_t(dp.x) * int64_t(dp.x) + int64_t(dp.y) * int64_t(dp.y);
      if (25 * dist2 < dist1) {
        return false;
      }
      if (25 * dist2 > 16 * dist1) {
        return false;
      }
      flag2 = true;
    }
  }
  if (!(flag1 && flag2)) {
    return false;
  }
  return true;
}

void run(std::istream &in, std::ostream &out) {
  int t;
  in >> t;
  for (int test = 0; test < t; test++) {
    std::array<std::array<point,2>,3> intervals;
    for (size_t i = 0; i < intervals.size(); i++) {
      for (size_t j = 0; j < intervals[i].size(); j++) {
        in >> intervals[i][j].x >> intervals[i][j].y;
      }
    }
    bool good = false;
    for (int test = 0; test < 3; test++) {
      if (check(intervals[test], intervals[(test+1)%3], intervals[(test+2)%3])) {
        good = true;
        break;
      }
    }
    if (good) {
      out << "YES\n";
    } else {
      out << "NO\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}