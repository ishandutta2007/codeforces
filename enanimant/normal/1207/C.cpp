// August 22, 2019
// https://codeforces.com/contest/1207/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const long long INF = 1e18;
const int N = 200005;


int n;
long long a, b;
int s[N];
long long dp[N][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      s[i] = c - '0';
      dp[i][0] = dp[i][1] = INF;
    }
    dp[0][0] = b;
    dp[0][1] = INF;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 0 && s[i + 1] == 0) {
        dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
      }
      dp[i][1] = min(dp[i - 1][1] + a + 2 * b, dp[i - 1][0] + 2 * a + 2 * b);
    }
    cout << dp[n][0] << '\n';
  }


  return 0;
}