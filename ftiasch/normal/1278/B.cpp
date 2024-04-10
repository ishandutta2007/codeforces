#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  // 0
  // +1 -1
  // +3 +1 -1 -3
  // +6 +4 +2 0 -2 -4 -6
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int d = std::abs(a - b);
    int x = 0;
    while (1LL * x * (x + 1) / 2 < d || (1LL * x * (x + 1) / 2 - d) & 1) {
      x++;
    }
    printf("%d\n", x);
  }
}