/*
 * author:  ADMathNoob
 * created: 08/09/21 10:35:21
 * problem: https://codeforces.com/contest/1557/problem/B
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
    vector<int> as = a;
    sort(as.begin(), as.end());
    for (int i = 0; i < n; i++) {
      a[i] = (int) (lower_bound(as.begin(), as.end(), a[i]) - as.begin());
    }
    int need = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] != a[i] + 1) {
        need += 1;
      }
    }
    cout << (need <= k ? "Yes" : "No") << '\n';
  }
  return 0;
}