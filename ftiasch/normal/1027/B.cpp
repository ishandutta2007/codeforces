#line 1 "sol.cpp"
#include <bits/stdc++.h>

long long solve(int n, int x, int y) {
  long long offset = 0;
  if (~(x + y) & 1) {
    offset += 1LL * (x >> 1) * n;
    if (x & 1) {
      offset += 1LL * ((n + 1) >> 1);
    }
    return offset + (y >> 1);
  } else {
    offset += (1LL * n * n + 1) >> 1;
    offset += 1LL * (x >> 1) * n;
    if (x & 1) {
      offset += n >> 1;
    }
    return offset + (y >> 1);
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%lld\n", solve(n, x - 1, y - 1) + 1);
  }
}