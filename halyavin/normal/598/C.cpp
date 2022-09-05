#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

std::pair<int, int> ff(int n, std::vector<std::pair<int, int>>& p) {
  std::vector<std::pair<long double, int>> points;
  for (int i = 0; i < n; i++) {
    points.emplace_back(atan2l(p[i].second, p[i].first), i + 1);
  }
  std::sort(points.begin(), points.end());
  long double min = 100;
  int imin = -1;
  int jmin = -1;
  for (size_t i = 0; i + 1 < points.size(); i++) {
    if (points[i + 1].first - points[i].first < min) {
      min = points[i + 1].first - points[i].first;
      imin = points[i].second;
      jmin = points[i + 1].second;
    }
  }
  long double last = points[0].first - points[n - 1].first
      + 2 * 3.14159265358979323;
  if (last < min) {
    imin = points[0].second;
    jmin = points[n - 1].second;
  }
  return {imin, jmin};
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::pair<int, int>> points;
  for (int i = 0; i < n; i++) {
    int x, y;
    in >> x >> y;
    points.emplace_back(x, y);
  }
  std::pair<int, int> result = ff(n, points);
  out << result.first << " " << result.second << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}