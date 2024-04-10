#include <bits/stdc++.h>

using namespace std;

const int N = 123, mod = 1e9 + 7;

long long C[N][N];
vector<int> g[N];

void dfs(int v, vector<int>& cnt, int par = -1, int depth = 0) {
  ++cnt[depth];
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, cnt, v, depth+1);
  }
}

long long calc(vector<int> cnt, int k) {
  vector<int> dp(k+1, 0);
  dp[0] = 1;
  for (int x : cnt) {
    for (int i = k; i > 0; --i) {
      dp[i] = (dp[i] + (long long)dp[i-1] * x) % mod;
    }
  }
  return dp[k];
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  if (k == 2) {
    ans = 1LL * n * (n - 1) / 2;
    ans %= mod;
    printf("%lld\n", ans);
    return;
  }
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> cnt(g[i].size(), vector<int>(n, 0));
    for (int j = 0; j < (int)g[i].size(); ++j) {
      dfs(g[i][j], cnt[j], i);
    }
    vector<int> sz(g[i].size());
    for (int j = 0; j < n; ++j) {
      for (int z = 0; z < (int)g[i].size(); ++z) {
        sz[z] = cnt[z][j];
      }
      ans += calc(sz, k);
      if (ans >= mod)
        ans -= mod;
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}