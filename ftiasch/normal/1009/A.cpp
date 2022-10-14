#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;

int n, m, a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }
  int result = 0;
  for (int j = 0, i = 0; j < m; ++j) {
    while (i < n && a[i] > b[j]) {
      i++;
    }
    if (i < n) {
      i++;
      result++;
    }
  }
  printf("%d\n", result);
}