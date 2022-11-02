/*
 * author:  ADMathNoob
 * created: 12/18/21 10:35:18
 * problem: https://codeforces.com/contest/1620/problem/B
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
    int X, Y;
    cin >> X >> Y;
    auto Get = [&] {
      int k;
      cin >> k;
      int mn;
      cin >> mn;
      for (int it = 0; it < k - 2; it++) {
        int foo;
        cin >> foo;
      }
      int mx;
      cin >> mx;
      return mx - mn;
    };
    long long bot = Get();
    long long top = Get();
    long long left = Get();
    long long right = Get();
    long long ans = max(max(bot, top) * Y, max(left, right) * X);
    cout << ans << '\n';
  }
  return 0;
}