/*
 * author:  ADMathNoob
 * created: 11/23/21 09:35:10
 * problem: https://codeforces.com/contest/1610/problem/B
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
    int i = 0, j = n - 1;
    bool ok = true;
    while (i < j) {
      if (a[i] != a[j]) {
        ok = false;
        break;
      }
      ++i;
      --j;
    }
    if (ok) {
      cout << "YES" << '\n';
      continue;
    }
    auto Check = [&](int x) {
      int L = 0, R = n - 1;
      while (L < R) {
        if (a[L] == a[R]) {
          ++L;
          --R;
        } else {
          if (a[L] == x) {
            ++L;
          } else if (a[R] == x) {
            --R;
          } else {
            return false;
          }
        }
      }
      return true;
    };
    if (Check(a[i]) || Check(a[j])) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}