#line 1 "sol.cpp"
#include <bits/stdc++.h>

std::pair<int, int> solve(int x) {
  if (x == 0) {
    return {1, 1};
  }
  int n = 1;
  while (true) {
    if (1LL * n * n - 1LL * (n / 2) * (n / 2) > x) {
      break;
    }
    if (1LL * n * n > x) {
      // (n / m)^2 == n^2 - x
      int r = sqrtl(1LL * n * n - x);
      if (1LL * r * r == 1LL * n * n - x) {
        // r <= n / m < r + 1
        int m = n / r;
        if (m > 0 && n / m == r) {
          return {n, m};
        }
      }
    }
    n++;
  }
  return {-1, -1};
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    auto [n, m] = solve(x);
    if (~n) {
      printf("%d %d\n", n, m);
    } else {
      puts("-1");
    }
  }
}