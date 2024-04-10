#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 50;

int a[N][N], b[N][N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  int count = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1] && a[i][j]) {
        count++;
        b[i - 1][j - 1] = b[i - 1][j] = b[i][j - 1] = b[i][j] = 1;
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ok &= a[i][j] == b[i][j];
    }
  }
  if (ok) {
    printf("%d\n", count);
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1] && a[i][j]) {
          printf("%d %d\n", i, j);
        }
      }
    }
  } else {
    puts("-1");
  }
}