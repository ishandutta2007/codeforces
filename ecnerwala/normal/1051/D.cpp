#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MAXK = 3e3;
int N,K;
ll dp[MAXK][MAXK][2];
int main() {
 cin >> N >> K;
 dp[1][1][0] = 2;
 dp[1][2][1] = 2;
 for (int i = 1; i < N; i++) {
  for (int k = 1; k <= 2*i; k++) {
   ll v0 = dp[i][k][0] % MOD, v1 = dp[i][k][1] % MOD;
   dp[i+1][k+0][0] += v0 + 2 * v1;
   dp[i+1][k+1][0] += v0;
   dp[i+1][k+0][1] += v1;
   dp[i+1][k+1][1] += 2*v0;
   dp[i+1][k+2][1] += v1;
  }
 }
 cout << (dp[N][K][0]+dp[N][K][1]) % MOD << '\n';
}