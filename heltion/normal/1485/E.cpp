#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
vector<int> G[maxn];
vector<int> D[maxn];
int d[maxn], dn;
LL dp[maxn], a[maxn];
void DFS(int u){
  D[d[u]].push_back(u);
  dn = max(dn, d[u]);
  for(int v : G[u]) if(not d[v]){
    d[v] = d[u] + 1;
    DFS(v);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    dn = 0;
    for(int i = 1; i <= n; i += 1){
      G[i].clear();
      D[i].clear();
      d[i] = 0;
      dp[i] = 0;
    }
    for(int i = 2, v; i <= n; i += 1){
      cin >> v;
      G[i].push_back(v);
      G[v].push_back(i);
    }
    for(int i = 2; i <= n; i += 1) cin >> a[i];
    DFS(d[1] = 1);
    for(int i = dn; i > 1; i -= 1){
      LL pma = INT_MIN, mma = INT_MIN;
      for(int v : D[i]){
        pma = max(pma, a[v] + dp[v]);
        mma = max(mma, dp[v] - a[v]);
      }
      LL smi = INT_MAX, sma = INT_MIN;
      for(int v : D[i]){
        smi = min(smi, a[v]);
        sma = max(sma, a[v]);
      }
      for(int u : D[i - 1]){
        for(int v : G[u]) if(d[v] == d[u] + 1){
          dp[u] = max(dp[u], dp[v] + abs(smi - a[v]));
          dp[u] = max(dp[u], dp[v] + abs(sma - a[v]));
          dp[u] = max(dp[u], pma - a[v]);
          dp[u] = max(dp[u], mma + a[v]);
        }
      }
    }
    cout << dp[1] << "\n";
  }
  return 0;
}