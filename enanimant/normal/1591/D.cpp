/*
 * author:  ADMathNoob
 * created: 12/12/21 10:15:57
 * problem: https://codeforces.com/contest/1591/problem/D
 */

/*
Comments about problem:

Parity of the permutation doesn't change, so just try it?
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
    if (n == 1) {
      cout << "YES" << '\n';
      continue;
    }
    auto as = a;
    sort(as.begin(), as.end());
    as.resize(unique(as.begin(), as.end()) - as.begin());
    if ((int) as.size() < n) {
      cout << "YES" << '\n';
      continue;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
      pos[a[i]] = i;
    }
    auto Do = [&](int i, int j, int k) {
      // pos j goes to pos i
      int t = a[i];
      a[i] = a[j];
      a[j] = a[k];
      a[k] = t;
      for (int x : {i, j, k}) {
        pos[a[x]] = x;
      }
    };
    for (int x = 0; x < n - 2; x++) {
      if (pos[x] != x) {
        int y = x;
        while (y == x || y == pos[x]) {
          ++y;
        }
        Do(x, pos[x], y);
      }
    }
    for (int i = 0; i < n - 2; i++) {
      assert(a[i] == i);
    }
    cout << (a[n - 2] < a[n - 1] ? "YES" : "NO") << '\n';
  }
  return 0;
}