#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    // a + x >= b + (n - x) + 1
    // 2x >= b + n - a + 1
    int min = 0;
    if (b + n - a + 1 >= 0) {
      min = (b + n - a + 2) >> 1;
    }
    printf("%d\n", std::max(n - min + 1, 0));
  }
}