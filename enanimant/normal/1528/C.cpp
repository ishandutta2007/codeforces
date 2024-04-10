/*
 * author:  ADMathNoob
 * created: 05/24/21 10:34:36
 * problem: https://codeforces.com/contest/1528/problem/C
 */

/*
g++ 1528C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1528C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<vector<int>> g(n);
    vector<int> p1(n);
    for (int i = 1; i < n; i++) {
      cin >> p1[i];
      --p1[i];
      g[p1[i]].push_back(i);
    }
    vector<vector<int>> h(n);
    vector<int> p2(n);
    for (int i = 1; i < n; i++) {
      cin >> p2[i];
      --p2[i];
      h[p2[i]].push_back(i);
    }
    vector<int> L(n), R(n);
    int T;
    function<void(int)> DfsH = [&](int v) {
      L[v] = T++;
      for (int u : h[v]) {
        DfsH(u);
      }
      R[v] = T - 1;
    };
    DfsH(0);
    int ans = 0;
    set<pair<int, int>> s;
    auto HasInside = [&](pair<int, int> p) -> bool {
      auto it = s.lower_bound({p.first, -1});
      return (it != s.end() && it->second <= p.second);
    };
    function<void(int)> DfsG = [&](int v) {
      pair<int, int> p = {L[v], R[v]};
      bool added = false;
      pair<int, int> q;
      bool removed = false;
      if (!HasInside(p)) {
        auto it = s.upper_bound(p);
        if (it != s.begin()) {
          --it;
          assert(it->first <= L[v]);
          if (it->second >= R[v]) {
            q = *it;
            // p is inside q
            s.erase(it);
            removed = true;
          }
        }
        s.insert(p);
        added = true;
      }
      ans = max(ans, (int) s.size());
      for (int u : g[v]) {
        DfsG(u);
      }
      // revert
      if (added) {
        s.erase(p);
      }
      if (removed) {
        s.insert(q);
      }
    };
    DfsG(0);
    cout << ans << '\n';
  }
  return 0;
}