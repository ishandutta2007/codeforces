#include <bits/stdc++.h>

int divide(int a, int b) { return (a + b - 1) / b; }

int solve(int n) {
  int result = n;
  int x = 1;
  while (x < n) {
    int y = divide(n, x);
    result = std::min(result, x - 1 + y);
    x = divide(n, y - 1);
  }
  return result;
}

int main() {
  int T, n, d;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &d);
    puts(solve(d) <= n ? "YES" : "NO");
  }
}