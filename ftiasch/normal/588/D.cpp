#line 1 "/tmp/tmp-334343smRiALBSFrv5.cpp"
#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, k;
  long long l;
  std::cin >> n >> l >> k;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int ai;
    std::cin >> ai;
    a[i] = {ai, i};
  }
  std::sort(a.begin(), a.end());
  long long full = l / n;
  int remain = l % n, result = 0;
  std::vector<int> dp(n, 1);
  for (int x = 1; x <= k; ++x) {
    for (int i = 0; i < n; ++i) {
      int r = a[i].second;
      if (x <= full) {
        add(result, static_cast<long long>((full - x + 1) % MOD) * dp[i] % MOD);
      }
      if (x - 1 <= full && r < remain) {
        add(result, dp[i]);
      }
    }
    std::vector<int> new_dp(n, 0);
    for (int i = 0, j = 0, sum = 0; i < n; ++i) {
      while (j < n && a[j].first <= a[i].first) {
        add(sum, dp[j++]);
      }
      new_dp[i] = sum;
    }
    dp.swap(new_dp);
  }
  std::cout << result << "\n";
}