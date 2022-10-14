#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    puts([&]() -> bool {
      if (n < k) {
        return false;
      }
      n -= k;
      if (n & 1) {
        return false;
      }
      return (k - 1LL) * k / 2 <= (n >> 1);
    }()
                      ? "YES"
                      : "NO");
  }
}