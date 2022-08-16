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

#line 1 "structure/union-find/union-find.cpp"

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }));
    return ret;
  }
};

#line 2 "graph/mst/boruvka.hpp"

/**
 * @brief Boruvka()
 * @docs docs/boruvka.md
 */
template< typename T >
struct Boruvka {
private:
  size_t V;
  UnionFind uf;
  const T INF;

public:
  explicit Boruvka(size_t V, T INF = numeric_limits< T >::max()) : V(V), uf(V), INF(INF) {}

  inline int find(int k) {
    return uf.find(k);
  }

  vector< tuple< int, int, int > > es;

  template< typename F >
  T build(const F &update) {
    T ret = T();
    while(uf.size(0) < (int) V) {
      vector< pair< T, int > > v(V, make_pair(INF, -1));
      update(v);
      bool con = false;
      vector< int > mins(V, -1);
      for(int i = 0; i < (int) V; i++) {
        if(v[i].second >= 0) {
          if(mins[uf.find(i)] == -1 or v[i].first < v[mins[uf.find(i)]].first) {
            mins[uf.find(i)] = i;
          }
        }
      }
      for(int j = 0; j < (int) V; j++) {
        if(uf.find(j) != j) {
          continue;
        }
        int i = mins[j];
        if(~i and uf.unite(v[i].second, i)) {
          es.emplace_back(v[i].first, v[i].second, i);
          ret += v[i].first;
          con = true;
        }
      }
      if(!con) return INF;
    }
    return ret;
  }
};

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
  int N, Q, S, D;
  cin >> N >> Q >> S >> D;
  --S;
  vector< int > A(N);
  cin >> A;
  Boruvka< int > mst(N);
  auto f = [&](vector< pair< int, int > > &ret) {
    vector< vector< int > > ev(N);

    vector< int > head(N, -1), tail(N, -1);
    for(int i = 1; i < N; i++) {
      if(mst.find(i - 1) != mst.find(i)) {
        head[i] = i - 1;
      } else {
        head[i] = head[i - 1];
      }
    }
    for(int i = N - 2; i >= 0; i--) {
      if(mst.find(i + 1) != mst.find(i)) {
        tail[i] = i + 1;
      } else {
        tail[i] = tail[i + 1];
      }
    }
    for(int i = 0, j = 0; i < N; i++) {
      while(j < i and A[j] < A[i] - D) {
        ++j;
      }
      if(j > 0) {
        --j;
        if(~head[j] and mst.find(head[j]) != mst.find(i)) {
          int k = head[j];
          chmin(ret[i], make_pair(abs(A[i] - D - A[k]), k));
        }
        if(j < N and mst.find(j) != mst.find(i)) {
          chmin(ret[i], make_pair(abs(A[i] - D - A[j]), j));
        }
        ++j;
      }
      if(j < N) {
        if(~tail[j] and mst.find(tail[j]) != mst.find(i)) {
          int k = tail[j];
          chmin(ret[i], make_pair(abs(A[i] - D - A[k]), k));
        }
        if(j < N and mst.find(j) != mst.find(i)) {
          chmin(ret[i], make_pair(abs(A[i] - D - A[j]), j));
        }
      }
    }
    for(int i = 0, j = 0; i < N; i++) {
      while(j < N and A[j] < A[i] + D) {
        ++j;
      }
      if(j > 0) {
        --j;
        if(~head[j] and mst.find(head[j]) != mst.find(i)) {
          int k = head[j];
          chmin(ret[i], make_pair(abs(A[i] + D - A[k]), k));
        }
        if(j < N and mst.find(j) != mst.find(i)) {
          chmin(ret[i], make_pair(abs(A[i] + D - A[j]), j));
        }
        ++j;
      }
      if(j < N) {
        if(~tail[j] and mst.find(tail[j]) != mst.find(i)) {
          int k = tail[j];
          chmin(ret[i], make_pair(abs(A[i] + D - A[k]), k));
        }
        if(j < N and mst.find(j) != mst.find(i)) {
          chmin(ret[i], make_pair(abs(A[i] + D - A[j]), j));
        }
      }
    }
  };
  mst.build(f);
  auto &es = mst.es;
  Graph<> g(N);
  for(auto&[cost, i, j] : es) {
    g.add_edge(i, j, cost);
  }
  vector< int > costs(N);
  MFP([&](auto rec, int idx, int p, int cost) -> void {
    costs[idx] = cost;
    for(auto &to : g.g[idx]) {
      if(to != p) {
        rec(to, idx, max(to.cost, cost));
      }
    }
  })(S, -1, 0);
  while(Q--) {
    int i, k;
    cin >> i >> k;
    --i;
    if(costs[i] <= k)cout << "Yes\n";
    else cout << "No\n";
  }
}