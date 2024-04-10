/*
 * author:  ADMathNoob
 * created: 07/30/21 14:56:40
 * problem: https://codeforces.com/contest/1555/problem/A
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
    long long n;
    cin >> n;
    long long ans = 1e18;
    for (int take8 = 0; take8 < 3; take8++) {
      for (int take10 = 0; take10 < 3; take10++) {
        long long res = 20 * take8 + 25 * take10;
        long long have = 8 * take8 + 10 * take10;
        long long need = n - have;
        res += 15 * ((need + 5) / 6);
        ans = min(ans, res);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}