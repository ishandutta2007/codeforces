#include <bits/stdc++.h>

using namespace std;
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

struct Bipartite_Graph : UnionFind {
  vector< int > color;

  Bipartite_Graph(int v) : color(v + v, -1), UnionFind(v + v) {}

  bool bipartite_graph_coloring() {
    for(int i = 0; i < color.size() / 2; i++) {
      int a = find(i);
      int b = find(i + (int) color.size() / 2);
      if(a == b) return (false);
      if(color[a] < 0) color[a] = 0, color[b] = 1;
    }
    return (true);
  }

  bool operator[](int k) {
    return (bool(color[find(k)]));
  }
};


int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, M;
    cin >> N >> M;
    Bipartite_Graph uf(N), uf2(N);
    vector< int > A(M), B(M);
    for(int i = 0; i < M; i++) {
      cin >> A[i] >> B[i];
      --A[i], --B[i];
      if(uf.unite(A[i], B[i])) {
        uf2.unite(A[i], B[i] + N);
        uf2.unite(B[i], A[i] + N);
      }
    }
    uf2.bipartite_graph_coloring();
    vector< int > V(2);
    for(int i = 0; i < N; i++) V[uf2[i]]++;
    vector< int > ans;
    int choose = V[0] < V[1] ? 0 : 1;
    for(int i = 0; i < N; i++) {
      if(uf2[i] == choose) ans.emplace_back(i + 1);
    }
    cout << ans.size() << endl;
    cout << ans << endl;
  }
}