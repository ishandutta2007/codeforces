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
 
template< int mod >
struct ModInt {
  int x;
 
  ModInt() : x(0) {}
 
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
 
  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }
 
  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
 
  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }
 
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
 
  ModInt operator-() const { return ModInt(-x); }
 
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
 
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
 
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
 
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
 
  bool operator==(const ModInt &p) const { return x == p.x; }
 
  bool operator!=(const ModInt &p) const { return x != p.x; }
 
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
 
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
 
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }
 
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
 
  static int get_mod() { return mod; }
};
 
using modint = ModInt< mod >;
 
const int B = 1024;
 
template< class T >
struct BinaryIndexedTree {
  vector< T > data;
 
  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }
 
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
 
  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
 
int main() {
  int N, Q;
  cin >> N >> Q;
  UnWeightedGraph g(N), h(N);
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
 
  vector< int > ord, in(N), out(N), sub(N);
  vector< int > remark;
  for(int i = 0; i < N; i++) {
    if(g[i].size() >= B) remark.emplace_back(i);
  }
  MFP([&](auto dfs, int idx, int par) -> void {
    in[idx] = ord.size();
    sub[idx] = 1;
    ord.emplace_back(idx);
    for(auto &to : g[idx]) {
      if(to != par) {
        h[idx].emplace_back(to);
        dfs(to, idx);
        sub[idx] += sub[to];
      }
    }
    out[idx] = ord.size();
  })(0, -1);
  // N
 
  // , 
  // N
  // R
  // (N-sub[r])*D
 
  // NN
  // 
 
 
  vector< int64 > add(N), cnt(N);
  modint coef = modint(1) / N, all_add = 0;
  BinaryIndexedTree< modint > bit(N + 1);
  vector< vector< int > > ushi;
  for(int i = 0; i < remark.size(); i++) {
    vector< int > uku(N);
    MFP([&](auto dfs, int idx, int par) -> void {
      uku[idx] = 1;
      for(auto &to : g[idx]) {
        if(to != par) {
          dfs(to, idx);
          uku[idx] += uku[to];
        }
      }
    })(remark[i], -1);
    vector< int > beet(N);
    auto dfs = MFP([&](auto dfs, int idx, int par, int other) -> void {
      beet[idx] = other;
      for(auto &to : g[idx]) {
        if(to != par) {
          dfs(to, idx, other);
        }
      }
    });
    for(auto &to : g[remark[i]]) dfs(to, remark[i], N - uku[to]);
    beet[remark[i]] = N;
    ushi.emplace_back(beet);
  }
 
  swap(g, h);
 
  vector< int > mark(N + 1, -1), xxx(N + 1);
  vector< modint > dp(N + 1);
  int ptr = 0, sss = 0;
  auto set = [&](int idx, modint p) {
    if(mark[idx] != ptr) {
      dp[idx] = 0;
      mark[idx] = ptr;
      xxx[sss++] = idx;
    }
    dp[idx] += p;
  };
 
 
  while(Q--) {
 
    int T;
    cin >> T;
    if(T == 1) {
      int64 V, D;
      cin >> V >> D;
      --V;
 
      if(g[V].size() < B) {
        modint preadd = 1LL * sub[V] * D;
 
        all_add += preadd;
 
        set(in[V], -preadd);
        set(out[V], preadd);
        set(in[V], 1LL * N * D);
        set(in[V] + 1, -1LL * N * D);
        for(auto &to : g[V]) {
          modint d = 1LL * (N - sub[to]) * D;
          set(in[to], d);
          set(out[to], -d);
        }
 
      } else {
        add[V] += D;
        cnt[V] += 1;
      }
    } else {
      int V;
      cin >> V;
      --V;
 
 
 
      for(int i = 0; i < sss; i++) bit.add(xxx[i], dp[xxx[i]]);
      ++ptr;
      sss = 0;
 
      modint ret = bit.sum(in[V]) + all_add;
 
 
      for(int i = 0; i < remark.size(); i++) {
        ret += ushi[i][V] * add[remark[i]];
      }
      cout << ret * coef << endl;
    }
  }
}