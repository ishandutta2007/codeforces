#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
#define pb push_back
#define mp make_pair
#define to second
#define wt first

typedef long long ll;
#define tll(X) static_cast<ll>(X)

const int MAXN = 3e5 + 100;

int N;

int w[MAXN];
vpi adj[MAXN];
ll dp[MAXN][3];
ll ans;

const ll INF = 1e16;

void rph(ll& a, const ll& b) {if(a < b) a = b;}
void rph2(ll * a, ll b) {for(int i = 0;i < 2;i++) if(b > a[i]) swap(b, a[i]);}
void dfs(int n = 1, int p = -1) {
  dp[n][0] = 0LL;
  int c = 0;
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i].to == p) continue;
    c++;
    dfs(adj[n][i].to, n);
    rph(dp[n][0], dp[adj[n][i].to][0] - adj[n][i].wt);
    rph2(dp[n] + 1, dp[adj[n][i].to][0] - adj[n][i].wt);
  }
  dp[n][0] += tll(w[n]);
  rph(ans, dp[n][0]);
  if(c > 1) rph(ans, dp[n][1] + dp[n][2] + tll(w[n]));
}

int main() {
  scanf("%d", &N);
  
  for(int i = 0;i < N;i++) scanf("%d", w + i + 1);
  
  for(int i = 0, u, v, q;i < N - 1;i++) {
    scanf("%d%d%d", &u, &v, &q);
    adj[u].pb(mp(q, v));
    adj[v].pb(mp(q, u));
  }
  
  for(int i = 0;i < N;i++) for(int j = 0;j < 3;j++) dp[i][j] = -INF;
  
  ans = 0LL;
  dfs();
  
  printf("%lld\n", ans);
  
  return 0;
}