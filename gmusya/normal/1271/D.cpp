#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  vvi can(n + 1);
  vi ma(n + 1, -1);
  for (int i = 1; i <= n; i++)
    ma[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    swap(u, v);
    ma[u] = max(ma[u], v);
  }
  for (int i = 1; i <= n; i++)
    can[ma[i]].push_back(i);
  for (int i = 1; i <= n; i++)
    sort(can[i].begin(), can[i].end(), [&](int a, int b){
      return c[a] > c[b];
    });
  vvi dp(n + 1, vi(5001, -1e9));
  dp[0][k] = 0;
  for (int i = 1; i <= n; i++) {
    for (int oldk = a[i]; oldk <= 5000; oldk++) {
      if (oldk + b[i] <= 5000)
        dp[i][oldk + b[i]] = max(dp[i][oldk + b[i]], dp[i - 1][oldk]);
      int cursum = 0;
      for (int it = 0; it < (int)can[i].size(); it++) {
        int newk = oldk + b[i] - (it + 1);
        cursum += c[can[i][it]];
        if (newk >= 0 && newk <= 5000)
          dp[i][newk] = max(dp[i][newk], dp[i - 1][oldk] + cursum);
      }
    }
  }
  int ans = -1;
  for (int i = 0; i <= 5000; i++)
    ans = max(ans, dp[n][i]);
  cout << ans;
  return 0;
}