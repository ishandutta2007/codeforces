#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);

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
 //   if(data[x] > data[y]) swap(x, y);
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
  int N, M, C, Q;
  cin >> N >> M >> C >> Q;
  UnionFind uf(1010101);
  map< int, int > belong[1010101];
  set< int > uku[1010101];
  for(int i = 0; i < N; i++) uku[i].emplace(i);
  int ptr = N;
  auto push = [&](int u, int v) {
    u = uf.find(u);
    v = uf.find(v);
    if(u == v) return;
    if(uku[u].size() > uku[v].size()) {
      uku[v].swap(uku[u]);
    }
    for(auto &p : uku[u]) uku[v].emplace(p);
    uku[u].clear();
    uf.unite(v, u);
  };
  for(int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y, --z;
    if(!belong[x].count(z)) belong[x][z] = ptr++;
    if(!belong[y].count(z)) belong[y][z] = ptr++;
    uku[uf.find(x)].emplace(y);
    uku[uf.find(y)].emplace(x);
    push(x, belong[y][z]);
    push(y, belong[x][z]);
  }
  while(Q--) {
    char t;
    cin >> t;
    if(t == '+') {
      int x, y, z;
      cin >> x >> y >> z;
      --x, --y, --z;
      if(!belong[x].count(z)) belong[x][z] = ptr++;
      if(!belong[y].count(z)) belong[y][z] = ptr++;
      uku[uf.find(x)].emplace(y);
      uku[uf.find(y)].emplace(x);
      push(x, belong[y][z]);
      push(y, belong[x][z]);
    } else {
      int x, y;
      cin >> x >> y;
      --x, --y;
      x = uf.find(x);
      if(uku[x].count(y)) cout << "Yes\n";
      else cout << "No\n";
    }
  }
}