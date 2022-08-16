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


int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector< int > P(N);
  cin >> P;
  map< int, int > rev;
  for(int i = 0; i < N; i++) {
    rev[P[i]] = i;
  }

  auto dame = []() {
    cout << "NO\n";
    exit(0);
  };

  vector< int > latte(N), malta(N);
  Graph<> g(N);
  vector< int > deg(N);
  for(int i = 0; i < N; i++) {
    latte[i] = rev.count(A - P[i]) ? rev[A - P[i]] : -1;
    malta[i] = rev.count(B - P[i]) ? rev[B - P[i]] : -1;
    if(i <= latte[i]) {
      g.add_edge(i, latte[i], 0);
      deg[i]++;
      deg[latte[i]]++;
    }
    if(i <= malta[i]) {
      g.add_edge(i, malta[i], 1);
      deg[i]++;
      deg[malta[i]]++;
    }
    if(latte[i] == -1 && malta[i] == -1) {
      dame();
    }
  }
  queue< int > que;
  for(int i = 0; i < N; i++) {
    if(deg[i] == 1) {
      que.emplace(i);
    }
  }
  vector< int > matched(N, -1);
  vector< int > type(N, -1);
  while(!que.empty()) {
    int i = que.front();
    que.pop();
    for(auto &e : g.g[i]) {
      --deg[e.to];
      if(deg[e.to] == 1) {
        que.emplace(e.to);
      }
      if(~matched[i] || ~matched[e.to]) continue;
      matched[e.to] = i;
      matched[i] = e.to;
      type[e.to] = e.cost;
      type[i] = e.cost;
      --deg[i];
    }
  }
  for(int i = 0; i < N; i++) {
    if(~matched[i]) continue;
    if(~latte[i] && matched[latte[i]] == -1) {
      matched[latte[i]] = i;
      matched[i] = latte[i];
      type[latte[i]] = 0;
      type[i] = 0;
    }
    if(~malta[i] && matched[malta[i]] == -1) {
      matched[malta[i]] = i;
      matched[i] = malta[i];
      type[malta[i]] = 1;
      type[i] = 1;
    }
  }
  for(int i = 0; i < N; i++) {
    if(matched[i] == -1) dame();
  }
  cout << "YES\n";
  cout << type << "\n";
}