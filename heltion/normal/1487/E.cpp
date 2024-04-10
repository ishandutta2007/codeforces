#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 150000 + 1;
int n[4], a[4][maxn], dp[4][maxn];
vector<int> G[4][maxn];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i = 0; i < 4; i += 1) cin >> n[i];
  for(int i = 0; i < 4; i += 1)
    for(int j = 1; j <= n[i]; j += 1) cin >> a[i][j];
  for(int i = 1, m, x, y; i < 4; i += 1)
    for(cin >> m; m; m -= 1){
      cin >> x >> y;
      G[i][y].push_back(x);
    }
  for(int i = 1; i <= n[0]; i += 1) dp[0][i] = a[0][i];
  for(int i = 1; i < 4; i += 1){
    multiset<int> ms;
    for(int j = 1; j <= n[i - 1]; j += 1) if(dp[i - 1][j] != -1) ms.insert(dp[i - 1][j]);
    for(int j = 1; j <= n[i]; j += 1){
      for(int k : G[i][j]) if(dp[i - 1][k] != -1) ms.erase(ms.find(dp[i - 1][k]));
      if(ms.empty()) dp[i][j] = -1;
      else dp[i][j] = *ms.begin() + a[i][j];
      for(int k : G[i][j]) if(dp[i - 1][k] != -1) ms.insert(dp[i - 1][k]);
    }
  }
  int ans = -1;
  for(int i = 1; i <= n[3]; i += 1)
    if(dp[3][i] != -1)
      if(ans == -1 or ans > dp[3][i]) ans = dp[3][i];
  cout << ans;
  return 0;
}