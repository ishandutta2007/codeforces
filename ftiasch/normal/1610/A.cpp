#include <bits/stdc++.h>

int solve(int n, int m) {
  if (n == 1 && m == 1) {
    return 0;
  }
  if (n == 1 || m == 1) {
    return 1;
  }
  return 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", solve(n, m));
  }
}