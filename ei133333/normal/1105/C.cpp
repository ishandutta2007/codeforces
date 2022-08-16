#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int main() {
  int64 N, L, R;
  cin >> N >> L >> R;
  --L;
  int64 dp[3] = {};
  dp[0] = 1;
  for(int i = 0; i < N; i++) {
    int64 dp2[3] = {};
    for(int j = 0; j < 3; j++) {
      for(int k = 1; k <= 3; k++) {
        int64 add = (R + 3-k) / 3 - (L + 3-k) / 3;
        dp2[(j + k) % 3] += dp[j] * add % mod;
        dp2[(j + k) % 3] %= mod;
      }
    }
    swap(dp, dp2);
  }
  cout << dp[0] << endl;
}