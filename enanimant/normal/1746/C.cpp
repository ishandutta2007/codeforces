/*
 * author:  ADMathNoob
 * created: 10/15/22 10:35:11
 * problem: https://codeforces.com/contest/1746/problem/C
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
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
      pos[p[i]] = i;
    }
    for (int x = 0; x < n; x++) {
      int at = pos[x] + 1;
      if (at == n) at = 0;
      cout << at + 1 << " \n"[x == n - 1];
    }
  }
  return 0;
}