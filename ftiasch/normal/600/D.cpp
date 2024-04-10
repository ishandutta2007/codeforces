#line 1 "sol.cpp"
#include <bits/stdc++.h>

long double PI = acosl(-1.);

long double safe_acos(long double a) {
  return acosl(std::min<long double>(std::max<long double>(a, -1), 1));
}

long double solve(int r1, int r2, long long d2) {
  if (d2 >= 1LL * (r1 + r2) * (r1 + r2)) {
    return 0.;
  }
  if (d2 <= 1LL * (r1 - r2) * (r1 - r2)) {
    int r = std::min(r1, r2);
    return PI * r * r;
  }
  long double d = sqrtl(d2);
  long double x = 0.5 * ((1LL * r1 * r1 - 1LL * r2 * r2) / d + d);
  long double y = 0.5 * ((1LL * r2 * r2 - 1LL * r1 * r1) / d + d);
  long double a1 = safe_acos(x / r1);
  long double a2 = safe_acos(y / r2);
  return (a1 - sinl(a1) * (x / r1)) * r1 * r1 +
         (a2 - sinl(a2) * (y / r2)) * r2 * r2;
}

int main() {
  int x1, y1, r1, x2, y2, r2;
  scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
  x2 -= x1;
  y2 -= y1;
  std::cout << std::setprecision(20) << solve(r1, r2, 1LL * x2 * x2 + 1LL * y2 * y2) << std::endl;
}