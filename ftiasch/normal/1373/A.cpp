#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d\n", a < c ? 1 : -1, 1LL * a * b > c ? b : -1);
  }
}