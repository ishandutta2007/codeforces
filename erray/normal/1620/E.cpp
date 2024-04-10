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
  int Q;
  cin >> Q;
  int MAX = int(5e5);
  vector<int> next(Q);
  vector<int> first(MAX);
  iota(first.begin(), first.end(), Q);
  int pos = 0;
  for (int i = 0; i < Q; ++i) {
    int T;
    cin >> T;
    if (T == 1) {
      int X;
      cin >> X;
      --X;
      if (first[X] != Q + X) {
        next[first[X]] = pos;
      }
      first[X] = pos;
      next[pos] = Q + X;
      pos += 1;
    } else {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      if (X == Y) {
        continue;
      }
      if (first[X] != Q + X) {
        next[first[X]] = first[Y];
        if (first[Y] == Q + Y) {
          first[Y] = first[X];
        }
        first[X] = Q + X;
      }
    }
  }

  DSU d(MAX + Q);
  for (int i = 0; i < pos; ++i) {
    d.unite(next[i], i);
  }
  for (int i = 0; i < pos; ++i) {
    cout << d.get(i) + 1 - Q << '\n';
  }

}