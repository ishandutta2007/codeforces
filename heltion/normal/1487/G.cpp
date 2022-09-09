#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 400 + 2;
LL dp[2][maxn][maxn][3][3];
LL sum[maxn][maxn];
int c[26];
void add(LL& x, LL y){
  x += y;
  if(x >= mod) x -= mod;
}
void sub(LL& x, LL y){
  x -= y;
  if(x < 0) x += mod;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < 26; i += 1) cin >> c[i];
  dp[0][0][0][0][0] = 1;
  for(int i = 1; i <= n; i += 1){
    int v = i & 1, u = v ^ 1;
    for(int j = 0; j <= n; j += 1)
      for(int k = 0; k <= n; k += 1)
        for(int x = 0; x < 3; x += 1)
          for(int y = 0; y < 3; y += 1)
            dp[v][j][k][x][y] = 0;
    for(int j = 0; j <= n; j += 1)
      for(int k = 0; k <= n; k += 1)
        for(int x = 0; x < 3; x += 1)
          for(int y = 0; y < 3; y += 1)if(dp[u][j][k][x][y]){
              //cout << i - 1 << " " << j << " " << k << " " << x << " " << y << " " << dp[u][j][k][x][y] << "\n";
              add(dp[v][j][k][y][0], dp[u][j][k][x][y] * (x == 0 and i > 2 ? 23 : 24) % mod);
              if(x != 1) add(dp[v][j + 1][k][y][1], dp[u][j][k][x][y]);
              if(x != 2) add(dp[v][j][k + 1][y][2], dp[u][j][k][x][y]);
          }
  }
  LL ans = 1;
  for(int i = 0; i < n; i += 1){
    if(i < 2) ans = ans * 26;
    else ans = ans * 25 % mod;
  }
  int u = n & 1;
  for(int j = 0; j <= n; j += 1)
    for(int k = 0; k <= n; k += 1)
      for(int x = 0; x < 3; x += 1)
        for(int y = 0; y < 3; y += 1)if(dp[u][j][k][x][y]){
          //cout << n << " " << j << " " << k << " " << x << " " << y << " " << dp[u][j][k][x][y] << "\n";
          add(sum[j][k], dp[u][j][k][x][y]);
        }
  for(int j = n; j >= 0; j -= 1)
    for(int k = n; k >= 0; k -= 1)
      add(sum[j][k], sum[j + 1][k]);
  for(int j = n; j >= 0; j -= 1)
    for(int k = n; k >= 0; k -= 1)
      add(sum[j][k], sum[j][k + 1]);
  for(int i = 0; i < 26; i += 1)
    sub(ans, sum[c[i] + 1][0]);
  for(int i = 0; i < 26; i += 1)
    for(int j = i + 1; j < 26; j += 1)
      add(ans, sum[c[i] + 1][c[j] + 1]);
  cout << ans;
  return 0;
}