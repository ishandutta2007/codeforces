#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int d2 = x * x + y * y;
    int d = sqrt(d2);
    puts(d2 == 0 ? "0" : (d * d == x * x + y * y ? "1" : "2"));
  }
}