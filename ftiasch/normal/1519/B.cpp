#include <bits/stdc++.h>

bool check(int n, int m, int k) { return 1 * (m - 1) + m * (n - 1) == k; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    puts(check(n, m, k) ? "YES" : "NO");
  }
}