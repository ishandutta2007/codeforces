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

void run(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  for (int i = 0; i < t; i++) {
    int n;
    in >> n;
    std::vector<std::pair<int, int>> as(2 * n - 1);
    int64_t sumA = 0;
    int64_t sumO = 0;
    for (size_t j = 0; j < as.size(); j++) {
      in >> as[j].first >> as[j].second;
      sumA += as[j].first;
      sumO += as[j].second;
    }
    std::vector<int> ind(2 * n - 1);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&as](int left, int right) { return as[left].first > as[right].first; });
    int64_t sumO1 = 0;
    int64_t sumO2 = 0;
    for (int i = 1; i < n; i++) {
      sumO1 += as[ind[2 * i]].second;
      sumO2 += as[ind[2 * i - 1]].second;
    }
    sumO1 += as[ind[0]].second;
    sumO2 += as[ind[0]].second;
    int offset = 0;
    if (sumO2 * 2 >= sumO) {
      offset = -1;
    }
    out << "YES" << std::endl;
    out << ind[0] + 1 << " ";
    for (int i = 1; i < n; i++) {
      out << ind[2 * i + offset] + 1 << " ";
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}