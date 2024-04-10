/*
 * author:  ADMathNoob
 * created: 07/30/21 14:50:57
 * problem: https://codeforces.com/contest/1555/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s[i] = (int) (c - 'a');
  }
  vector<vector<int>> prefs(6);
  vector<int> p = {0, 1, 2};
  for (int rot = 0; rot < 6; rot++) {
    auto& pref = prefs[rot];
    pref.resize(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + (s[i] != p[i % 3]);
    }
    next_permutation(p.begin(), p.end());
  }
  while (tt--) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    int ans = n;
    for (int r = 0; r < 6; r++) {
      ans = min(ans, prefs[r][R + 1] - prefs[r][L]);
    }
    cout << ans << '\n';
  }
  return 0;
}