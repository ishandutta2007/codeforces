/*
 * author:  ADMathNoob
 * created: 01/03/22 09:35:40
 * problem: https://codeforces.com/contest/1621/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> L(n), R(n), c(n);
    map<pair<int, int>, int> mp;
    map<int, int> mpL, mpR;
    int mn = INF, mx = -1;
    for (int i = 0; i < n; i++) {
      cin >> L[i] >> R[i] >> c[i];
      mn = min(mn, L[i]);
      mx = max(mx, R[i]);
      pair<int, int> p = {L[i], R[i]};
      if (mp.count(p)) {
        mp[p] = min(mp[p], c[i]);
      } else {
        mp[p] = c[i];
      }
      p = {mn, mx};
      if (mpL.count(L[i])) {
        mpL[L[i]] = min(mpL[L[i]], c[i]);
      } else {
        mpL[L[i]] = c[i];
      }
      if (mpR.count(R[i])) {
        mpR[R[i]] = min(mpR[R[i]], c[i]);
      } else {
        mpR[R[i]] = c[i];
      }
      int ans = INF;
      if (mp.count(p)) {
        ans = min(ans, mp[p]);
      }
      ans = min(ans, mpL[mn] + mpR[mx]);
      cout << ans << '\n';
    }
  }
  return 0;
}