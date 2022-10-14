#line 1 "sol.cpp"
#include <bits/stdc++.h>

std::pair<int, int> solve(int n, int m, long long k) {
  if (k < n) {
    return {k, 0};
  }
  k -= n;
  int row = n - 1 - k / (2 * (m - 1)) * 2;
  int r = k % (2 * (m - 1));
  if (r < m - 1) {
    return {row, r + 1};
  }
  return {row - 1, m - 1 - (r - (m - 1))};
}

int main() {
  int n, m;
  long long k;
  std::cin >> n >> m >> k;
  auto [x, y] = solve(n, m, k);
  printf("%d %d\n", x + 1, y + 1);
}