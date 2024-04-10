// April 2, 2020
// https://codeforces.com/problemset/problem/505/C

/*
For all jump lengths L that can be made, abs(d - L) <= 2 * sqrt(n). This is
because any multiset of integers summing to n contains at most O(sqrt(n))
distinct integers.
*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int n = 30001;
const int S = 250; // shift, i.e. maximum value of abs(d - L) mentioned above

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int g, d;
  cin >> g >> d;
  vector<int> gems(n, 0);
  for (int i = 0; i < g; i++) {
    int p;
    cin >> p;
    gems[p]++;
  }
  vector<vector<int>> dp(n, vector<int>(2 * S, -INF));
  dp[d][S] = gems[d];
  int ans = dp[d][S];
  for (int i = d + 1; i < n; i++) {
    for (int j = 0; j < 2 * S; j++) {
      int l = d + j - S; // jump length
      if (l <= 0 || l > i) {
        continue;
      }
      for (int k = -1; k <= 1; k++) {
        if (0 <= j + k && j + k < 2 * S) {
          dp[i][j] = max(dp[i][j], dp[i - l][j + k]);
        }
      }
      dp[i][j] += gems[i];
      if (i < 30) {
        cerr << dp[i][j] << ' ';
      }
      ans = max(ans, dp[i][j]);
    }
    cerr << '\n';
  }
  cout << ans << '\n';


  return 0;
}