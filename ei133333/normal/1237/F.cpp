#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  vector< int > latte(H), malta(W);
  for(int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    latte[a] = true;
    malta[b] = true;
    latte[c] = true;
    malta[d] = true;
  }

  vector< int > as;
  {
    int sz = 0;
    for(int i = 0; i <= W; i++) {
      if(i == W || malta[i]) {
        if(sz) as.emplace_back(sz);
        sz = 0;
      } else {
        ++sz;
      }
    }
  }

  Combination< modint > beet(101010);
  auto coef = make_v< modint >(1);
  int all = 0;

  {
    coef[0] = 1;
    int used = 0;
    for(auto &sz : as) {
      auto dp = make_v< modint >(sz + 1);
      for(int k = 0; k <= sz; k++) {
        dp[k] = beet.C(sz - k, k);
      }
      auto coef2 = make_v< modint >(used + sz / 2 + 1);
      for(int k = 0; k <= used; k++) {
        for(int l = 0; l <= sz/2; l++) {
          coef2[k + l] += coef[k] * dp[l];
        }
      }
      coef.swap(coef2);
      used += sz / 2;
      all += sz;
    }
  }



  auto dp = make_v< modint >(H + 1, W + 1);
  dp[0][0] = 1;
  int tateall = 0;
  for(int i = 0; i < H; i++) {
    if(i + 1 < H && !latte[i] && !latte[i + 1]) {
      for(int j = 1; j <= W; j++) {
        dp[i + 2][j] += dp[i][j - 1] * j;
      }
    }
    for(int j = 0; j <= W; j++) {
      dp[i + 1][j] += dp[i][j];
    }
    tateall += latte[i] ^ 1;
  }


  modint ret = 0;
  for(int i = 0; i <= H; i++) {
    int rest = tateall - i * 2;
    if(rest < 0) continue;
    for(int j = 0; j <= W && j < coef.size(); j++) {
      ret += beet.P(rest, j) * dp[H][i] * coef[j] * beet.C(all - 2 * j, i);
    }
  }
  cout << ret << endl;
}