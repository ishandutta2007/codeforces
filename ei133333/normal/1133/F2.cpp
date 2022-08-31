#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

vector< int > u[200000];
int val[200000];

void dfs(int idx, int par, int child) {
  val[idx] = child;
  int ptr = 0;
  for(auto to : u[idx]) {
    if(to == par) continue;
    dfs(to, idx, (par == -1 ? ptr++ : child));
  }
}

void dfs2(int idx, int par) {
  for(auto to : u[idx]) {
    if(to == par) continue;
    cout << idx + 1 << " " << to + 1 << endl;
    dfs2(to, idx);
  }
}


int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector< int > g[200000];
  vector< pair< int, int > > e;
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    e.emplace_back(x, y);
  }

  int pos = 0;

  if(g[pos].size() < K) {
    cout << "NO" << endl;
    return 0;
  }

  UnionFind uf(N);
  vector< pair< int, int > > edges;
  for(auto &p : g[pos]) {
    uf.unite(pos, p);
    u[pos].emplace_back(p);
  }
  vector< pair< int, int > > uku;
  for(auto &p : e) {
    if(uf.unite(p.first, p.second)) {
      u[p.first].emplace_back(p.second);
      u[p.second].emplace_back(p.first);
    } else {
      uku.emplace_back(p);
    }
  }
  dfs(pos, -1, -1);
  int need = (int) g[pos].size() - K;
  UnionFind uf2(N);
  if(need > 0) {
    for(auto &p : uku) {
      if(p.first == pos || p.second == pos) continue;
      if(uf2.unite(val[p.first], val[p.second])) {
        u[p.first].emplace_back(p.second);
        u[p.second].emplace_back(p.first);
        --need;
        if(need == 0) break;
      }
    }
    if(need > 0) {
      cout << "NO" << endl;
      return 0;
    }
  }


  vector< int > renew;
  for(auto &p : u[pos]) {
    if(uf2.find(val[p]) == val[p]) renew.emplace_back(p);
  }
  u[pos] = renew;


  cout << "YES" << endl;
  dfs2(pos, -1);
}