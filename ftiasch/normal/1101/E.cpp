#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int q;
  scanf("%d", &q);
  int max_x = 0, max_y = 0;
  while (q--) {
    char op[2];
    int x, y;
    scanf("%s%d%d", op, &x, &y);
    if (x > y) {
      std::swap(x, y);
    }
    if (*op == '+') {
      max_x = std::max(max_x, x);
      max_y = std::max(max_y, y);
    } else {
      puts(max_x <= x && max_y <= y ? "YES" : "NO");
    }
  }
}