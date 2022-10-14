#include <bits/stdc++.h>

const int N = 100000;

int n, a[2][N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", a[i] + j);
      }
    }
    int result = INT_MAX;
    int sum0 = std::accumulate(a[0], a[0] + n, 0), sum1 = 0;
    for (int j = 0; j < n; ++j) {
      sum0 -= a[0][j];
      result = std::min(result, std::max(sum0, sum1));
      sum1 += a[1][j];
      // 0, j + 1..n - 1
      // 1, 0..j - 1
    }
    printf("%d\n", result);
  }
}