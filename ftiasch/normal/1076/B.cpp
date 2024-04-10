#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", [&]() -> long long {
    if (~n & 1) {
      return n >> 1;
    }
    long long p = 2;
    while (p * p <= n && n % p != 0) {
      p++;
    }
    if (n % p != 0) {
        return 1;
    }
    return 1 + ((n - p) >> 1);
  }());
}