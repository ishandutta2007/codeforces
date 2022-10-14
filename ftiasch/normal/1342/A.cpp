#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    if (x < y) {
      std::swap(x, y);
    }
    printf("%lld\n", std::min(1LL * b * y + 1LL * a * (x - y), 1LL * a * (x + y)));
  }
}