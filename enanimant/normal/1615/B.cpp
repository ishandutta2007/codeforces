/*
 * author:  ADMathNoob
 * created: 12/24/21 09:35:13
 * problem: https://codeforces.com/contest/1615/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int N = 200005;
  const int LOG = 20;
  vector<vector<int>> cnt(LOG, vector<int>(N + 1));
  for (int k = 0; k < LOG; k++) {
    for (int i = 0; i < N; i++) {
      cnt[k][i + 1] = cnt[k][i] + ((i >> k) & 1);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int L, R;
    cin >> L >> R;
    int ans = N;
    for (int k = 0; k < LOG; k++) {
      ans = min(ans, (R - L + 1) - (cnt[k][R + 1] - cnt[k][L]));
    }
    cout << ans << '\n';
  }
  return 0;
}