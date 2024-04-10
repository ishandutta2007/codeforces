/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/D
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
    }
    vector<int> sum(1 << n);
    for (int mm = 0; mm < (1 << n); mm++) {
      for (int j = 0; j < n; j++) {
        if (mm & (1 << j)) {
          sum[mm] += a[j];
        }
      }
    }
    sort(sum.begin(), sum.end());
    sum.resize(unique(sum.begin(), sum.end()) - sum.begin());
    if ((int) sum.size() < (1 << n)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}