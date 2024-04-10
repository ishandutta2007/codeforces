#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

int main() {
  Long x, y;
  scanf("%lld%lld", &x, &y);
  Long result = 0;
  while (y) {
    Long b = std::__gcd(x, y);
    x /= b;
    y /= b;
    Long delta = y;
    for (Long d = 1; d * d <= x; ++d) {
      if (x % d == 0) {
        if (d > 1) {
          delta = std::min(delta, y % d);
        }
        if (d < x) {
          delta = std::min(delta, y % (x / d));
        }
      }
    }
    result += delta;
    y -= delta;
  }
  printf("%lld\n", result);
}