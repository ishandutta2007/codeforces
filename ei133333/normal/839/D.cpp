#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int mod = 1e9 + 7;
const int H = 1000000;

int main()
{
  int N, fact[200001];
  fact[0] = 1;
  for(int i = 1; i < 200001; i++) fact[i] = fact[i - 1] * 2 % mod;
  cin >> N;
  vector< int64 > dp(H + 1, 0);
  for(int i = 0; i < N; i++) {
    int X;
    cin >> X;
    ++dp[X];
  }
  for(int i = 1; i <= H; i++) {
    for(int j = i + i; j <= H; j += i) dp[i] += dp[j];
    if(dp[i] == 0) continue;
    (dp[i] *= fact[dp[i] - 1]) %= mod;
  }
  int ret = 0;
  for(int i = H; i > 1; i--) {
    for(int j = i + i; j <= H; j += i) (dp[i] += mod - dp[j]) %= mod;
    (ret += i * dp[i] % mod) %= mod;
  }
  cout << ret << endl;
}