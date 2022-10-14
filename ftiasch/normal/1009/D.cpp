#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool work(int n, int m) {
  if (m < n - 1) {
    return false;
  }
  std::vector<std::pair<int, int>> plan;
  for (int i = 1; i <= n && plan.size() < m; ++i) {
    for (int j = i + 1; j <= n && plan.size() < m; ++j) {
      if (std::__gcd(i, j) == 1) {
        plan.emplace_back(i, j);
      }
    }
  }
  if (plan.size() < m) {
    return false;
  }
  puts("Possible");
  for (auto [a, b] : plan) {
    printf("%d %d\n", a, b);
  }
  return true;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (!work(n, m)) {
    puts("Impossible");
  }
}