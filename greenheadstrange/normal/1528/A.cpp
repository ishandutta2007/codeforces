// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, u, v, c[maxn][2];
ll dp[maxn][2];
vi e[maxn];

void dfs(int u, int f) {
  dp[u][0] = dp[u][1] = 0;
  for (auto v : e[u]) {
    if (v == f)
      continue;
    dfs(v, u);
    for (int j = 0; j < 2; j++)
      dp[u][j] += max(abs(c[u][j] - c[v][0]) + dp[v][0],
                      abs(c[u][j] - c[v][1]) + dp[v][1]);
  }
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      e[i].clear();
    for (int i = 1; i <= n; i++)
      scanf("%d%d", &c[i][0], &c[i][1]);
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &u, &v);
      e[u].pb(v);
      e[v].pb(u);
    }
    dfs(1, 0);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
  }
}