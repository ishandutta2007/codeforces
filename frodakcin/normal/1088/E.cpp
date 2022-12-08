#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

const int MAXN = 3e5 + 100;
const int MAXV = 1e9 + 10000;
const ll INF = tll(MAXN) * tll(MAXV);

int N;
int a[MAXN], K;
ll dp[MAXN], ans;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];

void dfs1(int n = 1, int p = -1) {
  dp[n] = tll(a[n]);
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    dfs1(adj[n][i], n);
    if(dp[adj[n][i]] > 0) dp[n] += dp[adj[n][i]];
  }
  if(dp[n] > ans) ans = dp[n];
}
int dfs2(int n = 1, int p = -1) {
  int k = 0;
  dp[n] = tll(a[n]);
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    k += dfs2(adj[n][i], n);
    if(dp[adj[n][i]] > 0) dp[n] += dp[adj[n][i]];
  }
  if(dp[n] == ans) ++k, dp[n] = 0;
  return k;
}

int main() {
  ans = -INF;
  scanf("%d", &N);
  for(int i = 1;i <= N;i++) scanf("%d", a + i);
  for(int i = 0, u, v;i < N - 1;i++) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs1();
  K = dfs2();
  printf("%lld %d\n", ans * K, K);
  return 0;
}