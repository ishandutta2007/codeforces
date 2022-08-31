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
};

using mint1 = ModInt< (int) (1e9 + 7) >;
using mint2 = ModInt< (int) (1e9 + 9) >;
using mint3 = ModInt< (int) (1e9 + 21) >;


template< typename Data, typename T >
struct ReRooting {

  struct Node {
    int to, rev;
    Data data;
  };

  using F1 = function< T(T, T) >;
  using F2 = function< T(T, Data) >;

  vector< vector< Node > > g;
  vector< vector< T > > ldp, rdp;
  vector< int > lptr, rptr;
  const F1 f1;
  const F2 f2;
  const T ident;

  ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident) :
      g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident) {}

  void add_edge(int u, int v, const Data &d) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, d});
  }

  void add_edge_bi(int u, int v, const Data &d, const Data &e) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, e});
  }


  T dfs(int idx, int par) {

    while(lptr[idx] != par && lptr[idx] < g[idx].size()) {
      auto &e = g[idx][lptr[idx]];
      ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));
      ++lptr[idx];
    }
    while(rptr[idx] != par && rptr[idx] >= 0) {
      auto &e = g[idx][rptr[idx]];
      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), e.data));
      --rptr[idx];
    }
    if(par < 0) return rdp[idx][0];
    return f1(ldp[idx][par], rdp[idx][par + 1]);
  }

  vector< T > solve() {
    for(int i = 0; i < g.size(); i++) {
      ldp[i].assign(g[i].size() + 1, ident);
      rdp[i].assign(g[i].size() + 1, ident);
      lptr[i] = 0;
      rptr[i] = (int) g[i].size() - 1;
    }
    vector< T > ret;
    for(int i = 0; i < g.size(); i++) {
      ret.push_back(dfs(i, -1));
    }
    return ret;
  }
};

int N;
vector< int > g[100000];
map< int, int > add[100000];

void dfs(int idx, int par, int base) {
  int child = -1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    if(child == -1) child = to;
    else child = -2;
    if(child == -2) break;
  }
  if(child == -2) {
    add[idx][par] = base;
  } else if(child != -1) {
    dfs(child, idx, base);
  }
}

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};


int main() {
  auto P = prime_table(1000000);
  vector< int > it;
  for(int i = 30; i < P.size(); i++) {
    if(P[i]) it.emplace_back(i);
  }
  RandomNumberGenerator rng;
  for(int i = 0; i < 1000000; i++) {
    int x = rng(it.size());
    int y = rng(it.size());
    swap(it[x], it[y]);
  }


  cin >> N;

  if(N <= 2) {
    cout << 1 << endl;
    return 0;
  }
  struct T {
    mint1 x;
    mint2 y;
    mint3 z;
  } e{0, 0, 0};

  auto f1 = [](T x, T y) {
    T z;
    z.x = x.x + y.x;
    z.y = x.y + y.y;
    z.z = x.z + y.z;
    return z;
  };
  auto f2 = [&](T x, int y) {
    x.x += it[0];
    x.y += it[1];
    x.z += it[2];
    x.x *= x.x;
    x.y *= x.y;
    x.z *= x.z;
    return x;
  };
  ReRooting< int, T > tap(N, f1, f2, e);
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    tap.add_edge(a, b, 1);
  }
  for(int i = 0; i < N; i++) dfs(i, -1, i);
  tap.solve();

  int k = true;
  int p = -1;
  for(int i = 0; i < N; i++) {
    k &= g[i].size() <= 2;
    if(g[i].size() == 1) p = i;
  }
  if(k) {
    cout << p + 1 << endl;
    return 0;
  }

  for(int i = 0; i < N; i++) {
    map< tuple< int, int, int >, int > uku;
    for(auto &e : tap.g[i]) {
      auto val = f2(tap.dfs(e.to, e.rev), e.data);
      auto cur = make_tuple(val.x.x, val.y.x, val.z.x);
      uku[cur]++;
    }

    if(uku.size() >= 3) continue;

    for(auto &e : tap.g[i]) {
      if(add[i].count(e.to)) {
        auto val = f2(tap.dfs(e.to, e.rev), e.data);
        auto cur = make_tuple(val.x.x, val.y.x, val.z.x);
        if(uku[cur] == 1 || (uku.size() == 1 && uku[cur] >= 3)) {
          cout << add[i][e.to] + 1 << endl;
          return 0;
        }
      }
    }
    if(g[i].size() >= 2) {
      if(uku.size() == 1) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}