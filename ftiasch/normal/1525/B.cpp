#include <bits/stdc++.h>

int n, a[51];

int solve() {
  bool already_sorted = true;
  for (int i = 1; i <= n; ++i) {
    already_sorted &= a[i] == i;
  }
  if (already_sorted) {
    return 0;
  }
  if (a[1] == 1 || a[n] == n) {
    return 1;
  }
  return (a[1] == n && a[n] == 1) ? 3 : 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    printf("%d\n", solve());
  }
}