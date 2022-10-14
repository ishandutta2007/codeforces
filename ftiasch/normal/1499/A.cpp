#include <bits/stdc++.h>

bool check(int k1, int k2, int n) { return 2 * n <= ((k1 + k2) & ~1); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k1, k2, w, b;
    scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
    puts(check(k1, k2, w) && check(n - k1, n - k2, b) ? "YES" : "NO");
  }
}