#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 2 * n; ++i) {
    if (n * 2 + i <= m) {
      printf("%d ", n * 2 + i);
    }
    if (i <= m) {
      printf("%d ", i);
    }
  }
}