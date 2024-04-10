#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    auto cost = [&](int i, int j) { return std::abs(a[i] - b[j]); };
    std::vector<std::pair<int, int>> edges;
    // 0..1
    // 2..3
    edges.emplace_back(cost(0, 0), 1 << 0 | 1 << 2);
    edges.emplace_back(cost(0, n - 1), 1 << 0 | 1 << 3);
    edges.emplace_back(cost(n - 1, 0), 1 << 1 | 1 << 2);
    edges.emplace_back(cost(n - 1, n - 1), 1 << 1 | 1 << 3);
    for (int x = 0; x < 2; ++x) {
      int i = x ? n - 1 : 0;
      int min_cost = INT_MAX;
      for (int j = 0; j < n; ++j) {
        min_cost = std::min(min_cost, cost(i, j));
      }
      edges.emplace_back(min_cost, 1 << x);
    }
    for (int y = 0; y < 2; ++y) {
      int j = y ? n - 1 : 0;
      int min_cost = INT_MAX;
      for (int i = 0; i < n; ++i) {
        min_cost = std::min(min_cost, cost(i, j));
      }
      edges.emplace_back(min_cost, 1 << (2 + y));
    }
    long long result = std::numeric_limits<long long>::max();
    for (int mask = 0; mask < 1 << 8; ++mask) {
      int u = 0;
      long long sum = 0;
      for (int i = 0; i < 8; ++i) {
        if (mask >> i & 1) {
          sum += edges[i].first;
          u |= edges[i].second;
        }
      }
      if (u == 15) {
        result = std::min(result, sum);
      }
    }
    printf("%lld\n", result);
  }
}