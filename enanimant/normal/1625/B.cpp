/*
 * author:  ADMathNoob
 * created: 01/23/22 14:21:18
 * problem: https://codeforces.com/contest/1625/problem/B
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

const int A = 150000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int>> pos(A);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      if (!pos[a[i]].empty()) {
        ans = max(ans, n - (i - pos[a[i]].back()));
      }
      pos[a[i]].push_back(i);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      pos[a[i]].clear();
    }
  }
  return 0;
}