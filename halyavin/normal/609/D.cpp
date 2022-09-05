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

void update(std::vector<std::pair<int, int>>& cost) {
  for (size_t i = 1; i < cost.size(); i++) {
    if (cost[i].first < cost[i - 1].first) {
      continue;
    } else {
      cost[i] = cost[i - 1];
    }
  }
}

void run(std::istream &in, std::ostream &out) {
  int n, m, k, s;
  in >> n >> m >> k >> s;
  std::vector<std::pair<int, int>> cost1(n);
  std::vector<std::pair<int, int>> cost2(n);
  for (int i = 0; i < n; i++) {
    in >> cost1[i].first;
    cost1[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    in >> cost2[i].first;
    cost2[i].second = i;
  }
  update(cost1);
  update(cost2);
  std::vector<std::pair<int, int>> gadgets(m);
  for (int i = 0; i < m; i++) {
    in >> gadgets[i].first >> gadgets[i].second;
  }
  cost1.emplace_back(0, n);
  cost2.emplace_back(0, n);
  int left = -1;
  int right = n;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    std::vector<std::pair<int64_t, int>> gadgetCosts(m);
    for (int i = 0; i < m; i++) {
      if (gadgets[i].first == 1) {
        gadgetCosts[i].first = int64_t(cost1[middle].first) * gadgets[i].second;
      } else {
        gadgetCosts[i].first = int64_t(cost2[middle].first) * gadgets[i].second;
      }
      gadgetCosts[i].second = i;
    }
    std::partial_sort(gadgetCosts.begin(), gadgetCosts.begin() + k, gadgetCosts.end());
    int64_t sum = 0;
    for (int i = 0; i < k ; i++) {
      sum += gadgetCosts[i].first;
    }
    if (sum <= s) {
      right = middle;
    } else {
      left = middle;
    }
  }
  if (right == n) {
    out << "-1" << std::endl;
    return;
  }
  out << (right + 1) << std::endl;
  std::vector<std::pair<int64_t, int>> gadgetCosts(m);
  for (int i = 0; i < m; i++) {
    if (gadgets[i].first == 1) {
      gadgetCosts[i].first = int64_t(cost1[right].first) * gadgets[i].second;
    } else {
      gadgetCosts[i].first = int64_t(cost2[right].first) * gadgets[i].second;
    }
    gadgetCosts[i].second = i;
  }
  std::partial_sort(gadgetCosts.begin(), gadgetCosts.begin() + k, gadgetCosts.end());
  for (int i = 0; i < k; i++) {
    int idx = gadgetCosts[i].second;
    out << (idx + 1) << " ";
    if (gadgets[idx].first == 1) {
      out << (cost1[right].second + 1) << "\n";
    } else {
      out << (cost2[right].second + 1) << "\n";
    }
  }
  out.flush();
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}