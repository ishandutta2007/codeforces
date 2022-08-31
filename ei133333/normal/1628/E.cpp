#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }));
    return ret;
  }
};

#line 2 "graph/tree/pmormq-lowest-common-ancestor.hpp"

#line 2 "graph/graph-template.hpp"

/**
 * @brief Graph Template()
 */
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }

  inline vector< Edge< T > > &operator[](const int &k) {
    return g[k];
  }

  inline const vector< Edge< T > > &operator[](const int &k) const {
    return g[k];
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;
#line 1 "structure/others/sparse-table.cpp"

/**
 * @brief Sparse-Table()
 * @docs docs/sparse-table.md
 */
template< typename T, typename F >
struct SparseTable {
  F f;
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable() = default;

  explicit SparseTable(const vector< T > &v, const F &f) : f(f) {
    const int n = (int) v.size();
    const int b = 32 - __builtin_clz(n);
    st.assign(b, vector< T >(n));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T fold(int l, int r) const {
    int b = lookup[r - l];
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T, typename F >
SparseTable< T, F > get_sparse_table(const vector< T > &v, const F &f) {
  return SparseTable< T, F >(v, f);
}

#line 2 "structure/others/plus-minus-one-rmq.cpp"

/**
 * @brief Plus-Minus-One-RMQ
 **/
template< typename T >
struct PlusMinusOneRMQ {
  using F = function< int(int, int) >;

  int backet;
  vector< T > vs;
  vector< int > bidx, bbit;
  SparseTable< int, F > st;
  vector< vector< vector< int > > > lookup;

  explicit PlusMinusOneRMQ() = default;

  explicit PlusMinusOneRMQ(const vector< T > &vs) : vs(vs) {
    int n = (int) vs.size();
    backet = max(1, (31 - __builtin_clz(n)) / 2);
    int sz = (n + backet - 1) / backet;
    bidx.assign(sz, -1);
    bbit.assign(sz, 0);
    for(int i = 0; i < sz; i++) {
      int l = i * backet;
      int r = min(l + backet, n);
      bidx[i] = l;
      for(int j = l + 1; j < r; j++) {
        if(vs[j] < vs[bidx[i]]) bidx[i] = j;
        if(vs[j - 1] < vs[j]) bbit[i] |= 1 << (j - l - 1);
      }
    }
    F f = [&](int a, int b) { return vs[a] < vs[b] ? a : b; };
    st = get_sparse_table(bidx, f);
    lookup.assign(1 << (backet - 1), vector< vector< int > >(backet, vector< int >(backet + 1)));
    for(int i = 0; i < (1 << (backet - 1)); i++) {
      for(int j = 0; j < backet; j++) {
        int sum = 0, ret = 0, pos = j;
        for(int k = j + 1; k <= backet; k++) {
          lookup[i][j][k] = pos;
          if(i & (1 << (k - 1))) ++sum;
          else --sum;
          if(sum < ret) {
            pos = k;
            ret = sum;
          }
        }
      }
    }
  }

  pair< T, int > fold(int l, int r) const {
    int lb = l / backet;
    int rb = r / backet;
    if(lb == rb) {
      int pos = lb * backet + lookup[bbit[lb]][l % backet][r % backet];
      return {vs[pos], pos};
    }
    int pos = lb * backet + lookup[bbit[lb]][l % backet][backet];
    if(r % backet > 0) {
      int sub = rb * backet + lookup[bbit[rb]][0][r % backet];
      if(vs[sub] < vs[pos]) pos = sub;
    }
    if(lb + 1 == rb) {
      return {vs[pos], pos};
    } else {
      int sub = st.fold(lb + 1, rb);
      if(vs[sub] < vs[pos]) pos = sub;
      return {vs[pos], pos};
    }
  }
};

#line 5 "graph/tree/pmormq-lowest-common-ancestor.hpp"

/**
 * @brief PMORMQ-Lowest-Common-Ancestor()
 * @docs docs/pmormq-lowest-common-ancestor.md
 **/
template< typename T = int >
struct PMORMQLowestCommonAncestor : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  using F = function< int(int, int) >;

  void build(int root = 0) {
    ord.reserve(g.size() * 2 - 1);
    dep.reserve(g.size() * 2 - 1);
    in.resize(g.size());
    dfs(root, -1, 0);
    vector< int > vs(g.size() * 2 - 1);
    iota(begin(vs), end(vs), 0);
    st = PlusMinusOneRMQ< int >(dep);
  }

  int lca(int x, int y) const {
    if(in[x] > in[y]) swap(x, y);
    return ord[st.fold(in[x], in[y] + 1).second];
  }

private:
  vector< int > ord, dep, in;
  PlusMinusOneRMQ< int > st;

  void dfs(int idx, int par, int d) {
    in[idx] = (int) ord.size();
    ord.emplace_back(idx);
    dep.emplace_back(d);
    for(auto &to: g[idx]) {
      if(to != par) {
        dfs(to, idx, d + 1);
        ord.emplace_back(idx);
        dep.emplace_back(d);
      }
    }
  }
};

/**
 * @brief Lazy-Segment-Tree()
 * @docs docs/lazy-segment-tree.md
 */
template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {
private:
  int n{}, sz{}, height{};
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;

  inline void update(int k) {
    data[k] = f(data[2 * k + 0], data[2 * k + 1]);
  }

  inline void all_apply(int k, const OperatorMonoid &x) {
    data[k] = g(data[k], x);
    if(k < sz) lazy[k] = h(lazy[k], x);
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      all_apply(2 * k + 0, lazy[k]);
      all_apply(2 * k + 1, lazy[k]);
      lazy[k] = OM0;
    }
  }

public:
  LazySegmentTree() = default;

  explicit LazySegmentTree(int n, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  explicit LazySegmentTree(const vector< Monoid > &v, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : LazySegmentTree(v.size(), f, g, h, M1, OM0) {
    build(v);
  }

  void build(const vector< Monoid > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) data[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) update(k);
  }

  void set(int k, const Monoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = x;
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  Monoid get(int k) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    return data[k];
  }

  Monoid operator[](int k) {
    return get(k);
  }

  Monoid prod(int l, int r) {
    if(l >= r) return M1;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    Monoid L = M1, R = M1;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, data[l++]);
      if(r & 1) R = f(data[--r], R);
    }
    return f(L, R);
  }

  Monoid all_prod() const {
    return data[1];
  }

  void apply(int k, const OperatorMonoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = g(data[k], x);
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  void apply(int l, int r, const OperatorMonoid &x) {
    if(l >= r) return;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      for(; l < r; l >>= 1, r >>= 1) {
        if(l & 1) all_apply(l++, x);
        if(r & 1) all_apply(--r, x);
      }
      l = l2, r = r2;
    }
    for(int i = 1; i <= height; i++) {
      if(((l >> i) << i) != l) update(l >> i);
      if(((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template< typename C >
  int find_first(int l, const C &check) {
    if(l >= n) return n;
    l += sz;
    for(int i = height; i > 0; i--) propagate(l >> i);
    Monoid sum = M1;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, data[l]))) {
        while(l < sz) {
          propagate(l);
          l <<= 1;
          auto nxt = f(sum, data[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, data[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) {
    if(r <= 0) return -1;
    r += sz;
    for(int i = height; i > 0; i--) propagate((r - 1) >> i);
    Monoid sum = 0;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(data[r], sum))) {
        while(r < sz) {
          propagate(r);
          r = (r << 1) + 1;
          auto nxt = f(data[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(data[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (int N, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{N, f, g, h, M1, OM0};
}

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (const vector< Monoid > &v, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{v, f, g, h, M1, OM0};
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector< tuple< int, int, int > > es;
  for(int i = 1; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    es.emplace_back(w, u, v);
  }
  sort(begin(es), end(es));
  UnionFind uf(N);

  PMORMQLowestCommonAncestor<> g(N);
  vector< int > p(N);
  for(int i = 0; i < N; i++) {
    p[i] = i;
  }
  vector< int > cost(N);
  for(auto&[w, u, v]: es) {
    u = uf.find(u);
    v = uf.find(v);
    uf.unite(u, v);
    int z = (int) g.size();
    g.g.emplace_back();
    cost.emplace_back();
    g.add_edge(z, p[u]);
    g.add_edge(z, p[v]);
    cost[z] = w;
    p[uf.find(u)] = z;
  }
  int root = p[uf.find(0)];
  g.build(root);
  vector< int > rev(N), po(N);
  int ptr = 0;
  auto dfs = MFP([&](auto dfs, int idx, int par) -> void {
    if(idx < N) {
      po[ptr] = idx;
      rev[idx] = ptr++;
    }
    for(auto to: g[idx]) {
      if(to == par) continue;
      dfs(to, idx);
    }
  });
  dfs(root, -1);

  struct Node {
    int ansmin, ansmax;
    int bufmin, bufmax;

    Node() {}

    Node(int a, int b, int c, int d) : ansmin(a), ansmax(b), bufmin(c), bufmax(d) {}
  };
  auto f1 = [](const Node &a, const Node &b) {
    return Node(min(a.ansmin, b.ansmin), max(a.ansmax, b.ansmax), min(a.bufmin, b.bufmin), max(a.bufmax, b.bufmax));
  };
  auto g1 = [](const Node &a, int f) {
    if(f == 0) return Node(inf, -inf, a.bufmin, a.bufmax);
    else return Node(a.bufmin, a.bufmax, a.bufmin, a.bufmax);
  };
  auto h1 = [](int f, int g) {
    if(g == -1) return f;
    else return g;
  };
  vector< Node > seg_array(N);
  for(int i = 0; i < N; i++) seg_array[i] = Node(inf, -inf, rev[i], rev[i]);
  auto seg = get_lazy_segment_tree(seg_array, f1, g1, h1, Node(inf, -inf, inf, -inf), -1);
  while(Q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int l, r;
      cin >> l >> r;
      --l;
      seg.apply(l, r, 1);
    } else if(t == 2) {
      int l, r;
      cin >> l >> r;
      --l;
      seg.apply(l, r, 0);
    } else {
      int x;
      cin >> x;
      --x;
      x = rev[x];
      auto ret = seg.all_prod();
      int l = ret.ansmin;
      int r = ret.ansmax;
      if(l == inf or (l == r and x == l)) {
        cout << "-1\n";
      } else {
        cout << cost[g.lca(po[min(x, l)], po[max(x, r)])] << "\n";
      }
    }
  }
}