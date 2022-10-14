#line 1 "sol.cpp"
#include <bits/stdc++.h>

const long double PI = acosl(-1.);

long double ang(long double x, long double y) {
  long double d = std::abs(x - y);
  return std::min(d, 2 * PI - d);
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<long double, int>> a(n);
  for (int i = 0, y, x; i < n; ++i) {
    scanf("%d%d", &x, &y);
    a[i] = {atan2l(y, x), i};
  }
  std::sort(a.begin(), a.end());
  std::pair<long double, std::pair<int, int>> best{
      std::numeric_limits<long double>::max(), {0, 0}};
  for (int i = 0; i < n; ++i) {
    auto [x, p] = a[i];
    auto [y, q] = a[i + 1 == n ? 0 : i + 1];
    best = std::min(best, {ang(x, y), {p, q}});
  }
  auto [x, y] = best.second;
  printf("%d %d\n", x + 1, y + 1);
}