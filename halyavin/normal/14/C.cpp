#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct ipoint {
  int x, y;
};
void run(std::istream &in, std::ostream &out) {
  std::array<std::array<ipoint, 2>, 4> intervals;
  for (int i = 0; i < 4; i++) {
    in >> intervals[i][0].x >> intervals[i][0].y;
    in >> intervals[i][1].x >> intervals[i][1].y;
  }
  int minX = intervals[0][0].x;
  int maxX = minX;
  int minY = intervals[0][0].y;
  int maxY = minY;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      minX = std::min(minX, intervals[i][j].x);
      maxX = std::max(maxX, intervals[i][j].x);
      minY = std::min(minY, intervals[i][j].y);
      maxY = std::max(maxY, intervals[i][j].y);
    }
  }
  if (minX == maxX || minY == maxY) {
    out << "NO" << std::endl;
    return;
  }
  std::array<bool, 4> flags = {};
  for (std::array<ipoint, 2>& interval : intervals) {
    if (interval[0].x == interval[1].x) {
      if (std::min(interval[0].y, interval[1].y) != minY) {
        out << "NO" << std::endl;
        return;
      }
      if (std::max(interval[0].y, interval[1].y) != maxY) {
        out << "NO" << std::endl;
        return;
      }
      if (interval[0].x == minX) flags[0] = true;
      if (interval[0].x == maxX) flags[1] = true;
    }
    if (interval[0].y == interval[1].y) {
      if (std::min(interval[0].x, interval[1].x) != minX) {
        out << "NO" << std::endl;
        return;
      }
      if (std::max(interval[0].x, interval[1].x) != maxX) {
        out << "NO" << std::endl;
        return;
      }
      if (interval[0].y == minY) flags[2] = true;
      if (interval[0].y == maxY) flags[3] = true;
    }
  }
  if (std::count(flags.begin(), flags.end(), true) == 4) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}