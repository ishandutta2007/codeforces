/*
 * author:  ADMathNoob
 * created: 12/18/21 10:35:20
 * problem: https://codeforces.com/contest/1620/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int TestCase() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 2e9;
  for (int k1 = 0; k1 <= 5; k1++) {
    for (int k2 = 0; k2 <= 5; k2++) {
      int need3 = 0;
      for (int i = 0; i < n; i++) {
        int best = 2e9;
        for (int t1 = 0; t1 <= k1; t1++) {
          for (int t2 = 0; t2 <= k2; t2++) {
            int rem = a[i] - t1 - 2 * t2;
            if (rem >= 0 && rem % 3 == 0) {
              best = min(best, rem / 3);
            }
          }
        }
        need3 = max(need3, best);
      }
      ans = min(ans, k1 + k2 + need3);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << TestCase() << '\n';
  }
  return 0;
}