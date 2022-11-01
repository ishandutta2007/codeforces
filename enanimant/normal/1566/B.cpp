/*
 * author:  ADMathNoob
 * created: 09/12/21 10:35:16
 * problem: https://codeforces.com/contest/1566/problem/B
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
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = 2;
    if (s.find('0') == string::npos) {
      ans = 0;
    } else {
      int first0 = n;
      int last0 = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          first0 = min(first0, i);
          last0 = i;
        }
      }
      bool all0 = true;
      for (int j = first0; j <= last0; j++) {
        all0 &= (s[j] == '0');
      }
      if (all0) {
        ans = 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}