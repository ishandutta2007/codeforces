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
 * @brief BFS()
 */
template< typename T >
vector< T > bfs(const Graph< T > &g, vector< int > q) {
  T max_cost = 0, beet = 0;
  for(auto &es : g.g) {
    for(auto &e : es) max_cost = max(max_cost, e.cost);
  }
  ++max_cost;
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  vector< queue< int > > ques(max_cost + 1);
  for(auto &p : q) {
    dist[p] = 0;
    ques[0].emplace(p);
  }
  for(T cost = 0; cost <= beet; cost++) {
    auto &que = ques[cost % max_cost];
    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      if(dist[idx] < cost) continue;
      for(auto &e : g.g[idx]) {
        auto next_cost = cost + e.cost;
        if(dist[e.to] <= next_cost) continue;;
        dist[e.to] = next_cost;
        beet = max(beet, dist[e.to]);
        ques[dist[e.to] % max_cost].emplace(e.to);
      }
    }
  }
  return dist;
}

int main() {
  int N, M, K, S;
  cin >> N >> M >> K >> S;
  vector< vector< int > > V(K);
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    --x;
    V[x].emplace_back(i);
  }
  Graph<> g(N);
  g.read(M);
  vector< vector< int > > tap(N);
  for(int i = 0; i < N; i++) {
    tap[i].reserve(K);
  }
  for(int i = 0; i < K; i++) {
    auto d = bfs(g, V[i]);
    for(int j = 0; j < N; j++) {
      if(d[j] >= inf) continue;
      tap[j].emplace_back(d[j]);
    }
  }
  for(int i = 0; i < N; i++) {
    sort(begin(tap[i]), end(tap[i]));
    int ret = 0;
    for(int j = 0; j < S; j++) ret += tap[i][j];
    cout << ret << " ";
  }
  cout << "\n";
}