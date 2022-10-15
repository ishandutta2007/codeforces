// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<bool EDGE = false, class F = function<void(int, int)>>
struct HLD {
  int n;
  vector<vector<int>> g;
  vector<int> d, root, par, ind, end;
  HLD() { }
  HLD(int _n) : n(_n) {
    g.resize(n);
    d.resize(n);
    root.resize(n);
    iota(root.begin(), root.end(), 0);
    ind.resize(n);
    par.resize(n, -1);
    end.resize(n);
  }

  void add_edge(int v, int u) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    g[v].push_back(u);
    g[u].push_back(v);
  }

  void add_edge(vector<vector<int>> _g) {
    for (int i = 0; i < n; ++i) {
      for (auto u : g[i]) {
        add_edge(i, u);
      }
    }
  }

  int dfs(int v) {
    int size = 0;
    int mx = -1;
    for (int i = 0; i < int(g[v].size()); ++i) {
      int u = g[v][i];
      if (u == par[v]) {
        continue;
      }
      d[u] = d[v] + 1;
      par[u] = v;
      int sz = dfs(u);
      size += sz;
      if (sz > mx) {
        swap(g[v][0], g[v][i]);
        mx = sz;
      }
    }
    return size;
  }

  void index(int v, int& t) {
    end[v] = ind[v] = t++;
    bool heavy = true;
    for (auto u : g[v]) {
      if (u == par[v]) {
        continue;
      }
      if (heavy) {
        root[u] = root[v];
        heavy = false;
      }
      index(u, t);
    }
    end[v] = t;
  }

  bool built = false;
  void build() {
    built = true;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (par[i] == -1) {
        dfs(i);
        index(i, t);
      }
    }
  }

  void path(int v, int u, F op) {
    assert(built);
    if (u == -1) {
      u = (EDGE ? par[v] : v);
    }
    assert(v >= 0 && u >= 0 && v < n && u < n);
    while (root[v] != root[u]) {
      if (d[root[v]] < d[root[u]]) {
        swap(v, u);
      }
      op(ind[root[v]], ind[v]);
      v = par[root[v]];
    }
    if (d[v] > d[u]) {
      swap(v, u);
    }
    if (EDGE) {
      if (v != u) {
        op(ind[v] + 1, ind[u]);
      }
    } else {
      op(ind[v], ind[u]);
    }
  }

  void subtree(int v, F op) {
    if (!EDGE) {
      op(ind[v], end[v]);
    } else {
      if (ind[v] != end[v]) {
        op(ind[v] + 1, end[v]);
      }
    }
  }
};
//container should be declared and used apart from HLD struct

array<long long, 2> operator+(array<long long, 2> x, array<long long, 2> y) {
  x[0] += y[0];
  x[1] += y[1];
  return x;
} 

array<long long, 2> operator-(array<long long, 2> x, array<long long, 2> y) {
  x[0] -= y[0];
  x[1] -= y[1];
  return x;
} 
struct SegTree {
  struct node {
    array<array<long long, 2>, 2> val = {};
    bool tag = false;
    array<long long, 2> modify() {
      tag = !tag;
      swap(val[0], val[1]);
      return val[1] - val[0];
    }
  };
  int n;
  vector<node> tree;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }


  node unite(node x, node y) {
    node res;
    for (int i = 0; i < 2; ++i) {
      res.val[i] = x.val[i] + y.val[i];  
    }
    return res;
  }

  #define def int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1);
  void push(int v, int l, int r) {
    if (tree[v].tag) {
      def;
      tree[v + 1].modify();
      tree[rv].modify();
      tree[v].tag = false;    
    }
  }

  array<long long, 2> modify(int v, int l, int r, int ll, int rr) {
    array<long long, 2> res = {};    
    if (l >= ll && rr >= r) {
      res = res + tree[v].modify();
    } else {
      def;
      push(v, l, r);
      if (ll <= mid) {
        res = res + modify(v + 1, l, mid, ll, rr);
      }
      if (rr > mid) {
        res = res + modify(rv, mid + 1, r, ll, rr);
      }
      tree[v] = unite(tree[v + 1], tree[rv]);
    }
    return res;
  }
  //return delta

  void assign(int v, int l, int r, int t, int x) {
    if (l == r) {
      tree[v].val[0] = {x, 1};
      return;
    }
    def;
    if (t <= mid) {
      assign(v + 1, l, mid, t, x);
    } else {
      assign(rv, mid + 1, r, t, x);
    }
  }

  void get(int v, int l, int r, vector<int>& res) {
    if (l == r) {
      if (tree[v].val[1][1]) {
        res.push_back(tree[v].val[1][0]);
      }
      return;
    }  
    def;
    push(v, l, r);
    get(v + 1, l, mid, res);
    get(rv, mid + 1, r, res);
  }

  array<long long, 2> modify(int ll, int rr) {
    assert(ll >= 0 && ll <= rr && rr < n);
    return modify(0, 0, n - 1, ll, rr);
  }

  void assign(int t, int x) {
    assert(t >= 0 && t < n);
    assign(0, 0, n - 1, t, x);
  }

  vector<int> get() {
    vector<int> res;
    get(0, 0, n - 1, res);
    sort(res.begin(), res.end());
    return res;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<array<int, 2>> E(N - 1);
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> E[i][j];
      --E[i][j];
      g[E[i][j]].push_back(i);     
    }
  }

  debug(g);
  SegTree st(N);
  HLD<true> hld(N);
  for (auto[v, u] : E) {
    hld.add_edge(v, u);
  }
  hld.build();
  debug("built");
  for (int i = 0; i < N - 1; ++i) {
    if (hld.par[E[i][0]] != E[i][1]) {
      swap(E[i][0], E[i][1]);
    }
    hld.path(E[i][0], -1, [&](int l, int r) {
      assert(l == r);
      st.assign(l, i + 1);
    });
  }

  int act = 1;
  array<long long, 2> sum = {};
  int t;
  do {
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      --v;
      debug("add", v);
      act += 1;
      hld.path(0, v, [&](int l, int r) {
        sum = sum + st.modify(l, r);
      });
    } 

    if (sum[1] * 2 != act && t != 3) {
      cout << 0 << '\n';
    } else if (t == 1) {
      cout << sum[0] << '\n';
    } else if (t == 2) {
      cout << act / 2 << ' ';
      for (auto e : st.get()) {
        cout << e << ' ';  
      }
      cout << '\n';
    }
    cout << endl;
  } while (t != 3);
}