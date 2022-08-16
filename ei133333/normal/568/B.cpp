#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int N, dp[4001][2];

int main()
{
  cin >> N;
  dp[0][0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = i; j >= 0; j--) {
      for(int k = 1; k >= 0; k--) {
        int base = dp[j][k];
        dp[j][k] = 0;
        (dp[j][1] += base) %= mod;
        (dp[j + 1][k] += base) %= mod;
        (dp[j][k] += 1LL * base * j % mod) %= mod;
      }
    }
  }

  int ret = 0;
  for(int i = 0; i <= N; i++) (ret += dp[i][1]) %= mod;
  cout << ret << endl;
}