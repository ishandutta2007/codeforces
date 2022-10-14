#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, m, sum[N];
std::vector<int> buckets[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, s, r; i < n; ++i) {
    scanf("%d%d", &s, &r);
    buckets[s - 1].push_back(r);
  }
  std::vector<std::pair<int, int>> order(m);
  for (int i = 0; i < m; ++i) {
    order[i] = {buckets[i].size(), i};
    std::sort(buckets[i].begin(), buckets[i].end(), std::greater<int>());
  }
  std::sort(order.begin(), order.end(), std::greater<std::pair<int, int>>());
  int result = 0;
  for (int x = 1; x <= n; ++x) {
    int subtotal = 0;
    for (auto [size, i] : order) {
      if (size < x) {
        break;
      }
      sum[i] += buckets[i][x - 1];
      subtotal += std::max(sum[i], 0);
    }
    result = std::max(result, subtotal);
  }
  printf("%d\n", result);
}