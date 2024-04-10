#include <bits/stdc++.h>

const int N = 100'000;

int c[N], a[N], b[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
    }
    long long result = 0, pre = 0;
    for (int i = n; i-- > 1;) {
      long long add = 0;
      if (i + 1 < n && a[i + 1] != b[i + 1]) {
        add = std::max(pre - 2 * std::abs(a[i + 1] - b[i + 1]), 0LL);
      }
      long long cur = add + std::abs(a[i] - b[i]) + 2 + c[i] - 1;
      result = std::max(result, cur);
      pre = cur;
      //   printf("%d %lld\n", i, cur);
    }
    printf("%lld\n", result);
  }
}