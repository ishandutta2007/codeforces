#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

template< typename T >
T binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(int64 i = 1; i <= K; i++) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  vector< int > L(N), R(N);
  vector< int > xs;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    ++R[i];
    xs.emplace_back(L[i]);
    xs.emplace_back(R[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(xs), end(xs), L[i]) - begin(xs);
    R[i] = lower_bound(begin(xs), end(xs), R[i]) - begin(xs);
  }
  auto dp = make_v< modint >(xs.size(), N + 1);
  for(int i = 0; i + 1 < xs.size(); i++) {
    if(L[N - 1] <= i && i + 1 <= R[N - 1]) {
      dp[i][1] = 1;
    }
  }
  modint uku = xs[R[N - 1]] - xs[L[N - 1]];

  Combination< modint > tap(N+N);
  auto UKU = [&](int len, int sz) {
    auto coef = make_v< modint >(sz + 1, 2);
    vector< modint > ans;
    coef[0][0] = 1;
    auto B = make_v< modint >(sz + 1);
    for(int i = 0; i <= sz; i++) {
      B[i] = binomial< modint >(len, i);
    }
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < 2; j++) {
        coef[i + 1][j] += coef[i][j] * len;
      }
      for(int to = i + 2; to <= sz; to++) {
        for(int j = 0; j < 2; j++) {
          coef[to][j ^ (to-i-1&1)] += coef[i][j] * B[to - i];
        }
      }
    }
    for(int i = 0; i <= sz; i++) {
      ans.emplace_back(coef[i][0] - coef[i][1]);
    }
    return ans;
  };
  vector< vector< modint > > coef;
  for(int i = 0; i + 1 < xs.size(); i++) {
    coef.emplace_back(UKU(xs[i + 1] - xs[i], N));
  }
  for(int i = N - 2; i >= 0; i--) {
    auto dp2 = make_v< modint >(xs.size(), N + 1);
    uku *= xs[R[i]] - xs[L[i]];
    modint add = 0;
    for(int j = 0; j + 1 < xs.size(); j++) {
      if(L[i] <= j && j + 1 <= R[i]) {
        for(int k = 0; k < N; k++) {
          dp2[j][k + 1] += dp[j][k];
        }
        dp2[j][1] += add;
      }
      for(int k = 0; k <= N; k++) {
        add += dp[j][k] * coef[j][k];
      }
    }
    dp.swap(dp2);
  }
  modint ans = 0;
  for(int i = 0; i + 1 < xs.size(); i++) {
    for(int k = 0; k <= N; k++) {
      ans += dp[i][k] * coef[i][k];
    }
  }
  cout << ans / uku << endl;
}