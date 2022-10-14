#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;
const int D = 30;

int n, s[N + 1], basis[D];

int main() {
  scanf("%d", &n);
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    s[i] = s[i - 1] ^ a;
  }
  if (s[n] == 0) {
    puts("-1");
  } else {
    int rank = 0;
    memset(basis, -1, sizeof(basis));
    for (int i = n; i >= 1; --i) {
      int x = s[i];
      for (int j = 0; j < D; ++j) {
        if (~basis[j] && x >> j & 1) {
          x ^= basis[j];
        }
      }
      if (x) {
        int j = 0;
        while (~x >> j & 1) {
          j++;
        }
        rank++;
        for (int k = 0; k < D; ++k) {
          if (~basis[k] && basis[k] >> j & 1) {
            basis[k] ^= x;
          }
        }
        basis[j] = x;
      }
    }
    printf("%d\n", rank);
  }
}