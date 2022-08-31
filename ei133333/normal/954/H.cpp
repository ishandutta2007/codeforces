#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 1e9 + 7;

int64 N, A[5000];

int main() {
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    cin >> A[i];
  }

  int64 fact = 1;

  vector< int64 > sum(2 * N - 1);
  vector< vector< int > > dp(2, vector< int >(3));
  dp[0][0] = 1; // 0: 
  for(int i = 1; i < N; i++) {
    (fact *= A[i - 1]) %= mod;
    vector< vector< int > > dp2(i * 2 + 2, vector< int >(3));
    dp2[0][0] = fact;
    for(int j = 1; j <= i * 2; j++) {
      if(j >= 2) (dp2[j][2] += 1LL * dp[j - 2][2] * A[i - 1] % mod * A[i - 1] % mod) %= mod; // 2: 2
      if(j >= 2) (dp2[j][2] += 1LL * dp[j - 2][0] * (A[i - 1] * (A[i - 1] - 1) / 2 % mod) % mod) %= mod; // 2: 2
      if(j >= 1) (dp2[j][1] += 1LL * dp[j - 1][2] * A[i - 1] % mod * 2 % mod) %= mod; // 1: 2
      if(j >= 1) (dp2[j][1] += 1LL * dp[j - 1][1] * A[i - 1] % mod) %= mod; // 1: 1(
      if(j >= 1) (dp2[j][1] += 1LL * dp[j - 1][0] * A[i - 1] % mod) %= mod; // 1: 1
    }
    dp.swap(dp2);
    for(int j = 1; j <= i * 2; j++) {
      for(int k = 1; k <= 2; k++) (sum[j] += dp[j][k]) %= mod;
    }
  }

  for(int i = 1; i <= 2 * N - 2; i++) {
    cout << sum[i] << " ";
  }
  cout << endl;
}