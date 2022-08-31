#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;

int N, M, K, X;
vector< int > g[100000];
int64 dp[100000][11][3], dp2[11][3];

int gettype(int a, int b)
{
  if(a == 2 || b == 2) return (2); // beet
  if(a == 0 && b == 0) return (0); // less then
  return (1); // any
}

int64 rec(int idx, int par = -1)
{
  dp[idx][0][0] = 1;

  for(auto &to : g[idx]) {
    if(par == to) continue;
    rec(to, idx);
    memset(dp2, 0, sizeof(dp2));
    for(int i = 0; i <= 10; i++) {
      for(int j = 0; j <= 10 - i; j++) {
        for(int k = 0; k <= 2; k++) {
          for(int l = 0; l <= 2; l++) {
            (dp2[i + j][gettype(k, l)] += 1LL * dp[idx][i][k] * dp[to][j][l] % mod) %= mod;
          }
        }
      }
    }
    for(int i = 0; i <= 10; i++) {
      dp[idx][i][0] = dp2[i][0];
      dp[idx][i][1] = dp2[i][1];
      dp[idx][i][2] = dp2[i][2];
    }
  }

  memset(dp2, 0, sizeof(dp2));
  int ret = 0;

  for(int i = 0; i < 10; i++) { // -> add
    (dp2[i + 1][2] += dp[idx][i][0]) %= mod; // less
  }
  for(int i = 0; i <= 10; i++) { // -> less then
    (dp2[i][0] += dp[idx][i][0] * (K - 1) % mod) %= mod;
    (dp2[i][0] += dp[idx][i][1] * (K - 1) % mod) %= mod;
    (dp2[i][0] += dp[idx][i][2] * (K - 1) % mod) %= mod;
  }

  for(int i = 0; i <= 10; i++) { // -> any
    (dp2[i][1] += dp[idx][i][0] * (M - K) % mod) %= mod;
    (dp2[i][1] += dp[idx][i][1] * (M - K) % mod) %= mod;
  }

  for(int i = 0; i <= X; i++) {
    dp[idx][i][0] = dp2[i][0];
    dp[idx][i][1] = dp2[i][1];
    dp[idx][i][2] = dp2[i][2];
    (ret += dp[idx][i][0]) %= mod;
    (ret += dp[idx][i][1]) %= mod;
    (ret += dp[idx][i][2]) %= mod;
  }
  return (ret);
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  cin >> K >> X;
  printf("%lld\n", rec(0));
}