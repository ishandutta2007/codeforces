#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <int M>
struct MInt {
  unsigned int val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % M : x % M + M) {}
  static constexpr int get_mod() { return M; }
  static void set_mod(int divisor) { assert(divisor == M); }
  static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }
  static MInt inv(int x, bool init = false) {
    // assert(0 <= x && x < M && std::__gcd(x, M) == 1);
    static std::vector<MInt> inverse{0, 1};
    int prev = inverse.size();
    if (init && x >= prev) {
      // "x!" and "M" must be disjoint.
      inverse.resize(x + 1);
      for (int i = prev; i <= x; ++i) inverse[i] = -inverse[M % i] * (M / i);
    }
    if (x < inverse.size()) return inverse[x];
    unsigned int a = x, b = M; int u = 1, v = 0;
    while (b) {
      unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }
  static MInt fact(int x) {
    static std::vector<MInt> f{1};
    int prev = f.size();
    if (x >= prev) {
      f.resize(x + 1);
      for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;
    }
    return f[x];
  }
  static MInt fact_inv(int x) {
    static std::vector<MInt> finv{1};
    int prev = finv.size();
    if (x >= prev) {
      finv.resize(x + 1);
      finv[x] = inv(fact(x).val);
      for (int i = x; i > prev; --i) finv[i - 1] = finv[i] * i;
    }
    return finv[x];
  }
  static MInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    if (n - k > k) k = n - k;
    return fact(n) * fact_inv(k) * fact_inv(n - k);
  }
  static MInt nPk(int n, int k) { return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }
  static MInt nHk(int n, int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }
  static MInt large_nCk(long long n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    inv(k, true);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) res *= inv(i) * n--;
    return res;
  }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= M) val -= M; return *this; }
  MInt &operator-=(const MInt &x) { if((val += M - x.val) >= M) val -= M; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % M; return *this; }
  MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == M) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? M : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? M - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int M> MInt<M> abs(const MInt<M> &x) { return x; } }
using ModInt = MInt<MOD>;

template <typename T = char, typename U = std::string>
std::vector<std::pair<T, int>> run_length_encoding(const U &s) {
  int n = s.size();
  std::vector<std::pair<T, int>> res;
  T now = s[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

template <typename T>
std::vector<T> fast_mobius_transform(std::vector<T> a, bool adds_superset, const T ID = 0) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (adds_superset) {
    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      a[s] -= a[s | i];
    }
  } else {
    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      a[s | i] -= a[s];
    }
  }
  return a;
}

template <typename Ring>
std::vector<Ring> fast_zeta_transform(
  std::vector<Ring> a,
  bool adds_superset,
  const Ring ID = 0,
  const std::function<Ring(Ring, Ring)> fn = [](const Ring &a, const Ring &b) -> Ring { return a + b; }
) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (adds_superset) {
    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      a[s] = fn(a[s], a[s | i]);
    }
  } else {
    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      a[s | i] = fn(a[s | i], a[s]);
    }
  }
  return a;
}

int main() {
  constexpr int C = 26;
  int n; cin >> n;
  vector s(n, vector(C, 0));
  REP(i, n) {
    string si; cin >> si;
    for (const auto [c, len] : run_length_encoding(si)) s[i][c - 'a'] = len;
  }
  vector<ModInt> uniq(1 << n, 1);
  FOR(b, 1, 1 << n) {
    int num[C]{};
    fill(num, num + C, INF);
    REP(i, n) {
      if (b >> i & 1) {
        REP(j, C) chmin(num[j], s[i][j]);
      }
    }
    REP(j, C) uniq[b] *= num[j] + 1;
  }
  uniq = fast_mobius_transform(uniq, true);
  uniq[0] = 0;
  // REP(b, 1 << n) cerr << uniq[b] << " \n"[b + 1 == (1 << n)];
  const ModInt all = accumulate(ALL(uniq), ModInt(0));
  vector<ModInt> cannot_get(1 << n, 0);
  REP(i, 1 << n) cannot_get[i ^ ((1 << n) - 1)] = uniq[i];
  cannot_get = fast_zeta_transform(cannot_get, true);
  // REP(b, 1 << n) cerr << cannot_get[b] << " \n"[b + 1 == (1 << n)];
  ll hash = 0;
  FOR(b, 1, 1 << n) {
    ll is = 0;
    REP(i, n) {
      if (b >> i & 1) is += i + 1;
    }
    hash ^= is * __builtin_popcount(b) * (all - cannot_get[b]).val;
  }
  cout << hash << '\n';
  return 0;
}