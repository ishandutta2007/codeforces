#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, l;
  cin >> n >> k >> l;
  if ((i64) k * l >= n) {
    cout << "0\n";
    return 0;
  }
  string s;
  cin >> s;
  vector<bool> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = 'a' <= s[i] && s[i] <= 'z';
  }
  auto solve = [&]() -> i64 {
    auto solve_inner = [&](i64 lam) -> pair<i64, int> {
      vector<pair<i64, int>> dp(n + 1);
      for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (a[i]) {
          continue;
        }
        ++dp[i + 1].first;
        auto if_use = dp[max(0, i + 1 - l)];
        if_use.first += lam;
        ++if_use.second;
        dp[i + 1] = min(dp[i + 1], if_use);
      }
      return dp.back();
    };
    i64 left = -1;
    i64 right = (i64) 1e12;
    while (left + 1 != right) {
      auto lam = (left + right) / 2;
      auto[score, used] = solve_inner(lam);
      if (used > k) {
        left = lam;
      } else {
        right = lam;
      }
    }
    auto get_score = [](auto p, auto lam) {
      return p.first - p.second * lam;
    };
    auto f_right = solve_inner(right);
    auto score_right = get_score(f_right, right);
    if (f_right.second == k || !right) {
      return score_right;
    }
    auto f_left = solve_inner(left);
    auto score_left = get_score(f_left, left);
    auto kk = (long double) (score_left - score_right) / (f_left.second -
            f_right.second);
    auto b = score_left - kk * f_left.second;
    return (i64) roundl(kk * k + b);
  };
  auto score = solve();
  for (int i = 0; i < n; ++i) {
    a[i] = !a[i];
  }
  score = min(score, solve());
  cout << score << '\n';
}