#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, s;
    scanf("%d%d", &n, &s);
    int x = s / n;
    // (x + 1)^2 - x^2 = 2x + 1
    printf("%lld\n", 1LL * x * x * n + (2 * x + 1LL) * (s % n));
  }
}