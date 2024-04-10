// #include "debug.h"

#include <bits/stdc++.h>

const int D = 18;
const int N = 200'000;

int n, x[N + 1], pre[D][N];

int main() {
  int m;
  scanf("%d%d", &m, &n);
  for (int i = 0, a; i < m; ++i) {
    scanf("%d", &a);
    x[a - 1] ^= 1;
  }
//   std::cout << std::vector(x, x + (n + 1)) << std::endl;
  for (int i = n; i--;) {
    x[i] ^= x[i + 1];
  }
//   std::cout << std::vector(x, x + (n + 1)) << std::endl;
  for (int j = 1; j < D; ++j) {
    int len = 1 << j;
    int half = 1 << (j - 1);
    for (int i = 0; i + len <= n; ++i) {
      pre[j][i] = pre[j - 1][i] ^ pre[j - 1][i + half];
      if (x[i + half] ^ x[i + len]) {
        pre[j][i] ^= half;
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int result = 0;
    for (int j = D; j--;) {
      int len = 1 << j;
      if (l + len <= r) {
        result ^= pre[j][l];
        if (x[l + len] ^ x[r]) {
          result ^= len;
        }
        l += len;
      }
    }
    putchar("AB"[result == 0]);
  }
  puts("");
}