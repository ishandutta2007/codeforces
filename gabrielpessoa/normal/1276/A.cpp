#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 3e5+5;
const int inf = 1e18;

int dp[ms][5];
int go[ms][5];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < 5; i++) {
      dp[n][i] = 0;
    }
    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < 5; j++) {
        dp[i][j] = dp[i+1][j] + 1;
        go[i][j] = -1;
        int g = 0;
        if(j == 4 && s[i] == 'o') g = -1;
        else if(s[i] == 'o') g = 1;
        else if(j == 1 && s[i] == 'n') g = 2;
        else if(j == 2 && s[i] == 'e') g = -1;
        else if(s[i] == 't') g = 3;
        else if(j == 3 && s[i] == 'w') g = 4;
        else if(j == 4 && s[i] == 'o') g = -1;
        if(~g) {
          if(dp[i+1][g] < dp[i][j]) {
            dp[i][j] = dp[i+1][g];
            go[i][j] = g;
          }
        }
        // cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << go[i][j] << endl;
      }
    }
    cout << dp[0][0] << '\n';
    int cur = 0;
    for(int i = 0; i < n; i++) {
      if(~go[i][cur]) cur = go[i][cur];
      else cout << i+1 << ' ';
    }
    cout << '\n';
  }
}