/*
 * author:  ADMathNoob
 * created: 05/08/22 08:05:27
 * problem: https://codeforces.com/contest/1677/problem/B
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
    int n, m;
    cin >> n >> m;
    vector<int> s(n * m);
    vector<int> pref(n * m + 1);
    for (int i = 0; i < n * m; i++) {
      char c;
      cin >> c;
      s[i] = c - '0';
      pref[i + 1] = pref[i] + s[i];
    }
    vector<int> col(n * m);
    {
      int cur = 0;
      vector<bool> good(m, false);
      for (int i = 0; i < n * m; i++) {
        if (s[i] && !good[i % m]) {
          good[i % m] = true;
          cur += 1;
        }
        col[i] = cur;
      }
    }
    // debug(col);
    vector<int> row(n * m);
    {
      vector<int> by_mod(m);
      for (int i = 0; i < n * m; i++) {
        // leftmost on this row is i
        int from = max(i - m + 1, 0);
        // occurs whenever (index = i mod m)
        // starts from index = i
        int sum = pref[i + 1] - pref[from];
        row[i] += (sum > 0);
        if (i + m < n * m) {
          row[i + m] += row[i];
        }
      }
    }
    for (int i = 0; i < n * m; i++) {
      cout << row[i] + col[i] << " \n"[i == n * m - 1];
    }
  }
  return 0;
}