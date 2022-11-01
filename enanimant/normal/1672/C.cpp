/*
 * author:  ADMathNoob
 * created: 04/23/22 10:05:28
 * problem: https://codeforces.com/contest/1672/problem/C
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
    while (L + 1 < n && a[L] != a[L + 1]) {
      ++L;
    }
    if (L == n - 1) {
      cout << 0 << '\n';
      continue;
    }
    int R = n - 1;
    while (R - 1 >= L && a[R] != a[R - 1]) {
      --R;
    }
    int len = R - L + 1;
    if (len <= 3) {
      cout << len - 2 << '\n';
    } else {
      cout << len - 3 << '\n';
    }
  }
  return 0;
}