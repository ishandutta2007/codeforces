/*
 * author:  ADMathNoob
 * created: 12/29/21 10:35:11
 * problem: https://codeforces.com/contest/1616/problem/A
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
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[abs(a)] += 1;
    }
    int ans = min(cnt[0], 1);
    for (int x = 1; x <= 100; x++) {
      ans += min(cnt[x], 2);
    }
    cout << ans << '\n';
  }
  return 0;
}