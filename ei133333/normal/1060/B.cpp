#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string N;
  cin >> N;
  reverse(begin(N), end(N));

  int dp[16][2];
  fill_n(*dp, 16 * 2, -133333);
  dp[0][0] = 0;
  for(int i = 0; i < N.size(); i++) {
    for(int j = 0; j < 2; j++) { // 
      for(int k = 0; k < 10; k++) { // a
        int l = (N[i] - '0') - k - j;
        int nxt = 0;
        if(l < 0) nxt++, l += 10;
        dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + k + l);
      }
    }
  }
  cout << dp[N.size()][0] << endl;
}