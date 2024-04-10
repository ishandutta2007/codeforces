#include <bits/stdc++.h>

const int N = 1'000;

int n, a[N][5];

bool check() {
  int count[5];
  memset(count, 0, sizeof(count));
  for (int j = 0; j < 5; ++j) {
    for (int i = 0; i < n; ++i) {
      count[j] += a[i][j];
    }
    for (int k = 0; k < j; ++k) {
      int uni = 0;
      for (int i = 0; i < n; ++i) {
        uni += a[i][k] || a[i][j];
      }
      if (count[j] >= n / 2 && count[k] >= n / 2 && uni == n) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        scanf("%d", a[i] + j);
      }
    }
    puts(check() ? "YES" : "NO");
  }
}