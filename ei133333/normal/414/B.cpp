#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 mod = 1e9 + 7;

int64 dp[2001][2001];

int main()
{
  int N, K;
  cin >> N >> K;

  dp[0][1] = 1;
  for(int i = 0; i < K; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = j; k <= N; k += j) {
        (dp[i + 1][k] += dp[i][j]) %= mod;
      }
    }
  }

  int64 ret = 0;
  for(int i = 1; i <= N; i++) (ret += dp[K][i]) %= mod;
  cout << ret << endl;
}