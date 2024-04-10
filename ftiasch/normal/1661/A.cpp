#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::array<int, 2>> a(n);
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i][j]);
      }
    }
    long long result = 0;
    for (int i = 1; i < n; ++i) {
      std::array<int, 2> cost{};
      for (int d = 0; d < 2; ++d) {
        cost[d] = std::abs(a[i][0] - a[i - 1][d]) +
                  std::abs(a[i][1] - a[i - 1][d ^ 1]);
      }
      result += std::min(cost[0], cost[1]);
    }
    printf("%lld\n", result);
  }
}