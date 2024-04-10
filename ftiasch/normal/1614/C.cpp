#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int o = 0;
    for (int i = 0, c; i < m; ++i) {
      scanf("%*d%*d%d", &c);
      o |= c;
    }
    int two = 1;
    for (int i = 0; i < n - 1; ++i) {
      two += two;
      if (two >= MOD) {
        two -= MOD;
      }
    }
    int result = 0;
    for (int j = 0; j < 30; ++j) {
      if (o >> j & 1) {
        result += (static_cast<long long>(two) << j) % MOD;
        if (result >= MOD) {
          result -= MOD;
        }
      }
    }
    printf("%d\n", result);
  }
}