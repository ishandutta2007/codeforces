/*
 * author:  ADMathNoob
 * created: 01/23/22 14:21:17
 * problem: https://codeforces.com/contest/1625/problem/A
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
    int n, L;
    cin >> n >> L;
    vector<vector<int>> cnt(L, vector<int>(2, 0));
    for (int it = 0; it < n; it++) {
      int x;
      cin >> x;
      for (int j = 0; j < L; j++) {
        cnt[j][(x >> j) & 1] += 1;
      }
    }
    int ans = 0;
    for (int j = 0; j < L; j++) {
      if (cnt[j][1] > cnt[j][0]) {
        ans |= (1 << j);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}