#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <math.h>

struct point {
  int x, y;
};

int n, m;
std::vector<point> points;

inline bool isRed(int index) {
  return index < n;
}
std::vector<std::vector<int>> sortAngles;
std::vector<std::vector<int>> invSortAngles;

bool compPoints(const point& origin, const point& p1, const point& p2) {
  point dp1 {p1.x - origin.x, p1.y - origin.y};
  point dp2 {p2.x - origin.x, p2.y - origin.y};
  int part1 = dp1.y < 0 || (dp1.y == 0 && dp1.x < 0);
  int part2 = dp2.y < 0 || (dp2.y == 0 && dp2.x < 0);
  if (part1 != part2) {
    return part1 < part2;
  }
  return int64_t(dp1.x) * int64_t(dp2.y) > int64_t(dp1.y) * int64_t(dp2.x);
}

bool checkOrient(const point& origin, const point& p1, const point& p2) {
  point dp1 {p1.x - origin.x, p1.y - origin.y};
  point dp2 {p2.x - origin.x, p2.y - origin.y};
  return int64_t(dp1.x) * int64_t(dp2.y) > int64_t(dp1.y) * int64_t(dp2.x);
}

bool checkIndex(size_t ind1, size_t ind2, size_t ind3) {
  if (ind1 < ind3) {
    return ind1 < ind2 && ind2 < ind3;
  } else {
    return ind2 < ind3 || ind2 > ind1;
  }
}

void run(std::istream &in, std::ostream &out) {
  in >> n >> m;
  points.resize(n + m);
  for (int i = 0; i < n + m; i++) {
    in >> points[i].x >> points[i].y;
  }
  sortAngles.resize(n);
  invSortAngles.resize(n);
  for (int i = 0; i < n; i++) {
    sortAngles[i].reserve(n + m);
    for (int j = 0; j < n + m; j++) {
      if (j != i) {
        sortAngles[i].push_back(j);
      }
    }
    auto& origin = points[i];
    auto comp = [&](int i1, int i2) {
      return compPoints(origin, points[i1], points[i2]);
    };
    std::sort(sortAngles[i].begin(), sortAngles[i].end(), comp);
    invSortAngles[i].resize(n + m);
    for (size_t j = 0; j < sortAngles[i].size(); j++) {
      invSortAngles[i][sortAngles[i][j]] = j;
    }
  }
  int answer = 0;
  for (int i1 = 0; i1 < n; i1++) {
    const auto& i1Angles = sortAngles[i1];
    for (size_t pos = 0; pos < i1Angles.size(); pos++) {
      int i2 = i1Angles[pos];
      if (!isRed(i2)) {
        continue;
      }
      //point* maxDiff = nullptr;
      size_t maxDiffIndex = 0;
      bool hasBlueDot = false;
      size_t nextPos = pos;
      size_t left = 0, right = i1Angles.size();
      while (right - left > 1) {
        size_t middle = (left + right) / 2;
        size_t index = (pos + middle) % i1Angles.size();
        if (!checkOrient(points[i1], points[i2], points[i1Angles[index]])) {
          right = middle;
        } else {
          left = middle;
        }
      }
      size_t exitIndex = (pos + right) % i1Angles.size();
      while (true) {
        nextPos++;
        if (nextPos == i1Angles.size()) {
          nextPos = 0;
        }
        if (nextPos == exitIndex) {
          break;
        }
        int i3 = i1Angles[nextPos];
        if (!hasBlueDot || checkIndex(maxDiffIndex, invSortAngles[i2][i3], invSortAngles[i2][i1])) { //checkOrient(points[i2], *maxDiff, points[i3])) {
          if (isRed(i3)) {
            answer++;
          } else {
            maxDiffIndex = invSortAngles[i2][i3];
            hasBlueDot = true;
          }
        }
      }
    }
  }
  out << answer / 3 << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}