/*
 * author:  ADMathNoob
 * created: 10/15/22 10:35:11
 * problem: https://codeforces.com/contest/1746/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    cout << (mx == 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}