
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[ms];
int x[ms];
int s[ms];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> s[i];
  }
  dp[m+1] = 0;
  for(int i = m; i >= 1; i--) {
    dp[i] = inf;
    for(int j = 0; j < n; j++) {
      if(x[j] <= i) {
        if(x[j] + s[j] < i) dp[i] = min(dp[i], dp[i+1]+1);
        else dp[i] = min(dp[i], dp[i+1]);
      } else {
        int k = min(m+1, ((x[j] - i) + x[j] + 1));
        int cst = max(0, x[j] - i - s[j]);
        dp[i] = min(dp[i], dp[k]+cst);
      }
    }
  }
  cout << dp[1] << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  // cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}