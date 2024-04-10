#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    long long x = sqrt(2LL * n);
    if (x * (x + 1) <= 2LL * n) {
      x++;
    }
    printf("%lld\n",
           n + std::max(static_cast<long long>(n), (x * x - x) / 2 + 2) - x -
               x);
  }
}