#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <vector <int>> fact(200'001);
  for (int i = 1; i <= 200'000; i++)
    for (int j = 2 * i; j <= 200'000; j += i)
      fact[j].push_back(i);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> cnt(200'001);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    for (int i = 1; i <= 200'000; i++)
      cnt[i] += cnt[i - 1];
    vector <int> dp(200'001, n + 1);
    for (int i = 1; i <= 200'000; i++) {
      if (cnt[i] - cnt[i - 1] == 0)
        continue;
      dp[i] = cnt[i - 1];
      for (int j : fact[i])
        dp[i] = min(dp[i], dp[j] + cnt[i - 1] - cnt[j]);
    }
    int ans = n + 1;
    for (int i = 1; i <= 200'000; i++) {
      if (cnt[i] - cnt[i - 1] == 0)
        continue;
      ans = min(ans, dp[i] + cnt[200'000] - cnt[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}