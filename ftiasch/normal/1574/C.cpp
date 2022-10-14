// #include "debug.h"

#include <bits/stdc++.h>

using Long = long long;

const int N = 200'000;

int n;
Long a[N], sum;

Long solve(Long x, Long y) {
  int i = std::lower_bound(a, a + n, x) - a;
  if (i == n) {
    return (x - a[n - 1]) + std::max(y - (sum - a[n - 1]), 0LL);
  }
//   std::cerr << KV(x) << " " << KV(y) << " " << KV(i) << std::endl;
  Long result = std::max(y - (sum - a[i]), 0LL);
  if (i > 0) {
    result =
        std::min(result, (x - a[i - 1]) + std::max(y - (sum - a[i - 1]), 0LL));
  }
  return result;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  std::sort(a, a + n);
  sum = std::accumulate(a, a + n, 0LL);
  int q;
  scanf("%d", &q);
  while (q--) {
    Long x, y;
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", solve(x, y));
  }
}