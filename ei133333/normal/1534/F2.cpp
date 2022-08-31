#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
inline bool chmin(T1 &a, T2 b) {
  if(b < 0)b *= -1;
  return a > b && (a = b, true);
}

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


int main() {
  int H, W;
  cin >> H >> W;
  vector< string > S(H);
  cin >> S;
  vector< int > A(W);
  cin >> A;

  auto last = make_v< int >(H, W);
  for(int j = 0; j < W; j++) {
    int p = -1;
    for(int i = H - 1; i >= 0; i--) {
      if(S[i][j] == '#') {
        p = i;
      }
      last[i][j] = p;
    }
  }

  StronglyConnectedComponents<> scc(H * W);
  const int vy[] = {-1, 0, 1, 0};
  const int vx[] = {0, 1, 0, -1};
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        for(int k = 0; k < 4; k++) {
          int ny = vy[k] + i;
          int nx = vx[k] + j;
          if(ny < 0 || ny >= H || nx < 0 || nx >= W) {
            continue;
          }
          if(~last[ny][nx]) {
            scc.add_directed_edge(i * W + j, last[ny][nx] * W + nx);
          }
        }
      }
    }
  }

  scc.build();
  auto dag = scc.dag;
  int N = (int) dag.size();

  vector< int > left(N, inf), right(N, -inf);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int id = scc[i * W + j];
      chmin(left[id], j);
      chmax(right[id], j);
    }
  }
  for(int from = 0; from < N; from++) {
    for(auto to : dag.g[from]) {
      chmin(left[to], left[from]);
      chmax(right[to], right[from]);
    }
  }
  vector< pair< int, int > > es;
  for(int j = 0; j < W; j++) {
    if(A[j] == 0) {
      continue;
    }
    int num = 0;
    for(int i = H - 1; i >= 0; i--) {
      if(S[i][j] == '#') {
        ++num;
      }
      if(num >= A[j]) {
        int id = scc[i * W + j];
        es.emplace_back(right[id], left[id]);
        break;
      }
    }
  }
  sort(begin(es), end(es));

  int ret = 0, x = -1;
  for(auto &[r, l] : es) {
    if(l > x) {
      x = r;
      ++ret;
    }
  }
  cout << ret << "\n";
}