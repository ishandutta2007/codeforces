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
  T coin;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, T coin = 1, int idx = -1) : from(from), to(to), cost(cost), coin(coin), idx(idx) {}

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

  void add_directed_edge(int from, int to, T cost = 1, T coin = 1) {
    g[from].emplace_back(from, to, cost, coin, es++);
  }

  void add_edge(int from, int to, T cost = 1, T coin = 1) {
    g[from].emplace_back(from, to, cost, coin, es);
    g[to].emplace_back(to, from, cost, coin, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1), d = T(1);
      if(weighted) cin >> c >> d;
      if(directed) add_directed_edge(a, b, c, d);
      else add_edge(a, b, c, d);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 N, S;
    cin >> N >> S;
    Graph< int64 > g(N);
    g.read(N - 1, -1, true);
    vector< int > sub(N);
    int64 ret = 0;
    priority_queue< tuple< int64, int64, int64 > > que[2];
    int64 all = 0;
    auto dfs = MFP([&](auto dfs, int idx, int par) -> void {
      sub[idx] = 0;
      int ch = 0;
      for(auto &to : g.g[idx]) {
        if(to != par) {
          dfs(to, idx);
          ++ch;
          sub[idx] += sub[to];
        }
      }
      if(ch == 0) {
        sub[idx] = 1;
      }
      for(auto &to : g.g[idx]) {
        if(to != par) {
          while(to.cost * sub[to] > S) {
            to.cost /= 2;
            ret += to.coin;
          }
          que[to.coin - 1].emplace(to.cost * sub[to] - to.cost / 2 * sub[to], to.cost, sub[to]);
          all += to.cost * sub[to];
        }
      }
    });
    dfs(0, -1);
    vector< int64 > latte, malta;
    while(que[0].size()) {
      int64 cost;
      int64 x, y;
      tie(cost, x, y) = que[0].top();
      que[0].pop();
      x /= 2;
      latte.emplace_back(cost);
      if(x * y - x / 2 * y > 0) {
        que[0].emplace(x * y - x / 2 * y, x, y);
      }
    }
    while(que[1].size()) {
      int64 cost;
      int64 x, y;
      tie(cost, x, y) = que[1].top();
      que[1].pop();
      x /= 2;
      malta.emplace_back(cost);
      if(x * y - x / 2 * y > 0) {
        que[1].emplace(x * y - x / 2 * y, x, y);
      }
    }
    int64 ans = infll;
    int64 more = all - S;
    vector< int64 > d(malta.size() + 1);
    for(int i = 0; i < malta.size(); i++) {
      d[i + 1] = d[i] + malta[i];
    }
    for(int i = 0; i <= latte.size(); i++) {
      int ok = malta.size() + 1, ng = -1;
      while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(d[mid] >= more) ok = mid;
        else ng = mid;
      }
      if(ok <= malta.size()) {
        chmin(ans, ok * 2 + i);
      }
      if(i < latte.size()) {
        more -= latte[i];
      }
    }
    cout << ret + ans << "\n";
  }
}