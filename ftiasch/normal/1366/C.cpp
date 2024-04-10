#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 30;

int a[N][N], cnt[N + N][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i] + j);
      }
    }
    memset(cnt, 0, sizeof(cnt));
    // 0, (n + m - 2)
    int s = n + m - 2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int d = i + j;
        if (d != s - d) {
          d = std::min(d, s - d);
          cnt[d][a[i][j]]++;
        }
      }
    }
    int result = 0;
    for (int i = 0; i <= s; ++i) {
      result += std::min(cnt[i][0], cnt[i][1]);
    }
    printf("%d\n", result);
  }
}