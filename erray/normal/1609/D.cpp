// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[get(v)];
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, D;
  cin >> N >> D;
  DSU d(N);
  vector<int> sizes(N, 1);
  int extra = 0;
  for (int i = 0; i < D; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    if (d.same(X, Y)) {
      extra += 1;
    } else {
      sizes.erase(find(sizes.begin(), sizes.end(), d.size(X)));
      sizes.erase(find(sizes.begin(), sizes.end(), d.size(Y)));
      d.unite(X, Y);
      sizes.insert(lower_bound(sizes.begin(), sizes.end(), d.size(X)), d.size(X));
    }

    int ans = 0;
    for (int j = 0; j < min(int(sizes.size()), extra + 1); ++j) {
      ans += sizes[int(sizes.size()) - j - 1];
    }
    cout << ans - 1 << '\n';
  }
}