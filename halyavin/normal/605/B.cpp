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
  int n, m;
  in >> n >> m;
  std::vector<std::pair<int, int>> as;
  std::vector<std::pair<int, int>> bs;
  for (int i= 0; i < m; i++) {
    int a, b;
    in >> a >> b;
    if (b == 0) {
      bs.emplace_back(a, i);
    } else {
      as.emplace_back(a, i);
    }
  }
  std::sort(as.begin(), as.end());
  std::sort(bs.begin(), bs.end());
  std::vector<std::pair<int, int>> ans(m);
  for (size_t i = 0; i < as.size(); i++) {
    ans[as[i].second].first = 0;
    ans[as[i].second].second = i + 1;
  }
  int aIndex = 0;
  int bIndex = 1;
  for (size_t i = 0; i < bs.size(); i++) {
    if (bs[i].first < as[bIndex].first) {
      out << "-1" << std::endl;
      return;
    }
    ans[bs[i].second].first = aIndex + 1;
    ans[bs[i].second].second = bIndex + 1;
    aIndex++;
    if (bIndex == aIndex) {
      bIndex++;
      aIndex = 0;
    }
  }
  for (size_t i = 0; i < ans.size(); i++) {
    out << (ans[i].first + 1) << " " << (ans[i].second + 1) << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}