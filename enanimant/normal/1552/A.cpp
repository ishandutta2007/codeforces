/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/A
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
    string s;
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (s[i] != t[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}