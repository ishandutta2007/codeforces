#include<bits/stdc++.h>

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
#line 1 "structure/union-find/union-find.cpp"

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

#line 3 "graph/tree/offline-lca.hpp"

/**
 * @brief Offline LCA()
 **/
template< typename T >
vector< int > offline_lca(const Graph< T > &g, vector< pair< int, int > > &qs, int root = 0) {
  int n = (int) g.size();
  UnionFind uf(n);
  vector< int > st(n), mark(n), ptr(n), ans(qs.size(), -1);
  int top = 0;
  st[top] = root;
  for(auto&[l, r]: qs) mark[l]++, mark[r]++;
  vector< vector< pair< int, int > > > q(n);
  for(int i = 0; i < n; i++) {
    q[i].reserve(mark[i]);
    mark[i] = -1;
    ptr[i] = (int) g[i].size();
  }
  for(int i = 0; i < qs.size(); i++) {
    q[qs[i].first].emplace_back(qs[i].second, i);
    q[qs[i].second].emplace_back(qs[i].first, i);
  }
  auto run = [&](int u) -> bool {
    while(ptr[u]) {
      int v = g[u][--ptr[u]];
      if(mark[v] == -1) {
        st[++top] = v;
        return true;
      }
    }
    return false;
  };
  while(~top) {
    int u = st[top];
    if(mark[u] == -1) {
      mark[u] = u;
    } else {
      uf.unite(u, g[u][ptr[u]]);
      mark[uf.find(u)] = u;
    }
    if(not run(u)) {
      for(auto&[v, i]: q[u]) {
        if(~mark[v] and ans[i] == -1) {
          ans[i] = mark[uf.find(v)];
        }
      }
      --top;
    }
  }
  return ans;
}

template< typename T = int >
struct MoTree : Graph< T > {
  using Graph< T >::Graph;
  using Graph< T >::g;
  vector< int > in, vs;
  vector< pair< int, int > > qs;

public:

  void add(int l, int r) { /* [l, r) */
    qs.emplace_back(l, r);
  }

private:
  void dfs(int u, int p) {
    in[u] = (int) vs.size();
    vs.emplace_back(u);
    for(auto &v: g[u]) {
      if(v != p) {
        dfs(v, u);
        vs.emplace_back(v);
      }
    }
  }

public:
  template< typename A, typename E, typename O >
  void build(const A &add, const E &erase, const O &out) {
    int n = (int) g.size() * 2 - 1;
    vs.reserve(n);
    in.resize(g.size());
    dfs(0, -1);
    vector< pair< int, int > > lr;
    lr.reserve(qs.size());
    auto lca = offline_lca(*this, qs);
    for(auto&[l, r]: qs) {
      lr.emplace_back(minmax(in[l] + 1, in[r] + 1));
    }
    int q = (int) lr.size();
    int bs = n / min< int >(n, sqrt(q));
    vector< int > ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if(ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    vector< int > flip(g.size());
    auto f = [&](int u) {
      flip[u] ^= 1;
      if(flip[u]) add(u);
      else erase(u);
    };
    for(auto &idx: ord) {
      while(l > lr[idx].first) f(vs[--l]);
      while(r < lr[idx].second) f(vs[r++]);
      while(l < lr[idx].first) f(vs[l++]);
      while(r > lr[idx].second) f(vs[--r]);
      f(lca[idx]);
      out(idx);
      f(lca[idx]);
    }
  }
};

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  for(auto &a: A) cin >> a;
  vector< int > B(N);
  for(auto &b: B) cin >> b;
  auto vs = B;
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  for(auto &b: B) b = lower_bound(begin(vs), end(vs), b) - begin(vs);
  MoTree<> g(N);
  g.read(N - 1);
  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g.add(a, b);
  }
  vector< int > cnt1(100000), cnt2(100000);
  vector< int64 > ans(Q);
  int64 sum = 0;
  auto add = [&](int i) {
    if(A[i] == 0) {
      cnt1[B[i]]++;
      sum += cnt2[B[i]];
    } else {
      cnt2[B[i]]++;
      sum += cnt1[B[i]];
    }
  };
  auto erase = [&](int i) {
    if(A[i] == 0) {
      cnt1[B[i]]--;
      sum -= cnt2[B[i]];
    } else {
      cnt2[B[i]]--;
      sum -= cnt1[B[i]];
    }
  };
  auto out = [&](int q) {
    ans[q] = sum;
  };
  g.build(add, erase, out);
  for(auto &p: ans) cout << p << "\n";
}