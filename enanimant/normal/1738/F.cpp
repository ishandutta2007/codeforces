/*
 * author:  ADMathNoob
 * created: 09/30/22 10:35:14
 * problem: https://codeforces.com/contest/1738/problem/F
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;  // get that inverse Ackermann time complexity
  vector<int> v;   // version
  int comps;
  int ver;

  Dsu(int _n) : n(_n), p(n, -1), sz(n, 1), v(n, 0), comps(n), ver(0) {}

  inline int get(int x) {
    if (v[x] != ver) {
      p[x] = -1;
      sz[x] = 1;
      v[x] = ver;
    }
    return (p[x] == -1 ? x : (p[x] = get(p[x])));
  }

  inline bool same(int x, int y) {
    return (get(x) == get(y));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    --comps;
    return true;
  }

  inline void reset() {
    comps = n;
    ++ver;
  }
};

int Ask(int u) {
  cout << "? " << u + 1 << endl;
  int v;
  cin >> v;
  --v;
  return v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      cin >> deg[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int u, int v) {
      return deg[u] > deg[v];
    });
    vector<bool> seen(n, false);
    Dsu d(n);
    for (int v : order) {
      if (seen[v]) {
        continue;
      }
      seen[v] = true;
      for (int it = 0; it < deg[v]; it++) {
        int u = Ask(v);
        d.unite(v, u);
        if (seen[u]) {
          break;
        } else {
          seen[u] = true;
        }
      }
    }
    cout << '!';
    for (int i = 0; i < n; i++) {
      cout << ' ' << d.get(i) + 1;
    }
    cout << endl;
  }
  return 0;
}