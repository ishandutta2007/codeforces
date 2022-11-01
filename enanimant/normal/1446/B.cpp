// November 13, 2020
// https://codeforces.com/contest/1446/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446B.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int INF = (int) 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(n, vector<int>(m, -INF));
  vector<vector<int>> mx(n, vector<int>(m, -INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = 2;
        if (i > 0 && j > 0) {
          dp[i][j] = max(dp[i][j], mx[i - 1][j - 1] + 4 - i - j);
        }
      }
      mx[i][j] = max(mx[i][j], dp[i][j] + i + j);
      if (i > 0) {
        mx[i][j] = max(mx[i][j], mx[i - 1][j]);
      }
      if (j > 0) {
        mx[i][j] = max(mx[i][j], mx[i][j - 1]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';


  return 0;
}