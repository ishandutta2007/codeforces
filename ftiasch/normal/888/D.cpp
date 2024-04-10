#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long result = 1;
  if (2 <= k) {
    result += 1LL * n * (n - 1) / 2;
  }
  if (3 <= k) {
    result += 1LL * n * (n - 1) / 2 * (n - 2) / 3 * 2;
  }
  if (4 <= k) {
    result += 1LL * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * 9;
  }
  printf("%lld\n", result);
}