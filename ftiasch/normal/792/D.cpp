#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

Long to_heap(Long n, Long u, Long v = 1) {
  Long root = (n + 1) >> 1;
  if (u == root) {
    return v;
  }
  if (u < root) {
    return to_heap(n >> 1, u, v << 1);
  }
  return to_heap(n >> 1, u - root, v << 1 | 1);
}

Long from_heap(Long n, Long u) {
  int k = 0;
  while (u >> (k + 1)) {
    k++;
  }
  Long v = 0;
  while (k--) {
    Long root = (n + 1) >> 1;
    if (u >> k & 1) {
      v += ((n + 1) >> 1);
    }
    n >>= 1;
  }
  return v + ((n + 1) >> 1);
}

int main() {
  Long n;
  int q;
  scanf("%lld%d", &n, &q);
  static char s[100'001];
  while (q--) {
    Long u;
    scanf("%lld%s", &u, s);
    u = to_heap(n, u);
    for (int i = 0; s[i]; ++i) {
      if (s[i] == 'U') {
        if (u > 1) {
          u >>= 1;
        }
      } else if ((u << 1) <= n) {
        u = (u << 1) | (s[i] == 'R');
      }
    }
    printf("%lld\n", from_heap(n, u));
  }
}