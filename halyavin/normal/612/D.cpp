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

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<std::pair<int, int>> points;
  for (int i = 0; i < n; i++) {
    int left, right;
    in >> left >> right;
    points.emplace_back(left, 1);
    points.emplace_back(right + 1, 0);
  }
  std::sort(points.begin(), points.end());
  std::vector<std::pair<int, int>> answer;
  int cur = 0;
  int prev = -2000000000;
  bool hasPrev = false;
  for (size_t i = 0; i < points.size(); i++) {
    if (points[i].second) {
      cur++;
    } else {
      cur--;
    }
    if (i + 1 == points.size() || points[i + 1] != points[i]) {
      if (cur >= k && !hasPrev) {
        hasPrev = true;
        prev = points[i].first;
      }
      if (cur < k && hasPrev) {
        answer.emplace_back(prev, points[i].first - 1);
        hasPrev = false;
      }
    }
  }
  out << answer.size() << std::endl;
  for (size_t i = 0; i < answer.size(); i++) {
    out << answer[i].first << "  " << answer[i].second << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}