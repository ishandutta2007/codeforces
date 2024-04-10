#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int x1, y1, x2, y2, a, b;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &a, &b);
  int dx = std::abs(x1 - x2);
  int dy = std::abs(y1 - y2);
  puts(dx % a == 0 && dy % b == 0 && ~(dx / a + dy / b) & 1 ? "YES" : "NO");
}