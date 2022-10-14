#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, cnt_a, cnt_b, a, b;
    scanf("%d%d%d%d%d%d", &n, &m, &cnt_a, &cnt_b, &a, &b);
    if (a > b) {
      std::swap(a, b);
      std::swap(cnt_a, cnt_b);
    }
    int result = 0;
    for (int x = 0; x <= cnt_a && a * x <= n; ++x) {
      int y = std::min(cnt_b, (n - a * x) / b);
      int rem_a = cnt_a - x;
      int rem_b = cnt_b - y;
      if (1LL * rem_a * a > m) {
        result = std::max(result, x + y + m / a);
      } else {
        int yy = std::min(rem_b, (m - rem_a * a) / b);
        result = std::max(result, x + y + rem_a + yy);
      }
    }
    printf("%d\n", result);
  }
}