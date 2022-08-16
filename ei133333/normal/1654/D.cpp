#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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


void beet() {
  int N;
  cin >> N;
  vector< int > pf(N + 1);
  vector< vector< modint > > es(N + 1);
  for(int i = 2; i <= N; i++) {
    if(pf[i] == 0) {
      for(int j = i; j <= N; j += i) {
        pf[j] = i;
      }
    }
  }
  struct edge {
    int to, x, y;
  };
  vector< vector< edge > > g(N);
  for(int i = 1; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b;
    g[a].emplace_back((edge) {b, c, d});
    g[b].emplace_back((edge) {a, d, c});
  }
  vector< modint > invs(N + 1);
  for(int i = 1; i <= N; i++) {
    invs[i] = modint(i).inverse();
  }
  auto add_fact = [&](map< int, int > &mp, int x, modint &now) {
    while(x > 1) {
      mp[pf[x]]++;
      now *= pf[x];
      x /= pf[x];
    }
  };
  auto del_fact = [&](map< int, int > &mp, int x, modint &now) {
    while(x > 1) {
      mp[pf[x]]--;
      now *= invs[pf[x]];
      x /= pf[x];
    }
  };
  vector< map< int, int > > dp(N);
  vector< modint > now(N);
  vector< modint > total(N);
  auto dfs = MFP([&](auto dfs, int idx, int par) -> void {
    now[idx] = 1;
    for(auto &e: g[idx]) {
      if(e.to == par) continue;
      dfs(e.to, idx);

      add_fact(dp[idx], e.y, now[idx]);
      //int a = ret * e.y;
      add_fact(dp[e.to], e.x, now[e.to]);
      //int b = res.first * e.x;

      modint lcm = now[idx];
      if(dp[idx].size() < dp[e.to].size()) { // lcm
        dp[idx].swap(dp[e.to]);
        lcm = now[e.to];
      }
      for(auto &p: dp[e.to]) {
        int pre = dp[idx][p.first];
        if(chmax(dp[idx][p.first], p.second)) {
          lcm *= modint(p.first).pow(p.second - pre);
        }
      }
      total[idx] *= lcm / now[idx];
      total[idx] += total[e.to] * (lcm / now[e.to]);
      now[idx] = lcm;
      del_fact(dp[idx], e.y, now[idx]);
    }
    total[idx] += now[idx];
  });
  dfs(0, -1);
  cout << total[0] << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}