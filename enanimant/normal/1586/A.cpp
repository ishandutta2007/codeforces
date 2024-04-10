/*
 * author:  ADMathNoob
 * created: 10/17/21 07:05:20
 * problem: https://codeforces.com/contest/1586/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int M = 100 * 200 + 5;
  vector<bool> p(M, true);
  for (int i = 2; i < M; i++) {
    if (p[i]) {
      for (int j = i * i; j < M; j += i) {
        p[j] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> dp(M, false);
    vector<int> last(M, -1);
    int sum = 0;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      for (int x = sum; x >= a[i]; x--) {
        if (!dp[x] && dp[x - a[i]]) {
          dp[x] = true;
          last[x] = i;
        }
      }
    }
    int k = -1;
    for (int x = sum; x >= 0; x--) {
      if (dp[x] && !p[x]) {
        k = x;
        break;
      }
    }
    // cout << k << '\n';
    vector<int> ids;
    while (k > 0) {
      ids.push_back(last[k]);
      k -= a[last[k]];
    }
    int s = (int) ids.size();
    cout << s << '\n';
    for (int i = 0; i < s; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ids[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}