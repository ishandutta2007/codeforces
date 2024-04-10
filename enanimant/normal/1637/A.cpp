/*
 * author:  ADMathNoob
 * created: 02/12/22 09:35:05
 * problem: https://codeforces.com/contest/1637/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "NO" : "YES") << '\n';
  }
  return 0;
}