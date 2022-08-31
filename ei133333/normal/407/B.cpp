#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int N, P[1000];
int dp[1002], sum[1002];

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    --P[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = P[i]; j < i; j++) {
      (dp[i] += dp[j]) %= mod;
    }
    (dp[i] += 2) %= mod;
  }
  cout << accumulate(dp, dp + N, 0LL) % mod << endl;
}