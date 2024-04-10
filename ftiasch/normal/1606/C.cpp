#include <bits/stdc++.h>

const int N = 10;

int a[N], denom[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    denom[0] = 1;
    for (int i = 1; i < n; ++i) {
      denom[i] = denom[i - 1];
      for (int j = a[i - 1]; j < a[i]; ++j) {
        denom[i] *= 10;
      }
    }
    long long result = 0;
    k++;
    for (int i = 0; i + 1 < n; ++i) {
      int max = denom[i + 1] / denom[i] - 1;
      int used = std::min(k, max);
      result += 1LL * denom[i] * used;
      k -= used;
    }
    result += 1ll * denom[n - 1] * k;
    printf("%lld\n", result);
  }
}