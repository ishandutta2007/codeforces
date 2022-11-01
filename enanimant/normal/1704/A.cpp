/*
 * author:  ADMathNoob
 * created: 07/31/22 07:05:04
 * problem: https://codeforces.com/contest/1704/problem/A
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

bool TestCase() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  for (int i = 0; i < m - 1; i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  char mn = '1', mx = '0';
  for (int i = m - 1; i < n; i++) {
    mn = min(mn, s[i]);
    mx = max(mx, s[i]);
  }
  return (mn <= t[m - 1] && t[m - 1] <= mx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << (TestCase() ? "Yes" : "No") << '\n';
  }
  return 0;
}