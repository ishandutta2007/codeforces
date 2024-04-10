/*
 * author:  ADMathNoob
 * created: 12/24/21 09:35:14
 * problem: https://codeforces.com/contest/1615/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a(n), b(n);
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i = 0; i < n; i++) {
      a[i] = sa[i] - '0';
      b[i] = sb[i] - '0';
      cnt[a[i]][b[i]] += 1;
    }
    int ans = n + 1;
    if (cnt[1][1] == cnt[0][0] + 1) {
      ans = min(ans, cnt[1][1] + cnt[0][0]);
    }
    if (cnt[1][0] == cnt[0][1]) {
      ans = min(ans, cnt[1][0] + cnt[0][1]);
    }
    cout << (ans <= n ? ans : -1) << '\n';
  }
  return 0;
}