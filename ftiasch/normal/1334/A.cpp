#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    bool ok = true;
    int n, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i) {
      scanf("%d%d", &a, &b);
      ok &= a >= x && b >= y && (a - x) >= (b - y);
      x = a;
      y = b;
    }
    puts(ok ? "YES" : "NO");
  }
}