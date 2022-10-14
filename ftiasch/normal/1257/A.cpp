#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x, a, b;
    scanf("%d%d%d%d", &n, &x, &a, &b);
    printf("%d\n", std::min(std::abs(a - b) + x, n - 1));
  }
}