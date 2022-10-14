#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, l, r, m;
    scanf("%d%d%d", &n, &l, &m);
    r = l;
    while (m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (std::max(l, a) <= std::min(r, b)) {
        l = std::min(l, a);
        r = std::max(r, b);
      }
    }
    printf("%d\n", r - l + 1);
  }
}