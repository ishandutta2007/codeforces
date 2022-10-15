// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> link;
  DSU(int n) {
    link.resize(n);
    iota(link.begin(), link.end(), 0);
  }
  int get(int v) {
    return link[v] = (v == link[v] ? v : get(link[v])); 
  }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) {
      return false;
    }
    link[y] = x;
    return true;
  }
};

const int inf = int(1e9);
struct fenwick {
  vector<int> mn;
  int n;
  fenwick(int _n) : n(_n) {
    mn.resize(n + 1, inf);
  }
  int get(int x) {
    x += 1;
    int res = inf;
    while (x > 0) {
      res = min(res, mn[x]);
      x -= x & -x;
    }
    return res;
  }
  void modify(int x, int v) {
    x += 1;
    while (x <= n) {
      mn[x] = min(mn[x], v);
      x += x & -x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<array<int, 2>>> upd(N);
    vector<map<int, int>> start(N);
    vector<map<int, int>> end(N);
    for (int i = 0; i < N; ++i) {
      start[i][i] = end[i][i] = i;
    }
    DSU d(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      X = d.get(X), Y = d.get(Y);
      if (int(start[X].size()) < int(start[Y].size())) {
        swap(X, Y);
      }
      if (X == Y) {
        continue;
      }
      debug(start[X], start[Y]);
      for (auto[l, r] : start[Y]) {
        int new_l = l;
        if (end[X].count(l - 1)) {
          new_l = end[X][l - 1];
          end[X].erase(l - 1);
        }
        int new_r = r;
        if (start[X].count(r + 1)) {
          new_r = start[X][r + 1];
          start[X].erase(r + 1);
        }
        if (new_l != l || new_r != r) {
          debug(i, new_l, new_r);
          upd[new_r].push_back({new_l, i});
        }
        start[X][new_l] = new_r;
        end[X][new_r] = new_l;
      }
      start[Y].clear(), end[Y].clear();
      assert(d.unite(X, Y));
    }
    debug(upd);

    vector<vector<array<int, 2>>> qs(N);
    for (int i = 0; i < Q; ++i) {
      int L, R;
      cin >> L >> R;
      --L, --R;
      qs[R].push_back({L, i});
    }
    vector<int> ans(Q);
    fenwick fw(N);
    for (int i = N - 1; i >= 0; --i) {
      for (auto[l, id] : upd[i]) {
        fw.modify(l, id);
      }
      for (auto[l, id] : qs[i]) {
        ans[id] = (l == i ? -1 : fw.get(l));
      }
    }  
    for (int i = 0; i < Q; ++i) {
      cout << ans[i] + 1 << " \n"[i == Q - 1];
    }
  }
}