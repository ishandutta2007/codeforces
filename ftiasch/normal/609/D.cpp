#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, k, s;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  std::vector<int> t(m), c(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &t[i], &c[i]);
  }
  int min_a, min_b;
  std::vector<std::pair<long long, int>> cost(m);
  auto check = [&](int n) -> bool {
    min_a = std::min_element(a.begin(), a.begin() + n) - a.begin();
    min_b = std::min_element(b.begin(), b.begin() + n) - b.begin();
    for (int i = 0; i < m; ++i) {
      cost[i] = {1LL * (t[i] == 1 ? a[min_a] : b[min_b]) * c[i], i};
    }
    std::sort(cost.begin(), cost.end());
    long long total = 0;
    for (int i = 0; i < k; ++i) {
      total += cost[i].first;
    }
    return total <= s;
  };
  int low = 1;
  int high = n + 1;
  while (low < high) {
    int middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  if (high <= n) {
    printf("%d\n", high);
    check(high);
    for (int i = 0; i < k; ++i) {
      int j = cost[i].second;
      printf("%d %d\n", j + 1, t[j] == 1 ? min_a + 1 : min_b + 1);
    }
  } else {
    puts("-1");
  }
}