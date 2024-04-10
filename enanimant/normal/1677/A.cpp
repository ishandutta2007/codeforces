/*
 * author:  ADMathNoob
 * created: 05/08/22 07:35:57
 * problem: https://codeforces.com/contest/1677/problem/A
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<vector<int>> cntL(n + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
      cntL[i + 1] = cntL[i];
      for (int x = p[i] + 1; x < n; x++) {
        cntL[i + 1][x] += 1;
      }
    }
    vector<vector<int>> cntR(n + 1, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      cntR[i] = cntR[i + 1];
      for (int x = p[i] + 1; x < n; x++) {
        cntR[i][x] += 1;
      }
    }
    // debug(cntL);
    // debug(cntR);
    long long ans = 0;
    for (int b = 0; b < n; b++) {
      for (int c = b + 1; c < n; c++) {
        int L = cntL[b][p[c]];
        int R = cntR[c + 1][p[b]];
        ans += (long long) L * R;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}