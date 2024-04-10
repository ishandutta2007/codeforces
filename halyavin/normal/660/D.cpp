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
#include <map>

void run(std::istream &in, std::ostream &out) {
  std::map<std::pair<int, int>, int> stat;
  int n;
  in >> n;
  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    in >> points[i].first >> points[i].second;
  }
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      std::pair<int, int> diff = {points[j].first - points[i].first, points[j].second - points[i].second};
      if (diff.first < 0 || (diff.first == 0 && diff.second < 0)) {
        diff.first = -diff.first;
        diff.second = -diff.second;
      }
      int& res = stat[diff];
      ans += res;
      res++;
    }
  }
  out << ans / 2 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}