#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

char s[N + 1];

void work() {
  int n = strlen(s);
  if (~n & 1) {
    int mask = 0;
    for (int i = 0; i < n; ++i) {
      mask ^= 1 << (s[i] - '0');
    }
    for (int i = n; i--;) {
      mask ^= 1 << (s[i] - '0');
      for (int j = s[i] - '0'; j--;) {
        if (i || j) {
          int nmask = mask ^ (1 << j);
          int count = __builtin_popcount(nmask);
          if (count <= n - i - 1) {
            s[i] = '\0';
            printf("%s%d", s, j);
            int nines = (n - i - 1) - count;
            for (int _ = 0; _ < nines; ++_) {
              putchar('9');
            }
            for (int i = 10; i--;) {
              if (nmask >> i & 1) {
                putchar('0' + i);
              }
            }
            puts("");
            return;
          }
        }
      }
    }
  }
  n = (n - 1) & ~1;
  for (int _ = 0; _ < n; ++_) {
    putchar('9');
  }
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    work();
  }
}