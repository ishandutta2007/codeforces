#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    long long needs = k + 1LL * y * k;
    x--;
    printf("%lld\n", ((needs - 1) + x - 1) / x + k);
  }
}