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
  for(T &in : v) is >> in;
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
  for(auto &e : t) fill_v(e, v);
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
};

template< typename T = int >
using Edges = vector< Edge< T > >;


/**
 * @brief Convert-Rooted-Tree()
 */
template< typename T >
Graph< T > convert_rooted_tree(const Graph< T > &g, int r = 0) {
  int N = (int) g.size();
  Graph< T > rg(N);
  vector< int > v(N);
  v[r] = 1;
  queue< int > que;
  que.emplace(r);
  while(!que.empty()) {
    auto p = que.front();
    que.pop();
    for(auto &to : g.g[p]) {
      if(v[to] == 0) {
        v[to] = 1;
        que.emplace(to);
        rg.add_directed_edge(p, to, to.cost);
      }
    }
  }
  return rg;
}


template< typename T >
struct DisjointSetUnionOnTree : Graph< T > {
  using F = function< void(int) >;
  using Graph< T >::g;
  vector< int > heavy, sz, in, out, ord;
  const F expand, shrink, query;

  explicit DisjointSetUnionOnTree(int n, F expand, F shrink, F query)
      : Graph< T >(n), expand(move(expand)), shrink(move(shrink)), query(move(query)) {}

private:
  queue< int > que;

  int build_subtree(int idx) {
    in[idx] = ord.size();
    ord.emplace_back(idx);
    for(auto &to : g[idx]) {
      int sub = build_subtree(to);
      sz[idx] += sub;
      if(heavy[idx] == -1 || sz[heavy[idx]] < sub) {
        heavy[idx] = to;
      }
    }
    out[idx] = ord.size();
    return sz[idx];
  }

  void dfs(int idx, bool keep) {
    for(auto &to : g[idx]) {
      if(heavy[idx] == to) continue;
      dfs(to, false);
    }
    if(heavy[idx] != -1) {
      dfs(heavy[idx], true);
    }
    for(auto &to : g[idx]) {
      if(heavy[idx] == to) continue;
      for(int p = in[to]; p < out[to]; p++) {
        expand(ord[p]);
      }
    }
    expand(idx);
    query(idx);
    if(!keep) {
      for(int p = in[idx]; p < out[idx]; p++) shrink(ord[p]);
    }
  }

public:
  void build(int root = 0) {
    g = convert_rooted_tree(*this, root).g;
    sz.assign(g.size(), 1);
    heavy.assign(g.size(), -1);
    in.resize(g.size());
    out.resize(g.size());
    build_subtree(root);
    dfs(root, false);
  }
};

int main() {
  int N;
  cin >> N;
  vector< int > C(N);
  cin >> C;

  vector< int64 > sum(202020), appear(202020);
  vector< int64 > last{0};
  auto expand = [&](int idx) {
    appear[sum[C[idx]]] -= C[idx];
    sum[C[idx]]++;
    last.emplace_back(max(last.back(), sum[C[idx]]));
    appear[sum[C[idx]]] += C[idx];
  };
  auto shrink = [&](int idx) {
    appear[sum[C[idx]]] -= C[idx];
    sum[C[idx]]--;
    last.pop_back();
    appear[sum[C[idx]]] += C[idx];
  };
  vector< int64 > ans(N);
  auto query = [&](int idx) {
    ans[idx] = appear[last.back()];
  };
  DisjointSetUnionOnTree< int > g(N, expand, shrink, query);
  g.read(N - 1);
  g.build();
  cout << ans << "\n";
}