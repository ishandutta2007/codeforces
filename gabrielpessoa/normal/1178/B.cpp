#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6+5;

int dp[ms][3];

main() {
  string s;
  cin >> s;
  for(int i = ((int) s.size()) - 2; i >= 0; i--) {
    for(int j = 0; j < 3; j++) {
      dp[i][j] = dp[i+1][j];
    }
    if(s[i] == 'v' && s[i+1] == 'v') {
      dp[i][0] += dp[i+1][1];
      dp[i][2]++;
    }
    if(s[i] == 'o') {
      dp[i][1] += dp[i+1][2];
    }
  }
  cout << dp[0][0] << '\n';
}