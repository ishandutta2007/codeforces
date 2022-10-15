// author: erray
#undef DEBUG 
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  vector<vector<T>> a;
  vector<int> logs;
  int n;
  F op;
  SparseTable() { }
  SparseTable(vector<T> _a, F _op) : op(_op) {
    n = int(_a.size());
    int lg = 32 - __builtin_clz(n);
    a.resize(lg); 
    a[0] = _a;
    for (int j = 1; j < lg; ++j) {
      int size = n - (1 << j) + 1;
      a[j].resize(size);
      for (int i = 0; i < size; ++i) {
        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);
      }
    }
    logs.resize(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      logs[i] = logs[(i >> 1)] + 1;
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = logs[r - l + 1];;
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};

struct EulerTourLCA {
  int n;
  vector<int> d, tin, tout;
  SparseTable<int> st;
  EulerTourLCA(vector<vector<int>> g, int root = 0) {
    n = int(g.size());
    vector<int> tour;
    d.resize(n);
    tin.resize(n);
    tout.resize(n);
    function<void(int, int)> Dfs = [&](int v, int pr) {
      tin[v] = tout[v] = int(tour.size());
      tour.push_back(v);
      for (auto u : g[v]) {
        if (u == pr) {
          continue;
        }
        d[u] = d[v] + 1;
        Dfs(u, v);
        tout[v] = int(tour.size());
        tour.push_back(v);
      }
    };
    if (root == -1) {
      for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
          Dfs(i, -1);
        }
      }
    } else {
      Dfs(root, -1);
    }  
    debug(tour);
    st = SparseTable<int>(tour, [&](int x, int y) {
      return (d[x] < d[y] ? x : y);
    }); 
  }

  int is_ancestor(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];  
  }

  int lca(int v, int u) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    if (tin[v] > tin[u]) {
      swap(v, u);
    }
    return (is_ancestor(v, u) ? v : st.get(tout[v], tin[u]));
  } 
};

template<typename node, typename F = function<void(node&, node, node)>> 
struct SegTree {
  vector<node> tree;
  F unite;
  int n;
  #define def int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1)

  void push(int v, int l, int r) {
    if (tree[v].tagged) {
      def;
      tree[v + 1].modify(tree[v].tag);
      tree[rv].modify(tree[v].tag);
      tree[v].tagged = false;
    }
  }

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v].lca = tree[v].active = l;
      return;
    }
    def;
    build(v + 1, l, mid);
    build(rv, mid + 1, r);
    unite(tree[v], tree[v + 1], tree[rv]);
    tree[v].active = tree[v].lca;
    //debug(v, l, r, tree[v].active);
  }

  void modify(int v, int l, int r, int ll, int rr, bool act) {
    if (l >= ll && rr >= r) {
      tree[v].modify(act);
      return;
    }
    def;
    push(v, l, r);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, act);
    }
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, act);
    }
    unite(tree[v], tree[v + 1], tree[rv]);
  }

  bool get(int v, int l, int r, int p) {
    if (l == r) {
      return (tree[v].lca != -1);
    }
    def;
    push(v, l, r);
    if (p <= mid) {
      return get(v + 1, l, mid, p);
    } else {
      return get(rv, mid + 1, r, p);
    }
  }

  bool get(int x) {
    return get(0, 0, n - 1, x);
  }

  int get() {
    return tree[0].lca;
  }
  
  void modify(int ll, int rr, bool act) {
    assert(ll >= 0 && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, act);
  }
  
  SegTree(int _n, F _unite) : n(_n), unite(_unite) {
    tree.resize((n << 1) - 1);
    build(0, 0, n - 1);
  }
};

struct ItSegTree {
  vector<array<int, 2>> tree;
  int n;
  ItSegTree(int _n) : n(_n) {
    tree.resize((n << 1));
  }
  
  void modify(int p, int x, int id) {
    assert(p < n && p >= 0);
    p += n;
    tree[p] = {x, id};
    while (p > 0) {
      tree[p >> 1] = max(tree[p], tree[p ^ 1]);
      p >>= 1;
    }  
  }

  array<int, 2> get(int l, int r) {
    array<int, 2> res = {};
    l += n;
    r += n + 1;
    while (l < r) {
      if (l & 1) {
        res = max(res, tree[l]);
        l += 1;
      }
      if (r & 1) {
        r -= 1;
        res = max(res, tree[r]);
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> g(N);
  vector<array<int, 3>> E(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    cin >> E[i][1] >> E[i][2] >> E[i][0];
    --E[i][1], --E[i][2];
    g[E[i][1]].push_back(i);
    g[E[i][2]].push_back(i); 
  }
  vector<int> tin(N), tout(N);
  vector<int> val(N);
  int t = -1;
  vector<int> par(N, -1);
  function<void(int)> Dfs = [&](int v) {
    //debug(v);
    ++t;
    tin[v] = t;
    for (auto id : g[v]) {
      int u = v ^ E[id][1] ^ E[id][2];
      if (u == par[v]) {
        continue;
      }
      par[u] = v;
      val[u] = E[id][0];
      Dfs(u);
    } 
    tout[v] = t;
  };
  Dfs(0);

  /*
  debug(tin);
  debug(tout);
  debug(val);
  debug(par);
  */
  ItSegTree mx(N);
  for (int i = 1; i < N; ++i) {
    mx.modify(tin[i], val[i], i);
  }
  
  vector<vector<int>> stg(N * 2);    
  //cerr << clock() << " ms before recursive" << endl;
  function<int(int, int)> Split = [&](int l, int r) {
    auto[foo, v] = mx.get(l, r);
    mx.modify(tin[v], 0, v);
    if (mx.get(tin[v], tout[v])[0] != 0) {
      stg[v + N].push_back(Split(tin[v], tout[v]));
    } else {
      stg[v + N].push_back(v); 
    }

    if (mx.get(l, r)[0] != 0) {
      stg[v + N].push_back(Split(l, r));
    } else {
      stg[v + N].push_back(par[v]);
    }
    return v + N;
  };
  int root = Split(0, N - 1);
  debug(root);
  debug(stg);
  //cerr << clock() << " ms after recursive" << endl;
  EulerTourLCA et(stg, root);
  debug(et.tin);
  debug(et.tout);
  struct node {
    int lca = -1;
    int active = -1;
    bool tag = false;
    bool tagged = false;
    void modify(bool x) {
      tag = x;
      tagged = true;
      lca = (x ? active : -1);
    }
  }; 

  SegTree<node> st(N, [&](node& res, const node& x, const node& y) {
    res.lca = (x.lca == -1 ? y.lca : (y.lca == -1 ? x.lca : et.lca(x.lca, y.lca)));   
  });
  st.modify(0, N - 1, false);

  //cerr << clock() << " ms precalculate" << endl;
  for (int it = 0; it < Q; ++it) {
    int T;
    cin >> T;
    
    if (T <= 2) {
      int L, R;
      cin >> L >> R;
      --L, --R;
      st.modify(L, R, T == 1);
    } else {
      int V;
      cin >> V;
      --V;
      bool prev = st.get(V);
      st.modify(V, V, true);
      int ans = st.get();
      cout << (ans < N ? -1 : val[ans - N]) << '\n';
      st.modify(V, V, prev);
    }
  }
  cerr << clock() << " ms total" << '\n';   
  assert(clock() <= 2200);
}