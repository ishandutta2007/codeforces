// April 26, 2020
// https://codeforces.com/contest/1342/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    string t;
    cin >> t;
    int n = (int) t.size();
    bool all_same = true;
    for (int i = 0; i < n; i++) {
      all_same &= (t[i] == t[0]);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (all_same) {
        ans += t[0];
        ans += t[0];
      } else {
        ans += "01";
      }
    }
    cout << ans << '\n';
  }


  return 0;
}