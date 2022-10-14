#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 1'000'000'007;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<char>> grid(n, std::vector<char>(m + 1));
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i].data());
  }
  if (n < m) {
    std::vector<std::vector<char>> new_grid(m, std::vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        new_grid[j][i] = grid[i][j];
      }
    }
    grid = std::move(new_grid);
    std::swap(n, m);
  }
  std::vector<std::vector<int>> dp(2, std::vector<int>(1 << (m + 2)));
  int *old_dp = dp[1].data();
  int *new_dp = dp[0].data();
  new_dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::swap(old_dp, new_dp);
      std::fill(new_dp, new_dp + (1 << (m + 2)), 0);
      for (int mask = 0; mask < 1 << (m + 2); ++mask) {
        if (old_dp[mask]) {
          int act = j ? mask : mask & ~(1 << m);
          if (grid[i][j] == 'x') {
            add(new_dp[act & ~(1 << j | 1 << m)], old_dp[mask]);
          } else {
            add(new_dp[act | 1 << j | 1 << m], old_dp[mask]);
            if ((act >> m & 1) || (act >> j & 1)) {
              add(new_dp[act], old_dp[mask]);
            } else if (~mask >> (m + 1) & 1) {
              add(new_dp[act | 1 << (m + 1)], old_dp[mask]);
            }
          }
        }
      }
    }
  }
  int result = 0;
  for (int mask = 0; mask < 1 << (m + 2); ++mask) {
    add(result, new_dp[mask]);
  }
  printf("%d\n", result);
}