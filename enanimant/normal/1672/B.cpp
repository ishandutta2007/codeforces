/*
 * author:  ADMathNoob
 * created: 04/23/22 10:05:28
 * problem: https://codeforces.com/contest/1672/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = [&] {
      if (s[0] == 'B' || s[n - 1] == 'A') {
        return false;
      }
      int p = 0;
      for (int i = 0; i < n; i++) {
        p += (s[i] == 'A' ? +1 : -1);
        if (p < 0) {
          return false;
        }
      }
      return true;
    }();
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}