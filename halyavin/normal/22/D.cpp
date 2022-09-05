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
  int n;
  in >> n;
  std::vector<std::pair<int, int>> intervals(n);
  for (int i = 0; i < n; i++) {
    in >> intervals[i].first >> intervals[i].second;
    if (intervals[i].second < intervals[i].first) {
      std::swap(intervals[i].first, intervals[i].second);
    }
  }
  std::sort(intervals.begin(), intervals.end());
  std::vector<int> ans;
  int cur = intervals[0].second;
  for (int i = 1; i < n; i++) {
    if (intervals[i].first > cur) {
      ans.push_back(cur);
      cur = intervals[i].second;
    } else {
      cur = std::min(cur, intervals[i].second);
    }
  }
  ans.push_back(cur);
  out << ans.size() << std::endl;
  for (int i = 0; i < ans.size(); i++) {
    out << ans[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}