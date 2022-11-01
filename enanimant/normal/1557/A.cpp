/*
 * author:  ADMathNoob
 * created: 08/09/21 10:35:16
 * problem: https://codeforces.com/contest/1557/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    long long sum = 0;
    int mx = -2e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
      mx = max(mx, a);
    }
    double ans = mx + (double) (sum - mx) / (n - 1);
    cout.precision(10);
    cout << fixed;
    cout << ans << '\n';
  }
  return 0;
}