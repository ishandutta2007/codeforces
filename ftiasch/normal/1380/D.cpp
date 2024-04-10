#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  int n, m, x, k, y;
  scanf("%d%d%d%d%d", &n, &m, &x, &k, &y);
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  long long result = 0;
  int last = -1;
  for (int i = 0, j = 0; j <= m; ++j) {
    if (j == m) {
      i = n;
    } else {
      while (i < n && a[i] != b[j]) {
        i++;
      }
      if (i == n) {
        result = -1;
        break;
      }
    }
    if (last + 1 < i) {
      int m = *std::max_element(a.begin() + last + 1, a.begin() + i);
      bool all_removable = ~last && a[last] > m || i < n && a[i] > m;
      int count = i - last - 1;
      long long sub_result = 1e18;
      for (int removes = 0; removes <= count - !all_removable; ++removes) {
        if ((count - removes) % k == 0) {
          sub_result = std::min(sub_result, 1LL * (count - removes) / k * x +
                                                1LL * removes * y);
        }
      }
      if (sub_result < 1e18) {
        result += sub_result;
      } else {
        result = -1;
        break;
      }
    }
    last = i;
  }
  printf("%lld\n", result);
}