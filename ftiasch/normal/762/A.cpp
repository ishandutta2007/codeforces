#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  long long n;
  int k;
  scanf("%lld%d", &n, &k);
  auto find = [&]() -> long long {
    long long d = 1;
    while (d * d <= n) {
      if (n % d == 0) {
        if (!(--k)) {
          return d;
        }
      }
      d++;
    }
    while (d >= 1) {
      if (n % d == 0 && d < n / d) {
        if (!(--k)) {
          return n / d;
        }
      }
      d --;
    }
    return -1;
  };
  printf("%lld\n", find());
}