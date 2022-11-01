/*
 * author:  ADMathNoob
 * created: 04/23/22 10:05:29
 * problem: https://codeforces.com/contest/1672/problem/F1
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
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      pos[a[i]].push_back(i);
    }
    set<int> alive;
    for (int x = 0; x < n; x++) {
      if (!pos[x].empty()) {
        alive.insert(x);
      }
    }
    vector<int> res(n, -1);
    while (!alive.empty()) {
      vector<int> ids(alive.begin(), alive.end());
      int len = ids.size();
      for (int z = 0; z < len; z++) {
        int x = ids[z];
        int i = pos[x].back();
        pos[x].pop_back();
        res[i] = ids[(z + 1) % len];
        if (pos[x].empty()) {
          alive.erase(x);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}