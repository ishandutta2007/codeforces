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

struct Info {
  int64 ret;
  vector< int64 > tap;
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


int main() {
  int N, M;
  cin >> N >> M;
  Graph<> g(N);
  UnionFind uf(N);
  for(int i = 0; i < M; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    --a, --b;
    c = (c == 'R');
    g.add_edge(a, b, c);
    uf.unite(a, b);
  }
  auto &U = g.g;
  vector< int > used(N);
  vector< vector< int > > be(N);
  for(int i = 0; i < N; i++) {
    be[uf.find(i)].emplace_back(i);
  }
  bool a = true, b = true;
  vector< int > latte, malta;
  for(int z = 0; z < 2; z++) {

    for(int i = 0; i < N; i++) {
      if(uf.find(i) != i) continue;
      if(U[i].empty()) continue;
      auto &e = U[i].front();
      int add = inf;
      vector< int > cash;
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          for(auto &t : be[i]) used[t] = -1;
          used[e.from] = j;
          used[e.to] = k;
          int color = e.cost ^j ^k;
          if(color != z) continue;
          vector< int > need;
          if(j) need.emplace_back(e.from);
          if(k) need.emplace_back(e.to);
          auto dfs = MFP([&](auto dfs, int idx) -> bool {
            for(auto &beet : U[idx]) {
              if(used[beet] != -1) {
                if(color ^ used[idx] ^ used[beet] ^ beet.cost) return false;
              } else {
                used[beet] = color ^ used[idx] ^ beet.cost;
                if(used[beet]) need.emplace_back(beet);
                if(!dfs(beet)) return false;
              }
            }
            return true;
          });
          if(!dfs(e.from)) continue;
          if(!dfs(e.to)) continue;
          if(chmin(add, need.size())) {
            cash = need;
          }
        }
      }
      if(add == inf) {
        (z ? a : b) = false;
      }
      for(auto &p : cash) {
        (z ? latte : malta).emplace_back(p + 1);
      }
    }


  }

  if(a && b) {
    if(latte.size() < malta.size()) cout << latte.size() << endl << latte << endl;
    else cout << malta.size() << endl << malta << endl;
  } else if(a) {
    cout << latte.size() << endl << latte << endl;
  } else if(b) {
    cout << malta.size() << endl << malta << endl;
  } else {
    cout << -1 << endl;
  }
}