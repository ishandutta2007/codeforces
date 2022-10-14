#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool check(int x, int y) {
  if (x == 1) {
    return y == 1;
  }
  if (x <= 3) {
    return y <= 3;
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y;
    scanf("%d%d", &x, &y);
    puts(check(x, y) ? "YES" : "NO");
  }
}