/*
 * author:  ADMathNoob
 * created: 08/24/21 10:35:15
 * problem: https://codeforces.com/contest/1558/problem/C
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
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      if (a[i] % 2 != i % 2) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    vector<int> ops;
    auto Do = [&](int p) {
      assert(0 <= p && p < n && p % 2 == 0);
      reverse(a.begin(), a.begin() + p + 1);
      ops.push_back(p + 1);
      for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
      }
    };
    while (n > 1) {
      Do(pos[n - 1]);
      Do(pos[n - 2] - 1);
      Do(pos[n - 1] + 2);
      Do(2);
      Do(n - 1);
      n -= 2;
    }
    int cnt = (int) ops.size();
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ops[i];
    }
    cout << '\n';
  }
  return 0;
}