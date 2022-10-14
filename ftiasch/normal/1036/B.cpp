#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x, y, k;
    scanf("%lld%lld%lld", &x, &y, &k);
    printf("%lld\n", [&]() -> long long {
      long long min_st = std::max(x, y);
      if (k < min_st) {
        return -1;
      }
      if ((x + y) & 1) {
        return k - 1;
      } else {
        return ((k - min_st) & 1) ? k - 2 : k;
      }
    }());
  }
}