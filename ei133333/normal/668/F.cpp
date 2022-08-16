#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;//998244353;

const int64 infll = (1LL << 60) - 1;
const int inf = (1 << 28) - 1;

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

/**
 * @brief Formal-Power-Series()
 */
template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;

  using MULT = function< vector< T >(P, P) >;
  using FFT = function< void(P &) >;
  using SQRT = function< T(T) >;

  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }

  static void set_mult(MULT f) {
    get_mult() = f;
  }

  static FFT &get_fft() {
    static FFT fft = nullptr;
    return fft;
  }

  static FFT &get_ifft() {
    static FFT ifft = nullptr;
    return ifft;
  }

  static void set_fft(FFT f, FFT g) {
    get_fft() = f;
    get_ifft() = g;
    if(get_mult() == nullptr) {
      auto mult = [&](P a, P b) {
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while((1 << nbase) < need) nbase++;
        int sz = 1 << nbase;
        a.resize(sz, T(0));
        b.resize(sz, T(0));
        get_fft()(a);
        get_fft()(b);
        for(int i = 0; i < sz; i++) a[i] *= b[i];
        get_ifft()(a);
        a.resize(need);
        return a;
      };
      set_mult(mult);
    }
  }

  static SQRT &get_sqrt() {
    static SQRT sqr = nullptr;
    return sqr;
  }

  static void set_sqrt(SQRT sqr) {
    get_sqrt() = sqr;
  }

  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  P operator+(const P &r) const { return P(*this) += r; }

  P operator+(const T &v) const { return P(*this) += v; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator-(const T &v) const { return P(*this) -= v; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P operator%(const P &r) const { return P(*this) %= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    shrink();
    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }

  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    assert(get_mult() != nullptr);
    auto ret = get_mult()(*this, r);
    return *this = P(begin(ret), end(ret));
  }

  P &operator%=(const P &r) {
    return *this -= *this / r * r;
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P dot(P r) const {
    P ret(min(this->size(), r.size()));
    for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  P pre(int sz) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), sz));
  }

  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }

  T operator()(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }

  P diff() const;

  P integral() const;

  // F(0) must not be 0
  P inv_fast() const;

  P inv(int deg = -1) const;

  // F(0) must be 1
  P log(int deg = -1) const;

  P sqrt(int deg = -1) const;

  // F(0) must be 0
  P exp_fast(int deg = -1) const;

  P exp(int deg = -1) const;

  P pow(int64_t k, int deg = -1) const;

  P mod_pow(int64_t k, P g) const;

  P taylor_shift(T c) const;
};

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
using FPSGraph = vector< vector< pair< int, T > > >;

template< typename T >
FormalPowerSeries< T > random_poly(int n) {
  mt19937 mt(1333333);
  FormalPowerSeries< T > res(n);
  uniform_int_distribution< int > rand(0, T::get_mod() - 1);
  for(int i = 0; i < n; i++) res[i] = rand(mt);
  return res;
}

template< typename T >
FormalPowerSeries< T > next_poly(const FormalPowerSeries< T > &dp, const FPSGraph< T > &g) {
  const int N = (int) dp.size();
  FormalPowerSeries< T > nxt(N);
  for(int i = 0; i < N; i++) {
    for(auto &p : g[i]) nxt[p.first] += p.second * dp[i];
  }
  return nxt;
}

template< class T >
FormalPowerSeries< T > berlekamp_massey(const FormalPowerSeries< T > &s) {
  const int N = (int) s.size();
  FormalPowerSeries< T > b = {T(-1)}, c = {T(-1)};
  T y = T(1);
  for(int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size());
    T x = 0;
    for(int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
    b.emplace_back(0);
    m++;
    if(x == T(0)) continue;
    T freq = x / y;
    if(l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, T(0));
      for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for(int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  return c;
}

template< typename T >
FormalPowerSeries< T > minimum_poly(const FPSGraph< T > &g) {
  const int N = (int) g.size();
  auto dp = random_poly< T >(N), u = random_poly< T >(N);
  FormalPowerSeries< T > f(2 * N);
  for(int i = 0; i < 2 * N; i++) {
    for(auto &p : u.dot(dp)) f[i] += p;
    dp = next_poly(dp, g);
  }
  return berlekamp_massey(f);
}

/* O(N(N+S) + N log N log Q) (O(S): time complexity of nex) */
template< typename T >
FormalPowerSeries< T > sparse_pow(int64_t Q, FormalPowerSeries< T > dp, const FPSGraph< T > &g) {
  const int N = (int) dp.size();
  auto A = FormalPowerSeries< T >({0, 1}).pow_mod(Q, minimum_poly(g));
  FormalPowerSeries< T > res(N);
  for(int i = 0; i < A.size(); i++) {
    res += dp * A[i];
    dp = next_poly(dp, g);
  }
  return res;
}

/* O(N(N+S)) (S: none-zero elements)*/
template< typename T >
T sparse_determinant(FPSGraph< T > g) {
  using FPS = FormalPowerSeries< T >;
  int N = (int) g.size();
  auto C = random_poly< T >(N);
  for(int i = 0; i < N; i++) for(auto &p : g[i]) p.second *= C[i];
  auto u = minimum_poly(g);
  T acdet = u[0];
  if(N % 2 == 0) acdet *= -1;
  T cdet = 1;
  for(int i = 0; i < N; i++) cdet *= C[i];
  return acdet / cdet;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector <pair< int, int >> es;
  for(int i = 0; i < K; i++) {
    for(int j = 0; j < i; j++) {
      es.emplace_back(i, j);
    }
  }
  for(int i = K; i < N; i++) {
    for(int j = 0; j < K; j++) {
      int x;
      cin >> x;
      --x;
      es.emplace_back(x, i);
    }
  }

  vector< int > deg(N);
  FPSGraph< modint > g(N - 1);
  for(auto[x, y] : es) {
    deg[x]++, deg[y]++;
    if(x < N - 1 and y < N - 1) {
      g[x].emplace_back(y, -1);
      g[y].emplace_back(x, -1);
    }
  }
  for(int i = 0; i < N - 1; i++) {
    g[i].emplace_back(i, deg[i]);
  }
  cout << sparse_determinant(g) << "\n";
}