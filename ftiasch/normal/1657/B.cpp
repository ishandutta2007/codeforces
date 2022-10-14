#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, b, x, y;
    scanf("%d%d%d%d", &n, &b, &x, &y);
    int a = 0;
    long long result = 0;
    for (int i = 1; i <= n; ++i) {
      if (a + x <= b) {
        a += x;
      } else {
        a -= y;
      }
      result += a;
    }
    printf("%lld\n", result);
  }
}