// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

struct fenwick {
  int n;
  vector<int> tree;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }

  void modify(int x, int y) {
    x += 1;
    while (x <= n) {
      tree[x] += y;
      x += x & -x;
    }
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }

  int find_first(int x) {
    int p = 0;
    int sum = 0;
    for (int i = (1 << __lg(n)); i > 0; i >>= 1) {
      debug(p + i);
      if (p + i <= n && sum + tree[p + i] < x) {
        p += i;
        sum += tree[p];
      }
    }
    debug(p);
    return (p == n ? -1 : p);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, Q;
    cin >> N >> Q; 
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    vector<int> P(N, -1);
    for (int i = 1; i < N; ++i) {
      cin >> P[i];
      --P[i];
    }

    vector<vector<array<int, 3>>> qs(N);
    for (int i = 0; i < Q; ++i) {
      int V, L, K;
      cin >> V >> L >> K;
      --V;
      qs[V].push_back({L, K, i});
    }

    vector<vector<int>> g(N);
    for (int i = 1; i < N; ++i) {
      g[P[i]].push_back(i);
    }

    vector<int> ans(Q, -2);
    vector<int> ct(N);
    vector<set<int>> occ(N + 1);
    for (int i = 0; i < N; ++i) {
      occ[0].insert(i);
    }
    fenwick fenw(N + 1);
    fenw.modify(0, +N);

    debug(qs, g, occ);
    function<void(int)> Dfs = [&](int v) {
      debug(v);
      int c = A[v];
      auto Delt = [&](int x) {
        fenw.modify(ct[c], -1);
        occ[ct[c]].erase(c);
        ct[c] += x;
        fenw.modify(ct[c], +1);
        occ[ct[c]].insert(c);
      };
      Delt(+1);
      for (auto u : g[v]) {
        Dfs(u);
      }
      for (auto[l, k, id] : qs[v]) {
        debug(l, k, id);
        int dec = fenw.get(l - 1);
        debug(dec);
        int cnt = fenw.find_first(dec + k);
        debug(cnt);
        if (cnt != -1) {
          ans[id] = (*occ[cnt].begin());
        }
      }
      Delt(-1);
    };
    Dfs(0);
    

    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}