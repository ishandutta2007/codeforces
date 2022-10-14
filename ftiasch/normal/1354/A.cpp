#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%lld\n", [&]() -> long long {
      if (a <= b) {
        return b;
      }
      a -= b;
      if (d >= c) {
        return -1;
      }
      int s = c - d;
      return b + (a + s - 1LL) / s * c;
    }());
  }
}