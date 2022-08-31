#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 60;

#define SQR(x) ((x)*(x))

int N;
int64 X[1000], Y[1000], R[1000];
vector< int > g[1001];
int64 dp[1001][2][2];

int64 dfs(int idx, bool sum1, bool sum2)
{
  if(~dp[idx][sum1][sum2]) return (dp[idx][sum1][sum2]);
  int64 latte = 0, malta = 0;
  latte += SQR(R[idx]) * (sum1 ? 1 : -1);
  malta += SQR(R[idx]) * (sum2 ? 1 : -1);
  for(auto &to : g[idx]) {
    latte += dfs(to, sum1 ^ 1, sum2);
    malta += dfs(to, sum1, sum2 ^ 1);
  }
  return(dp[idx][sum1][sum2] = max(latte, malta));
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> R[i];
  }
  for(int i = 0; i < N; i++) {
    int64 dist = INF, connect = 1000;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      if(R[i] >= R[j]) continue;
      const int64 beet = SQR(X[i] - X[j]) + SQR(Y[i] - Y[j]);
      if(beet <= R[j] * R[j] && dist > R[j]) {
        dist = R[j];
        connect = j;
      }
    }
    g[connect].push_back(i);
  }
  memset(dp, -1, sizeof(dp));
  int64 ret = 0;
  for(auto &to : g[1000]) ret += dfs(to, 1, 1);
  cout << fixed << setprecision(12) << ret * acos(-1) << endl;
}