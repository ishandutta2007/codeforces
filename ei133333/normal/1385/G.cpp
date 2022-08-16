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
 * @brief Strongly-Connected-Components()
 */
template< typename T = int >
struct StronglyConnectedComponents : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  vector< int > comp;
  Graph< T > dag;
  vector< vector< int > > group;

  void build() {
    rg = Graph< T >(g.size());
    for(int i = 0; i < g.size(); i++) {
      for(auto &e : g[i]) {
        rg.add_directed_edge(e.to, e.from, e.cost);
      }
    }
    comp.assign(g.size(), -1);
    used.assign(g.size(), 0);
    for(int i = 0; i < g.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;
    dag = Graph< T >(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &e : g[i]) {
        int x = comp[e.from], y = comp[e.to];
        if(x == y) continue;
        dag.add_directed_edge(x, y, e.cost);
      }
    }
    group.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      group[comp[i]].emplace_back(i);
    }
  }

  int operator[](int k) const {
    return comp[k];
  }

private:
  vector< int > order, used;
  Graph< T > rg;

  void dfs(int idx) {
    if(exchange(used[idx], true)) return;
    for(auto &to : g[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(auto &to : rg.g[idx]) rdfs(to, cnt);
  }
};


/**
 * @brief 2-SAT
 */
struct TwoSatisfiability : StronglyConnectedComponents< bool > {
public:
  using StronglyConnectedComponents< bool >::g;
  using StronglyConnectedComponents< bool >::comp;
  using StronglyConnectedComponents< bool >::add_edge;
  size_t sz;

  explicit TwoSatisfiability(size_t v) : sz(v), StronglyConnectedComponents< bool >(v + v) {}

  void add_if(int u, int v) {
    // u -> v <=> !v -> !u
    add_directed_edge(u, v);
    add_directed_edge(rev(v), rev(u));
  }

  void add_or(int u, int v) {
    // u or v <=> !u -> v
    add_if(rev(u), v);
  }

  void add_nand(int u, int v) {
    // u nand v <=> u -> !v
    add_if(u, rev(v));
  }

  void set_true(int u) {
    // u <=> !u -> u
    add_directed_edge(rev(u), u);
  }

  void set_false(int u) {
    // !u <=> u -> !u
    add_directed_edge(u, rev(u));
  }

  inline int rev(int x) {
    if(x >= sz) return x - sz;
    return x + sz;
  }

  vector< int > solve() {
    StronglyConnectedComponents< bool >::build();
    vector< int > ret(sz);
    for(int i = 0; i < sz; i++) {
      if(comp[i] == comp[rev(i)]) return {};
      ret[i] = comp[i] > comp[rev(i)];
    }
    return ret;
  }
};

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

struct BipartiteGraph : UnionFind {
  vector< int > color;

  BipartiteGraph(int v) : color(v + v, -1), UnionFind(v + v) {}

  bool bipartite_graph_coloring() {
    for(int i = 0; i < color.size() / 2; i++) {
      int a = find(i);
      int b = find(i + (int) color.size() / 2);
      if(a == b) return (false);
      if(color[a] < 0) color[a] = 0, color[b] = 1;
    }
    return (true);
  }

  bool operator[](int k) {
    return (bool(color[find(k)]));
  }
};


void solve() {
  int N;
  cin >> N;
  vector< int > A(N), B(N);
  cin >> A >> B;
  TwoSatisfiability sat(N);
  vector< vector< int > > latte(N), malta(N);
  for(auto &p : A) --p;
  for(auto &p : B) --p;
  for(int i = 0; i < N; i++) latte[A[i]].emplace_back(i);
  for(int i = 0; i < N; i++) malta[B[i]].emplace_back(i);
  BipartiteGraph uf(2 * N);
  for(int i = 0; i < N; i++) {
    int z = latte[i].size() + malta[i].size();
    if(z != 2) {
      cout << -1 << "\n";
      return;
    }
    if(latte[i].size() == 2) {
      uf.unite(latte[i][0], latte[i][1] + N);
      uf.unite(latte[i][0] + N, latte[i][1]);
    } else if(malta[i].size() == 2) {
      uf.unite(malta[i][0], malta[i][1] + N);
      uf.unite(malta[i][0] + N, malta[i][1]);
    } else if(latte[i][0] != malta[i][0]) {
      uf.unite(latte[i][0] + N, malta[i][0] + N);
      uf.unite(latte[i][0], malta[i][0]);
    }
  }
  if(uf.bipartite_graph_coloring()) {
    vector< int > cost(2 * N);
    for(int i = 0; i < N; i++) cost[uf.find(i)]++;
    vector< int > f(2 * N, false);
    for(int i = 0; i < N; i++) {
      if(cost[uf.find(i)] < cost[uf.find(i + N)]) {
        f[uf.find(i)] = true;
        f[uf.find(i + N)] = false;
      } else {
        f[uf.find(i)] = false;
        f[uf.find(i + N)] = true;
      }
    }
    vector< int > ans;
    for(int i = 0; i < N; i++) if(f[uf.find(i)]) ans.emplace_back(i + 1);
    cout << ans.size() << "\n";
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}