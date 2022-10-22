#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> up(n, 0), down(n, 0);
  vector<int> dp(n, n);
  vector<int> dec = {0}, inc = {0};
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = min(dp[i-1]+1, dp[i]);
    while (!dec.empty() && a[dec.back()] <= a[i]) dec.pop_back();
    while (!inc.empty() && a[inc.back()] >= a[i]) inc.pop_back();
    if (a[i-1] < a[i]) {
      int last = *lower_bound(inc.begin(), inc.end(), dec.empty() ? -1 : dec.back());
      dp[i] = min(dp[last] + 1, dp[i]);
    } else {
      int last = *lower_bound(dec.begin(), dec.end(), inc.empty() ? -1 : inc.back());
      dp[i] = min(dp[last] + 1, dp[i]);
    }
    dec.push_back(i);
    inc.push_back(i);
  }
  cout << dp[n-1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}