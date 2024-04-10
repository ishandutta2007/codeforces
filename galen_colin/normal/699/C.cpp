#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n, dp[101][5], a[101];
//rest, contest, sport
int main() {
  io;
  cin >> n;
  ms(dp, 0);
  f0r(i, n) cin >> a[i];
  f1r(i, 1, n + 1) {
    if (a[i-1] == 0) {
      //neither
      f0r(j, 3) dp[i][j] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    } else if (a[i-1] == 1) {
      //contest    
      dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    } else if (a[i-1] == 2) {
      dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
      dp[i][1] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    } else {
      dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }
  }

  // f0r(i, 3) {
  //   f0r(j, n+1) cout << dp[j][i] << " ";
  //   cout << endl;
  // }

  cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}