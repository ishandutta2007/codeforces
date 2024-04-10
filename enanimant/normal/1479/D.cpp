/*
 * author:  ADMathNoob
 * created: 03/23/21 17:41:15
 * problem: https://codeforces.com/contest/1479/problem/D
 */

/*
g++ 1479D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1479D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1479D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


*/

#include "bits/stdc++.h"

using namespace std;

template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  function<bool(int)> ignore;

  Graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)>& f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class Forest : public Graph<T> {
 public:
  using Graph<T>::n;
  using Graph<T>::g;
  using Graph<T>::edges;

  Forest(int _n) : Graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
class DfsForest : public Forest<T> {
 public:
  using Forest<T>::n;
  using Forest<T>::g;
  using Forest<T>::edges;
  using Forest<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pre;
  vector<int> post;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  DfsForest(int _n) : Forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pre = vector<int>(n, -1);
    post = vector<int>(n, -1);
    sz = vector<int>(n, -1);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pre.clear();
    post.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

 private:
  void do_dfs(int v) {
    pre[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    post[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

template <typename T>
class LcaForest : public DfsForest<T> {
  // TODO: for LCA only, use HLD to save memory?
 public:
  using DfsForest<T>::edges;
  using DfsForest<T>::g;
  using DfsForest<T>::n;
  using DfsForest<T>::pv;
  using DfsForest<T>::pre;
  using DfsForest<T>::post;
  using DfsForest<T>::depth;

  int h;
  vector<vector<int>> pr;

  LcaForest(int _n) : DfsForest<T>(_n) {
  }

  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 32 - __builtin_clz(max_depth);
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }

  inline bool anc(int x, int y) {
    return (pre[x] <= pre[y] && post[y] <= post[x]);
  }

  inline int lca(int x, int y) {
    // maybe optimize?
    // if depth[x] > depth[y], swap
    // then go from j = log(depth[x])?
    assert(!pr.empty());
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    for (int j = 31 - __builtin_clz(depth[x]); j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};

namespace persistent_segtree {

// not all of these functions have been tested!!!

struct Node {
  Node* l = NULL;
  Node* r = NULL;
  // declare extra variables:
  unsigned long long x;

  void apply(int from, int to, unsigned long long v) {
    // apply update to this node:
    x ^= v;
  }
};

Node* clone(const Node* const v) {
  if (v == NULL) {
    return NULL;
  }
  Node* u = new Node;
  u->l = v->l;
  u->r = v->r;
  // clone extra values:
  u->x = v->x;
  return u;
}

// having both unite and pull is definitely a bad idea...

Node unite(const Node& a, const Node& b) {
  Node res;
  res.x = a.x ^ b.x;
  return res;
}

void pull(Node* const res, const Node* const a, const Node* const b) {
  // unite nodes a and b to res
  // init from self:
  res->x = 0;
  if (a != NULL) {
    // pull from a:
    res->x ^= a->x;
  }
  if (b != NULL) {
    // pull from b:
    res->x ^= b->x;
  }
}

void pull(Node* const x) {
  pull(x, x->l, x->r);
}

void push(Node* const x, int l, int r) {
}

void build(Node* x, int l, int r) {
  if (l == r) {
    return;
  }
  int y = (l + r) >> 1;
  x->l = new Node;
  x->r = new Node;
  build(x->l, l, y);
  build(x->r, y + 1, r);
  pull(x);
}

template <typename T>
void build(Node* x, int l, int r, const vector<T>& v) {
  if (l == r) {
    x->apply(l, r, v[l]);
    return;
  }
  int y = (l + r) >> 1;
  x->l = new Node;
  x->r = new Node;
  build(x->l, l, y);
  build(x->r, y + 1, r);
  pull(x);
}

Node get(Node* x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return *x;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  Node res{};
  if (rr <= y) {
    res = get(x->l, l, y, ll, rr);
  } else if (ll > y) {
    res = get(x->r, y + 1, r, ll, rr);
  } else {
    res = unite(get(x->l, l, y, ll, rr), get(x->r, y + 1, r, ll, rr));
  }
  pull(x);
  return res;
}

template <typename... T>
void modify(Node* x, int l, int r, int ll, int rr, Node* n, const T&... v) {
  if (ll <= l && r <= rr) {
    n->apply(l, r, v...);
    return;
  }
  int y = (l + r) >> 1;
  push(n, l, r);
  if (ll <= y) {
    n->l = clone(x->l);
    modify(x->l, l, y, ll, rr, n->l, v...);
  }
  if (rr > y) {
    n->r = clone(x->r);
    modify(x->r, y + 1, r, ll, rr, n->r, v...);
  }
  pull(n);
}

int find_first_knowingly(Node* x, int l, int r, const function<bool(const Node* const)>& f) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res;
  if (f(x->l)) {
    res = find_first_knowingly(x->l, l, y, f);
  } else {
    res = find_first_knowingly(x->r, y + 1, r, f);
  }
  pull(x);
  return res;
}

int find_first(Node* x, int l, int r, int ll, int rr, const function<bool(const Node* const)>& f) {
  if (ll <= l && r <= rr) {
    if (f(x)) {
      return find_first_knowingly(x, l, r, f);
    }
    return -1;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res = -1;
  if (ll <= y) {
    res = find_first(x->l, l, y, ll, rr, f);
  }
  if (res == -1 && rr > y) {
    res = find_first(x->r, y + 1, r, ll, rr, f);
  }
  pull(x);
  return res;
}

int find_last_knowingly(Node* x, int l, int r, const function<bool(const Node* const)>& f) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res;
  if (f(x->r)) {
    res = find_last_knowingly(x->r, y + 1, r, f);
  } else {
    res = find_last_knowingly(x->l, l, y, f);
  }
  pull(x);
  return res;
}

int find_last(Node* x, int l, int r, int ll, int rr, const function<bool(const Node* const)>& f) {
  if (ll <= l && r <= rr) {
    if (f(x)) {
      return find_last_knowingly(x, l, r, f);
    }
    return -1;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res = -1;
  if (rr > y) {
    res = find_first(x->r, y + 1, r, ll, rr, f);
  }
  if (res == -1 && ll <= y) {
    res = find_first(x->l, l, y, ll, rr, f);
  }
  pull(x);
  return res;
}

Node* build(int n) {
  Node* root = new Node;
  build(root, 0, n - 1);
  return root;
}

template <typename T>
Node* build(const vector<T>& v) {
  int n = (int) v.size();
  Node* root = new Node;
  build(root, 0, n - 1, v);
  return root;
}

Node get(Node* root, int n, int ll, int rr) {
  assert(0 <= ll && ll <= rr && rr < n);
  return get(root, 0, n - 1, ll, rr);
}

Node get(Node* root, int n, int p) {
  assert(0 <= p && p < n);
  return get(root, 0, n - 1, p, p);
}

template <typename... T>
Node* modify(Node* root, int n, int ll, int rr, const T&... v) {
  assert(0 <= ll && ll <= rr && rr < n);
  Node* new_root = clone(root);
  modify(root, 0, n - 1, ll, rr, new_root, v...);
  return new_root;
}

int find_first(Node* root, int n, int ll, int rr, const function<bool(const Node* const)>& f) {
  assert(0 <= ll && ll <= rr && rr < n);
  return find_first(root, 0, n - 1, ll, rr, f);
}

int find_last(Node* root, int n, int ll, int rr, const function<bool(const Node* const)>& f) {
  assert(0 <= ll && ll <= rr && rr < n);
  return find_first(root, 0, n - 1, ll, rr, f);
}

}  // namespace persistent_segtree

using namespace persistent_segtree;

int SolveKnowingly(Node* n1, Node* n2, int l, int r) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  if (n1->l->x != n2->l->x) {
    return SolveKnowingly(n1->l, n2->l, l, y);
  } else {
    return SolveKnowingly(n1->r, n2->r, y + 1, r);
  }
}

int Solve(Node* n1, Node* n2, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    if (n1->x == n2->x) {
      return -1;
    }
    return SolveKnowingly(n1, n2, l, r);
  }
  int y = (l + r) >> 1;
  int res = -1;
  if (ll <= y) {
    res = Solve(n1->l, n2->l, l, y, ll, rr);
  }
  if (res == -1 && rr > y) {
    res = Solve(n1->r, n2->r, y + 1, r, ll, rr);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int n, tt;
  cin >> n >> tt;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  LcaForest<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g.add(u, v);
  }

  vector<unsigned long long> value(n);
  mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < n; i++) {
    value[i] = rng();
  }

  // g.dfs_all();
  g.dfs(0);
  g.build_lca();
  vector<Node*> roots(n);
  Node* empty = build(n);
  roots[0] = modify(empty, n, c[0], c[0], value[c[0]]);
  for (int z = 1; z < n; z++) {
    int v = g.order[z];
    roots[v] = modify(roots[g.pv[v]], n, c[v], c[v], value[c[v]]);
  }

  while (tt--) {
    int u, v, ll, rr;
    cin >> u >> v >> ll >> rr;
    --u;
    --v;
    --ll;
    --rr;

    int L = g.lca(u, v);
    Node* x = modify(roots[u], n, c[L], c[L], value[c[L]]);
    int ans = Solve(x, roots[v], 0, n - 1, ll, rr);
    cout << (ans != -1 ? ans + 1 : -1) << '\n';
  }

  return 0;
}