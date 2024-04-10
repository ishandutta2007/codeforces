#include <bits/stdc++.h>

const int N = 501;

int n, m, a[N][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    static char buffer[N];
    scanf("%s", buffer);
    for (int j = 0; j < m; ++j) {
      a[i][j] = buffer[j] == 'B';
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] ^= a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1];
      sum += a[i][j];
    }
  }
  int result = sum;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i - 1][j - 1] && a[i - 1][m - 1] && a[n - 1][j - 1] &&
          a[n - 1][m - 1]) {
        result = sum - 1;
      }
    }
  }
  printf("%d\n", result);
}