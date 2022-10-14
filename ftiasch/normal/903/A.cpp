#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
      int n;
      scanf("%d", &n);
      bool ok = false;
      for (int b = 0; b < 3 && 7 * b <= n; ++ b) {
          ok |= (n - 7 * b) % 3 == 0;
      }
      puts(ok ? "YES" : "NO");
  }
}