#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 998244353;

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


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) is >> in;
  return is;
}

template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template<typename T = int64>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
  t = v;
}

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
  for (auto &e : t) fill_v(e, v);
}

template<typename F>
struct FixPoint : F {
  FixPoint(F &&f) : F(forward<F>(f)) {}

  template<typename... Args>
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
inline decltype(auto) MFP(F &&f) {
  return FixPoint<F>{forward<F>(f)};
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
  int N;
  cin >> N;
  Graph<> g(N);
  g.read(N - 1);
  int64 best = 1;
  auto dp = make_v< int64 >(N, N);
  fill_v(dp, -1);
  for(int i = 0; i < N; i++) {
    vector< int > sz(N);
    auto dfs = MFP([&](auto dfs, int idx, int par) -> void {
      sz[idx] = 1;
      for(auto to : g.g[idx]) {
        if(to == par) continue;
        dfs(to, idx);
        sz[idx] += sz[to];
      }
    });
    dfs(i, -1);
    auto dfs2 = MFP([&](auto dfs2, int left, int right) -> int64 {
      if(~dp[left][right]) {
        return dp[left][right];
      }
      int64 ret = 0;
      for(auto to : g.g[left]) {
        if (sz[left] > sz[to]) {
          chmax(ret, dfs2(to, right) + (1LL * sz[to] * sz[right]));
        }
      }
      for(auto to : g.g[right]) {
        if(sz[right] > sz[to]) {
          chmax(ret, dfs2(left, to) + (1LL * sz[left] * sz[to]));
        }
      }
      return dp[left][right] = ret;
    });
    for(auto to1 : g.g[i]) {
      for(auto to2 : g.g[i]) {
        if (to1 >= to2) continue;
        chmax(best, dfs2(to1, to2) + max(1LL * sz[to1] * (N - sz[to1]), 1LL * sz[to2] * (N - sz[to2])) + 1LL * sz[to1] * sz[to2]);
      }
    }
  }
  cout << best << endl;
}