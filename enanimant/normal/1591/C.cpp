/*
 * author:  ADMathNoob
 * created: 12/12/21 10:15:56
 * problem: https://codeforces.com/contest/1591/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = 0;
    long long sum = 0;
    for (int i = 0; i < n; i += k) {
      if (a[i] >= 0) {
        break;
      }
      mx = max(mx, abs(a[i]));
      sum += abs(a[i]);
    }
    for (int i = n - 1; i >= 0; i -= k) {
      if (a[i] <= 0) {
        break;
      }
      mx = max(mx, abs(a[i]));
      sum += abs(a[i]);
    }
    cout << 2 * sum - mx << '\n';
  }
  return 0;
}