#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, lim;
  scanf("%d%d", &n, &lim);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  auto solve = [&]() -> int {
    std::vector<int> maxsuf(n);
    maxsuf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      maxsuf[i] = a[i] + std::max(0, maxsuf[i + 1]);
    }
    int cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      cur += a[i];
      if (cur > lim) {
        return -1;
      }
      if (a[i] == 0 && cur < 0) {
        // x <= lim - maxsuf[i]
        res++;
        cur = lim - maxsuf[i];
        if (cur < 0) {
          return -1;
        }
      }
    }
    return res;
  };
  printf("%d\n", solve());
}