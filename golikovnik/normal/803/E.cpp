#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int const WIN = 0;
  int const LOSE = 1;
  int const DRAW = 2;

  vector delta_bal{1, -1, 0};
  string c = "WLD";

  int const MAX_BAL = 2 * k + 1;
  vector<vector<int>> dp(n + 1, vector<int>(MAX_BAL, -1));
  dp[0][k] = WIN;
  for (int i = 0; i < n; ++i) {
    for (int bal = 0; bal < MAX_BAL; ++bal) {
      if (dp[i][bal] < 0) {
        continue;
      }
      for (int j : {WIN, LOSE, DRAW}) {
        if (s[i] != '?' && s[i] != c[j]) {
          continue;
        }
        auto min_bal = i + 1 == n ? 0 : 1;
        auto max_bal = i + 1 == n ? MAX_BAL - 1 : MAX_BAL - 2;
        auto new_bal = bal + delta_bal[j];
        if (min_bal <= new_bal && new_bal <= max_bal) {
          dp[i + 1][new_bal] = j;
        }
      }
    } 
  }
  for (int bal : {0, MAX_BAL - 1}) {
    if (dp.back()[bal] < 0) {
      continue;
    }
    string ans;
    for (int i = n, b = bal; i > 0; ) {
      auto put = dp[i][b];
      ans += c[put];
      b -= delta_bal[put];
      --i;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
  }
  cout << "NO\n";
  return 0;
}