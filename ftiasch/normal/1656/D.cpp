#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    long long pw2 = 1;
    while (n % (pw2 * 2) == 0) {
      pw2 *= 2;
    }
    auto solve = [&]() -> long long {
      if (pw2 == n) {
        return -1;
      }
      return std::min(pw2 * 2, n / pw2);
    };
    printf("%lld\n", solve());
  }
}