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
  int idx;

  Edge() = default;

  Edge(int from, int to, int idx = -1) : from(from), to(to), idx(idx) {}

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
    g[from].emplace_back(from, to, es++);
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
 * @brief Topological-Sort()
 */

int deg[50505];
int que[50505];

template< typename T >
bool topological_sort(const Graph< T > &g) {
  const int N = (int) g.size();
  for(int i = 0; i < N; i++) {
    deg[i] = 0;
  }
  for(int i = 0; i < N; i++) {
    for(auto &to : g.g[i]) ++deg[to];
  }
  int f = 0, t = 0;
  for(int i = 0; i < N; i++) {
    if(deg[i] == 0) que[t++] = i;
  }
  int cnt = 0;
  for(; f < t; f++) {
    auto p = que[f];
    ++cnt;
    for(auto &to : g.g[p]) {
      if(--deg[to] == 0) que[t++] = to;
    }
  }
  return cnt == N;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector< int > A(M), B(M);
  Graph<> g(N);
  for(int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
    g.add_directed_edge(A[i], B[i]);
  }
  if(topological_sort(g)) {
    cout << "YES\n";
    return 0;
  }
  vector< int > used, path;
  auto dfs = MFP([&](auto dfs, int idx, int from) -> bool {
    if(used[idx] && from == idx) {
      return true;
    }
    if(used[idx]) return false;
    used[idx] = true;
    for(auto &e : g.g[idx]) {
      if(dfs(e.to, from)) {
        path.emplace_back(e.idx);
        return true;
      }
    }
    return false;
  });
  for(int i = 0; i < N; i++) {
    used.assign(N, false);
    if(dfs(i, i)) {
      for(auto &p : path) {
        Graph<> buf(N);
        for(int j = 0; j < M; j++) {
          if(p == j) continue;
          buf.add_directed_edge(A[j], B[j]);
        }
        if(topological_sort(buf)) {
          cout << "YES\n";
          return 0;
        }
      }
      cout << "NO\n";
      return 0;
    }
  }

}