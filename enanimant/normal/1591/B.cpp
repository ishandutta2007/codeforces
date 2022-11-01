/*
 * author:  ADMathNoob
 * created: 12/12/21 10:15:55
 * problem: https://codeforces.com/contest/1591/problem/B
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    int last = -1;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > last) {
        last = a[i];
        cnt += 1;
      }
    }
    cout << cnt - 1 << '\n';
  }
  return 0;
}