/*
 * author:  ADMathNoob
 * created: 06/25/22 07:35:33
 * problem: https://codeforces.com/contest/1696/problem/B
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
    int L = 0;
    while (L < n && a[L] == 0) {
      ++L;
    }
    if (L == n) {
      cout << 0 << '\n';
      continue;
    }
    int R = n - 1;
    while (R >= 0 && a[R] == 0) {
      --R;
    }
    bool ok = true;
    for (int i = L; i <= R; i++) {
      ok &= (a[i] > 0);
    }
    cout << (ok ? 1 : 2) << '\n';
  }
  return 0;
}