// #include "debug.h"

#include <bits/stdc++.h>

const int N = 1 << 20;
const int MOD = 998'244'353;

int ban[N];
char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    int l = 0;
    while (l < k && (1 << l) <= n) {
      l++;
    }
    int zeros = 0, suffix = 0;
    for (int i = 0; i < n; ++i) {
      int c = (s[i] - '0') ^ 1;
      suffix = suffix << 1 | c;
      if (i >= l) {
        int lc = suffix >> l;
        suffix &= ((1 << l) - 1);
        zeros = lc ? 0 : zeros + 1;
      }
      if (i >= k - 1 && zeros >= k - l) {
        ban[suffix] = t;
      }
    }
    int result = 0;
    while (result < (1 << l) && ban[result] == t) {
      result++;
    }
    if (result < (1 << l)) {
      puts("YES");
      for (int i = 0; i < k - l; ++i) {
        putchar('0');
      }
      for (int i = l; i--;) {
        putchar('0' + (result >> i & 1));
      }
      puts("");
    } else {
      puts("NO");
    }
  }
}