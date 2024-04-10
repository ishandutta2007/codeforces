#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l * 2 <= r) {
      printf("%d %d\n", l, 2 * l);
    } else {
      puts("-1 -1");
    }
  }
}