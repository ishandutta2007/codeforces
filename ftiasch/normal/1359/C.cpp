#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int h, c, t;
    scanf("%d%d%d", &h, &c, &t);
    h -= c;
    t -= c;
    if (2 * t <= h) {
      puts("2");
    } else {
      // (k+1)/(2k+1)*h >= t
      // (2k+2)/(2k+1)*h >= 2t
      // (1 + 1/(2k+1)) >= 2t/h
      // 1/(2k+1) >=(2t-h)/h
      // 2k+1 <= h/(2t-h)
      int k = (h / (2 * t - h) - 1) / 2 + 1;
      // 2k+1: (h*(k+1))/(2k+1)
      // 2k-1: (h*k)/(2k-1)-t <= t-(h*(k+1))/(2k+1)
      if (1LL * h * k * (2 * k + 1) + h * (k + 1LL) * (2 * k - 1) <=
          2LL * t * (2 * k + 1LL) * (2 * k - 1LL)) {
        printf("%d\n", 2 * k - 1);
      } else {
        printf("%d\n", 2 * k + 1);
      }
    }
  }
}