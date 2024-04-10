/*
 * author:  ADMathNoob
 * created: 01/22/22 09:35:08
 * problem: https://codeforces.com/contest/1628/problem/A
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    int at = 0;
    vector<int> res;
    while (at < n) {
      int b = 0;
      while (cnt[b] > 0) {
        ++b;
      }
      res.push_back(b);
      if (b == 0) {
        ++at;
        continue;
      }
      vector<bool> seen(b, false);
      int cnt_seen = 0;
      while (cnt_seen < b) {
        assert(at < n);
        int x = a[at];
        if (x < b && !seen[x]) {
          seen[x] = true;
          cnt_seen += 1;
        }
        --cnt[x];
        ++at;
      }
    }
    int sz = res.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
      if (i > 0) cout << ' ';
      cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}