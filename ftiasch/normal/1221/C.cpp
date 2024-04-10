#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    // x
    // x <= a
    // x <= b
    // x <= (a - x) + (b - x) + c
    printf("%d\n", std::min({a, b, (a + b + c) / 3}));
  }
}