#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    printf("%d\n", [&]() -> int {
      if (d < l || r < d) {
        return d;
      }
      return (r / d + 1) * d;
    }());
  }
}