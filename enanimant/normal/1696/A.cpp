/*
 * author:  ADMathNoob
 * created: 06/25/22 07:35:32
 * problem: https://codeforces.com/contest/1696/problem/A
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
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans = max(ans, a[i] | z);
    }
    cout << ans << '\n';
  }
  return 0;
}