#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x, y, d;
    scanf("%d%d%d%d", &n, &x, &y, &d);
    printf("%d\n", [&]() -> int {
      if (std::abs(x - y) % d == 0) {
        return std::abs(x - y) / d;
      }
      int result = INT_MAX;
      if ((y - 1) % d == 0) {
        result = std::min(result, (x - 1 + d - 1) / d + (y - 1) / d);
      }
      if ((n - y) % d == 0) {
        result = std::min(result, (n - x + d - 1) / d + (n - y) / d);
      }
      return result < INT_MAX ? result : -1;
    }());
  }
}