/*
 * author:  ADMathNoob
 * created: 11/23/21 09:35:11
 * problem: https://codeforces.com/contest/1610/problem/C
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    auto Check = [&](int k) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        if (b[i] >= cur && a[i] >= k - 1 - cur) {
          ++cur;
          if (cur == k) {
            return true;
          }
        }
      }
      return false;
    };
    int low = 0, high = n;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (Check(mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << low << '\n';
  }
  return 0;
}