#line 1 "sol.cpp"
#include <bits/stdc++.h>

template <typename T> void update(T &x, T a) { x = std::max(x, a); }

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::array<int, 3>> a(n);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[j][i]);
    }
  }
  using Long = long long;
  const Long INF = 3'000'000'000LL * n + 1;
  std::array<Long, 5> dp;
  dp[0] = a[0][0];
  dp[1] = a[0][0] + a[0][1];
  dp[2] = dp[3] = static_cast<Long>(a[0][0]) + a[0][1] + a[0][2];
  dp[4] = -INF;
  for (int i = 1; i < n; ++i) {
    Long sum = static_cast<Long>(a[i][0]) + a[i][1] + a[i][2];

    std::array<Long, 5> new_dp;
    std::fill(new_dp.begin(), new_dp.end(), -INF);

    update(new_dp[0], dp[0] + a[i][0]);
    update(new_dp[1], dp[0] + a[i][0] + a[i][1]);
    update(new_dp[2], dp[0] + sum);
    update(new_dp[3], dp[0] + sum);

    update(new_dp[0], dp[1] + a[i][0] + a[i][1]);
    update(new_dp[1], dp[1] + a[i][1]);
    update(new_dp[2], dp[1] + a[i][1] + a[i][2]);

    update(new_dp[0], dp[2] + sum);
    update(new_dp[1], dp[2] + a[i][1] + a[i][2]);
    update(new_dp[2], dp[2] + a[i][2]);
    update(new_dp[4], dp[2] + sum);

    update(new_dp[3], dp[3] + sum);
    update(new_dp[2], dp[3] + sum);

    update(new_dp[4], dp[4] + sum);
    update(new_dp[0], dp[4] + sum);

    dp = new_dp;
  }
  printf("%lld\n", dp[2]);
}