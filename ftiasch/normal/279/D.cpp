#include <bits/stdc++.h>

const int N = 23;

int n, a[N];
int8_t dp[1 << N];

int8_t go(int i, int msk)
{
  auto& ref = dp[msk];
  if (ref == -1) {
    ref = n + 1;
    if (i) {
      for (int j = 0; j < i; ++ j) {
        for (int k = j; k < i; ++ k) {
          if (a[j] + a[k] == a[i]) {
            ref = std::min(ref, go(i - 1, msk ^ 1 << i | 1 << i - 1 | 1 << j | 1 << k));
          }
        }
      }
      ref = std::max(ref, static_cast<int8_t>(__builtin_popcount(msk)));
    } else {
      ref = 1;
    }
  }
  return ref;
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    memset(dp, -1, sizeof(*dp) << n);
    int result = go(n - 1, 1 << n - 1);
    printf("%d\n", result <= n ? result : -1);
  }
}