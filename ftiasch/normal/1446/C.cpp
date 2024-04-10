#include <bits/stdc++.h>

using Result = std::array<int, 2>;

const int N = 200000;

int n, a[N];

Result solve(int d, int offset, int l, int r) {
  if (l == r) {
    return {0, 0};
  }
  if (l + 1 == r) {
    return {0, 0};
  }
  int offset1 = offset | 1 << d;
  int m = std::lower_bound(a + l, a + r, offset1) - a;
  auto lr = solve(d - 1, offset, l, m);
  auto rr = solve(d - 1, offset1, m, r);
  return {std::min(lr[0] + (r - m), rr[0] + (m - l)),
          std::min(lr[0] + rr[1], lr[1] + rr[0])};
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::sort(a, a + n);
    printf("%d\n", solve(29, 0, 0, n)[1]);
  }
}