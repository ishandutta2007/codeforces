#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

using int64 = long long;
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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
  // +
  // DP
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    UnWeightedGraph g(N);
    for(int i = 1; i < N; i++) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    int ret = 0;
    for(int i = 0; i < N; i++) {
      chmax(ret, g[i].size() + 1);
    }
    auto dp = make_v< int >(N);
    fill_v(dp, -inf);

    auto dfs = MFP([&](auto dfs, int idx, int par) -> void {
      int child = 0;
      for(auto &to  :g[idx]) {
        if(to == par) continue;
        ++child;
        dfs(to, idx);
      }

      // idx-
      dp[idx] = child + 1;


      // -
      for(auto &to : g[idx]) {
        if(to == par) continue;
        chmax(dp[idx], dp[to] + child);
      }

      //-idx
      for(auto &to : g[idx]) {
        if(to == par) continue;
        chmax(ret, (par == -1 ? 0 : 1) + child + dp[to]);
      }

      // -idx-
      if(child >= 2) {
        vector< int > mx;
        for(auto &to : g[idx]) {
          if(to == par) continue;
          mx.emplace_back(dp[to]);
        }
        sort(mx.rbegin(), mx.rend());
        chmax(ret, mx[0] + mx[1] + child - 1 + (par == -1 ? 0 : 1));
      }

    });
    dfs(0, -1);
    cout << ret << endl;
  }
}