#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int N, K;
vector< int > g[100];

int64 dp[201][42];

void rec(int idx, int par = -1)
{
  dp[idx][0] = dp[idx][K + 1] = 1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    rec(to, idx);
    vector< int64 > dp2(2 * K + 2); // preset
    for(int i = 0; i <= 2 * K; i++) {
      for(int j = 0; j <= 2 * K; j++) {
        if(i + j <= 2 * K) (dp2[min(i, j + 1)] += dp[idx][i] * dp[to][j]) %= mod;
        else (dp2[max(i, j + 1)] += dp[idx][i] * dp[to][j]) %= mod;
      }
    }
    for(int i = 0; i <= 2 * K; i++) dp[idx][i] = dp2[i];
  }
}

int main()
{
  cin >> N >> K;
  if(K == 0) {
    cout << 1 << endl;
    return (0);
  }
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  rec(0);
  int ret = 0;
  for(int i = 0; i <= K; i++) (ret += dp[0][i]) %= mod;
  cout << ret << endl;
}