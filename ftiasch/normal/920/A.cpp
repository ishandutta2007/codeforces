#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> x(m);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &x[i]);
    }
    int result = std::max(x[0], n - x[m - 1] + 1);
    for (int i = 1; i < m; ++i) {
      // 1 1
      // 2 2
      // 3 2
      // 4 3
      result = std::max(result, ((x[i] - x[i - 1]) >> 1) + 1);
    }
    printf("%d\n", result);
  }
}