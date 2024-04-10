#include <bits/stdc++.h>

const int N = 200'000;
const int MOD = 998244353;

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int n, a[N], fact[N + 1];

int main() {
  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::sort(a, a + n, std::greater<int>());
    int m = a[0];
    int mcount = 0;
    while (mcount < n && a[mcount] == m) {
      mcount++;
    }
    if (mcount >= 2) {
      printf("%d\n", fact[n]);
    } else {
      // mcount = 1
      int m2count = 0;
      while (mcount + m2count < n && a[mcount + m2count] == m - 1) {
        m2count++;
      }
      if (m2count == 0) {
        puts("0");
      } else {
        printf("%d\n", static_cast<int>(1LL * fact[n] *
                                        (1 + MOD - inv(mcount + m2count)) %
                                        MOD)) /*  */;
      }
    }
  }
}