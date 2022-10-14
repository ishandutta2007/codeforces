#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int m, d, w;
    scanf("%d%d%d", &m, &d, &w);
    // 0 <= x < y < min(m, d)
    // x * D + y = y * D + x (mod w)
    // w | (y - x) * (D - 1)
    long long result = 0;
    // for (int x = 0; x < m && x < d; ++ x) {
    //     for (int y = x + 1; y < m && y < d; ++ y) {
    //         result += 1LL * (y - x) * (d - 1) % w == 0;
    //     }
    // }
    if (d > 1) {
      w /= std::__gcd(w, d - 1);
      int ub = std::min(m, d);
      // w' | (y - x)
      //   for (int d = w; d < ub; d += w) {
      //     result += ub - d;
      //   }
      int k = (ub - 1) / w;
      // 1 .. k
      result += 1LL * ub * k;
      result -= (1LL + k) * k / 2 * w;
    }
    printf("%lld\n", result);
  }
}