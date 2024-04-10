#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  printf("%d\n", std::max(std::abs(x1 - x2), std::abs(y1 - y2)));
}