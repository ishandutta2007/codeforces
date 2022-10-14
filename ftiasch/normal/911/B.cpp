#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  int x = std::min(a, b);
  while (a / x + b / x < n) {
    x--;
  }
  printf("%d\n", x);
}