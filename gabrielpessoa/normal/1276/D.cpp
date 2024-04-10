#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 4e5+5;
const int inf = 1e18;
const int mod = 998244353;

vector<int> g[ms];
int dp[ms][3];

int solve(int cur, int rem, int par) {
  if(par == -1 && rem == 1) return 0;
  int hasPar = par != -1;
  int m = g[cur].size() - hasPar;
  int &ans = dp[cur][rem];
  if(~ans) return ans;
  int posP = -1;
  vector<int> rem1, rem0, rem2;
  rem1.push_back(1); 
  rem0.push_back(1);
  rem2.push_back(1);
  for(int i = 0; i < g[cur].size(); i++) {
    if(g[cur][i] == par) posP = i;
    else {
      rem1.emplace_back(solve(g[cur][i], 1, cur));
      rem2.emplace_back(solve(g[cur][i], 2, cur));
      rem0.emplace_back(solve(g[cur][i], 0, cur));
    }
  }
  rem1.push_back(1); 
  rem0.push_back(1);
  rem2.push_back(1);
  rem1.push_back(1); 
  rem0.push_back(1);
  rem2.push_back(1);
  int t = rem1.size();
  for(int i = 1; i < t; i++) {
    rem1[i] = rem1[i] * rem1[i-1] % mod;
  }
  for(int i = t-2; i >= 0; i--) {
    rem0[i] = rem0[i] * rem0[i+1] % mod;
  }
  ans = 0;
  if(rem == 1) {
    ans = (ans + rem1[posP] * rem0[posP+1]) % mod;
    for(int i = 0; i < posP; i++) {
      ans = (ans + (rem1[i] * rem0[i+2] % mod) * rem2[i+1]) % mod;
    }
  } else if(rem == 0) {
    ans = rem1[t-1];
    for(int i = 0; i < m; i++) {
      ans = (ans + (rem1[i] * rem0[i+2] % mod) * rem2[i+1]) % mod;
    }
  } else if(rem == 2) {
    ans = rem1[t-1];
    for(int i = posP; i < m; i++) {
      ans = (ans + (rem1[i] * rem0[i+2] % mod) * rem2[i+1]) % mod;
    }
  }
  // cout << cur << ' ' << rem << " = " << ans << endl;
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  cout << solve(1, 0, -1) << '\n';
}