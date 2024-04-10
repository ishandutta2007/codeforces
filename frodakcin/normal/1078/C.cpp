#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

const int MOD = 998244353;
int sum(const int& a, const int& b) {
  return ti((tll(a) + tll(b))%MOD);
}
int prod(const int& a, const int& b) {
  return ti((tll(a) * tll(b))%MOD);
}
int dif(const int& a, const int& b) {
  return ti((tll(a) - tll(b) + tll(100)*MOD)%MOD);
}
int pow(int b, int p) {
  int r = 1;
  for(;p;p>>=1,b=prod(b, b)) if(p&1) r = prod(r, b);
  return r;
}
int divi(const int& n, const int& d) {
  return prod(n, pow(d, MOD-2));
}


const int MAXN = 3e5 + 100;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];
int N, dp[MAXN][3];

void dfs(const int& n = 1, const int& p = -1) {
  dp[n][0] = 1, dp[n][1] = 0, dp[n][2] = 1;
  int t = 1;
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    dfs(adj[n][i], n);
    dp[n][0] = prod(dp[n][0], sum(dp[adj[n][i]][0], dp[adj[n][i]][1]));
    dp[n][2] = prod(dp[n][2], sum(dp[adj[n][i]][0], prod(dp[adj[n][i]][1], 2)));
    t = prod(t, sum(dp[adj[n][i]][0], prod(dp[adj[n][i]][1], 2)));
  }
  dp[n][2] = dif(dp[n][2], dp[n][0]);
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    int w = divi(t, sum(dp[adj[n][i]][0], prod(dp[adj[n][i]][1], 2)));
    dp[n][1] = sum(dp[n][1], prod(w, sum(dp[adj[n][i]][2], dp[adj[n][i]][0])));
  }
  //printf("%d: %d %d %d\n", n, dp[n][0], dp[n][1], dp[n][2]);
}

int main() {
  scanf("%d", &N);
  for(int i = 0, u, v;i < N - 1;i++) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  for(int i = 0;i <= N;i++) for(int j = 0;j < 3;j++) dp[i][j] = 0;
  
  dfs();
  
  printf("%d\n", sum(dp[1][0], dp[1][1]));
  
  return 0;
}