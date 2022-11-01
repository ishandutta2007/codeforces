/*
 * author:  ADMathNoob
 * created: 04/23/22 10:05:28
 * problem: https://codeforces.com/contest/1672/problem/A
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt += x - 1;
    }
    if (cnt % 2 == 0) {
      cout << "maomao90" << '\n';
    } else {
      cout << "errorgorn" << '\n';
    }
  }
  return 0;
}