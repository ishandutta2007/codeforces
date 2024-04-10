#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), order(n), loc(n);
    std::iota(order.begin(), order.end(), 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(order.begin(), order.end(),
              [&](int i, int j) { return a[i] > a[j]; });
    long long cost = 0;
    for (int _ = 0; _ < n; ++_) {
      int i = order[_];
      loc[i] = (_ >> 1) + 1;
      if (_ & 1) {
        loc[i] *= -1;
      }
      cost += 2LL * a[i] * std::abs(loc[i]);
    }
    printf("%lld\n0", cost);
    for (int i = 0; i < n; ++i) {
      printf(" %d", loc[i]);
    }
    puts("");
  }
}