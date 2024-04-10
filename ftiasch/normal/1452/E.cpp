#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 2000;

using Pair = std::pair<int, int>;

bool by_mid(const Pair &a, const Pair &b) {
  return a.first + a.second < b.first + b.second;
}

int n, len, m, prefix[N + 1], count[N];
Pair a[N];

int main() {
  scanf("%d%d%d", &n, &m, &len);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    a[i].first--;
  }
  std::sort(a, a + m, by_mid);
  for (int i = 0; i < m; ++i) {
    auto [l, r] = a[i];
    for (int x = 0; x + len <= n; ++x) {
      count[x] += std::max(std::min(x + len, r) - std::max(x, l), 0);
    }
    // std::cout << std::vector<int>(count, count + n) << std::endl;
    prefix[i + 1] = *std::max_element(count, count + n);
  }

  int result = 0;
  memset(count, 0, sizeof(count));
  for (int i = m; i >= 0; --i) {
    auto [l, r] = a[i];
    if (i < m) {
      for (int x = 0; x + len <= n; ++x) {
        count[x] += std::max(std::min(x + len, r) - std::max(x, l), 0);
      }
    }
    result = std::max(result, prefix[i] + *std::max_element(count, count + n));
  }
  printf("%d\n", result);
}