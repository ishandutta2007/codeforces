#line 1 "sol.cpp"
#include <bits/stdc++.h>

int x, y;

long long solve(int n) {
  long long result = 1LL * x * std::abs(n);
  if (std::abs(n) > 1) {
    if (n % 2 == 0) {
      result = std::min(result, solve(n / 2) + y);
    } else {
      result = std::min(result, solve((n + 1) / 2) + x + y);
      result = std::min(result, solve((n - 1) / 2) + x + y);
    }
  }
  return result;
}

int main() {
  int n;
  scanf("%d%d%d", &n, &x, &y);
  printf("%lld\n", solve(n));
}