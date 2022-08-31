#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

#line 2 "graph/tree/centroid-decomposition.hpp"

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
#line 4 "graph/tree/centroid-decomposition.hpp"

/**
 * @brief Centroid-Decomosition()
 */
template< typename T >
struct CentroidDecomposition : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  Graph< int > tree;

  int build(int t = 0) {
    sub.assign(g.size(), 0);
    v.assign(g.size(), 0);
    tree = Graph< int >(g.size());
    return build_dfs(0);
  }

  explicit CentroidDecomposition(const Graph< T > &g) : Graph< T >(g) {}

private:
  vector< int > sub;
  vector< int > v;

  inline int build_dfs(int idx, int par) {
    sub[idx] = 1;
    for(auto &to: g[idx]) {
      if(to == par || v[to]) continue;
      sub[idx] += build_dfs(to, idx);
    }
    return sub[idx];
  }

  inline int search_centroid(int idx, int par, const int mid) {
    for(auto &to: g[idx]) {
      if(to == par || v[to]) continue;
      if(sub[to] > mid) return search_centroid(to, idx, mid);
    }
    return idx;
  }

  inline int build_dfs(int idx) {
    int centroid = search_centroid(idx, -1, build_dfs(idx, -1) / 2);
    v[centroid] = true;
    for(auto &to: g[centroid]) {
      if(!v[to]) tree.add_directed_edge(centroid, build_dfs(to));
    }
    v[centroid] = false;
    return centroid;
  }
};

int main() {
  int N;
  cin >> N;
  CentroidDecomposition< int > g(N);
  g.read(N - 1, -1, true);
  int64 ret = 0;
  vector< int > used(N), alive(N + 1), none(N + 1), dp(N + 1), t(N + 1, -1);
  int ptr = 0;
  int64 all_pad = 0;
  vector< tuple< int, int, int, int > > st;
  vector< pair< int, int > > ts;
  vector< pair< int, int > > add_pend;
  auto calc = MFP([&](auto calc, int idx_, int par_, int cost_) { // 1
    st.emplace_back(idx_, par_, cost_, 0);
    dp[par_] = 0;
    while(not st.empty()) {
      auto[idx, par, cost, type] = st.back();
      if(type == 0) {
        ++alive[cost];
        dp[idx] = 1;
        get< 3 >(st.back()) = 1;
        for(auto &to: g[idx]) {
          if(used[to] or to == par) continue;
          st.emplace_back(to, idx, to.cost, 0);
        }
      } else {
        --alive[cost];
        if(alive[cost] == 1) {
          if(t[cost] != ptr) {
            t[cost] = ptr;
            none[cost] = 0;
          }
          ret -= 1LL * dp[idx] * (none[cost] + all_pad);
        } else if(alive[cost] == 0) {
          if(t[cost] != ptr) {
            t[cost] = ptr;
            none[cost] = 0;
          }
          ret += 1LL * dp[idx] * (none[cost] + all_pad);
          add_pend.emplace_back(cost, dp[idx]);
        }
        st.pop_back();
        dp[par] += dp[idx];
      }
    }
    return dp[par_];
  });
  queue< int > que;
  que.emplace(g.build());
  while(not que.empty()) {
    auto idx = que.front();
    que.pop();
    used[idx] = 1;
    all_pad = 1;
    for(auto &to: g[idx]) {
      if(used[to]) continue;
      all_pad += calc(to, idx, to.cost);
      for(auto&[x, y]: add_pend) none[x] -= y;
      add_pend.clear();
    }
    all_pad = 0;
    ++ptr;
    for(int $ = (int) g[idx].size() - 1; $ >= 0; $--) {
      auto &to = g[idx][$];
      if(used[to]) continue;
      all_pad += calc(to, idx, to.cost);
      for(auto&[x, y]: add_pend) none[x] -= y;
      add_pend.clear();
    }
    ++ptr;
    for(auto &to: g.tree[idx]) que.emplace(to);
  }
  cout << ret << "\n";
}