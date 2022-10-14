#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x;
    scanf("%d%d", &n, &x);
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = n; i--;) {
      a[i] += a[i + 1];
    }
    std::vector<int> max_sum(n + 1, INT_MIN);
    max_sum[0] = 0;
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i + len <= n; ++i) {
        max_sum[len] = std::max(max_sum[len], a[i] - a[i + len]);
      }
    }
    for (int i = n; i--;) {
      max_sum[i] = std::max(max_sum[i], max_sum[i + 1]);
    }
    int result = 0;
    for (int k = 0; k <= n; ++k) {
      result = std::max(result, max_sum[k] + x * k);
      printf("%d%c", result, " \n"[k == n]);
    }
  }
}