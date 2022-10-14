#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool check(int a, int b) {
  // x + 2 * y = a
  // 2 * x + y = b
  // x + y = (a + b) / 3
  if ((a + b) % 3 != 0) {
      return false;
  }
  int s = (a + b) / 3;
  return s <= a && s <= b;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    puts(check(a, b) ? "YES" : "NO");
  }
}