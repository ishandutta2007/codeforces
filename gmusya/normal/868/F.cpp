#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

vector <int> a;
vector <int> cnt;
vector <vector <ll>> dp;

int L = 0, R = -1;
ll f = 0;

void add(int val) {
  f += cnt[val];
  cnt[val]++;
}

void erase(int val) {
  cnt[val]--;
  f -= cnt[val];
}

void mo(int newl, int newr) {
  for (; L > newl; L--)
    add(a[L - 1]);
  for (; R < newr; R++)
    add(a[R + 1]);
  for (; L < newl; L++)
    erase(a[L]);
  for (; R > newr; R--)
    erase(a[R]);
}

void solve(int k, int l, int r, int optl, int optr) {
  if (l > r)
    return;
  int m = (l + r) / 2, optm = optl;
  mo(optm + 1, m);
  dp[m][k] = min(dp[optm][k - 1] + f, dp[m][k - 1]);
  for (int i = optl + 1; i <= optr && i < m; i++) {
    mo(i + 1, m);
    if (dp[i][k - 1] + f <= dp[m][k]) {
      dp[m][k] = dp[i][k - 1] + f;
      optm = i;
    }
  }
  solve(k, l, m - 1, optl, optm);
  solve(k, m + 1, r, optm, optr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  a = vector <int>(n + 1);
  cnt = vector<int>(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dp = vector <vector <ll>>(n + 1, vector<ll>(k + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++)
    solve(i, 1, n, 0, n);
  cout << dp[n][k];
  return 0;
}