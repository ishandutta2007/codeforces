/*
 * author:  ADMathNoob
 * created: 04/19/22 10:35:05
 * problem: https://codeforces.com/contest/1667/problem/A
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 1e18;
  for (int i = 0; i < n; i++) {
    vector<long long> b(n, 0);
    long long res = 0;
    for (int j = i - 1; j >= 0; j--) {
      long long diff = b[j] - b[j + 1] + 1;
      long long cnt = (diff + a[j] - 1) / a[j];
      res += cnt;
      b[j] -= cnt * a[j];
    }
    for (int j = i + 1; j < n; j++) {
      long long diff = b[j - 1] - b[j] + 1;
      long long cnt = (diff + a[j] - 1) / a[j];
      res += cnt;
      b[j] += cnt * a[j];
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
  return 0;
}