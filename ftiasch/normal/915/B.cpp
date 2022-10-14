#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, p, l, r;
  scanf("%d%d%d%d", &n, &p, &l, &r);
  auto solve = [&]() -> int {
    if (l == 1 && r == n) {
      return 0;
    }
    if (l == 1) {
      return std::abs(p - r) + 1;
    }
    if (r == n) {
      return std::abs(p - l) + 1;
    }
    return std::min(std::abs(p - l), std::abs(p - r)) + std::abs(l - r) + 2;
  };
  printf("%d\n", solve());
}