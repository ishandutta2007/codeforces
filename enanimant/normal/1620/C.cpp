/*
 * author:  ADMathNoob
 * created: 12/18/21 10:35:19
 * problem: https://codeforces.com/contest/1620/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    --x;
    string s;
    cin >> s;
    vector<long long> suf(n + 1);
    suf[n] = 1;
    vector<int> next_a(n);
    int nxt = n;
    for (int i = n - 1; i >= 0; i--) {
      next_a[i] = nxt;
      if (s[i] == 'a') {
        suf[i] = suf[i + 1];
        nxt = i;
      } else {
        int stars = nxt - i;
        if (suf[nxt] > INF / (k * stars + 1)) {
          suf[i] = INF;
        } else {
          suf[i] = suf[nxt] * (k * stars + 1);
        }
      }
    }
    vector<pair<char, int>> ret;
    int at = 0;
    while (at < n) {
      if (s[at] == 'a') {
        ret.emplace_back('a', 1);
        ++at;
        continue;
      }
      int j = next_a[at];
      int cnt = x / suf[j];
      ret.emplace_back('b', cnt);
      x -= cnt * suf[j];
      at = j;
    }
    for (const auto [c, r] : ret) {
      cout << string(r, c);
    }
    cout << '\n';
  }
  return 0;
}