/*
 * author:  ADMathNoob
 * created: 10/17/21 07:05:22
 * problem: https://codeforces.com/contest/1586/problem/C
 */

/*
Comments about problem:

All empty have to be exitable.


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> bad(m + 1);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') {
        bad[j] += 1;
      }
    }
  }
  vector<int> pref(m + 1);
  for (int j = 0; j < m; j++) {
    pref[j + 1] = pref[j] + bad[j];
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    int cnt = pref[R + 1] - pref[L + 1];
    if (cnt == 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}