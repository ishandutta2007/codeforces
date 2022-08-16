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
  int H, W;
  cin >> H >> W;
  auto S = make_v< string >(H);
  cin >> S;
  UnionFind uf(H * W);
  for(int i = 0; i < H; i++) {
    int x = inf, y = -inf;
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        chmin(x, j);
        chmax(y, j);
      }
    }
    for(int j = x + 1; j <= y; j++) {
      uf.unite(i * W + j, i * W + j - 1);
    }
  }
  for(int j = 0; j < W; j++) {
    int x = inf, y = -inf;
    for(int i = 0; i < H; i++) {
      if(S[i][j] == '#') {
        chmin(x, i);
        chmax(y, i);
      }
    }
    for(int i = x + 1; i <= y; i++) {
      uf.unite(i * W + j, i * W + j - W);
    }
  }
  vector< int > active(H * W);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        active[uf.find(i * W + j)] = true;
      }
    }
  }
  int add = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '.') {
        add++;
        if(active[uf.find(i * W + j)]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  if(add == H * W) {
    cout << 0 << endl;
    return 0;
  }
  vector< int > tap(H), ris(W);
  int group = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(active[uf.find(i * W + j)]) {
        tap[i] = true;
        ris[j] = true;
        group += i * W + j == uf.find(i * W + j);
      }
    }
  }
  for(int i = 0; i < H; i++) {
    if(!tap[i]) {
      bool ok = false;
      for(int j = 0; j < W; j++) {
        if(!ris[j]) ok = true;
      }
      if(!ok) {
        cout << -1 << endl;
        exit(0);
      }
    }
  }
  for(int j = 0; j < W; j++) {
    if(!ris[j]) {
      bool ok = false;
      for(int i = 0; i < H; i++) {
        if(!tap[i]) ok = true;
      }
      if(!ok) {
        cout << -1 << endl;
        exit(0);
      }
    }
  }

  cout << group << endl;
}