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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
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

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); REP(i, n) cin >> a[i];
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    vector<ll> sum(n + 1, 0LL);
    REP(i, n) sum[i + 1] = sum[i] + a[i];
    // ll ans = 0;
    ModInt ans = 0;
    // CC ... PCPC ... (PPP)
    {
      vector<ll> even(n, 0), odd(n, 0);
      for (int i = n - 2; i > 0; i -= 2) {
        if (i + 2 < n) even[i] = even[i + 2];
        even[i] += a[i] - a[i + 1];
      }
      for (int i = n - 2; i > 0; i -= 2) even[i] -= sum[i] - sum[0];
      for (int i = n - 1; i > 0; i -= 2) {
        if (i + 2 < n) odd[i] = odd[i + 2];
        odd[i] += a[i];
        if (i + 1 < n) odd[i] -= a[i + 1];
      }
      for (int i = n - 1; i > 0; i -= 2) odd[i] -= sum[i] - sum[0];
      vector<ll> r{0};
      for (int i = n - 2; i > 0; i -= 2) {
        r.emplace_back(r.back() + a[i + 1] * 2);
        ans += r.end() - upper_bound(ALL(r), -even[i]);
      }
      r.assign(1, 0);
      for (int i = n - 1; i > 0; i -= 2) {
        if (i + 1 < n) r.emplace_back(r.back() + a[i + 1] * 2);
        ans += r.end() - upper_bound(ALL(r), -odd[i]);
      }
    }
    // CC ... PPC
    if (n >= 4) {
      ans += sum[n - 3] - sum[0] + a[n - 1] < a[n - 3] + a[n - 2];
      if (n > 4) {
        vector<ll> even(n, 1LL * a[n - 3] + a[n - 2] - a[n - 1]), odd(n, 1LL * a[n - 3] + a[n - 2] - a[n - 1]);
        for (int i = n - 5; i > 0; i -= 2) {
          if (i + 2 <= n - 5) even[i] = even[i + 2];
          even[i] += a[i] - a[i + 1];
        }
        for (int i = n - 5; i > 0; i -= 2) even[i] -= sum[i] - sum[0];
        for (int i = n - 4; i > 0; i -= 2) {
          if (i + 2 <= n - 4) odd[i] = odd[i + 2];
          odd[i] += a[i];
          if (i + 1 <= n - 4) odd[i] -= a[i + 1];
        }
        for (int i = n - 4; i > 0; i -= 2) odd[i] -= sum[i] - sum[0];
        vector<ll> r{0};
        for (int i = n - 5; i > 0; i -= 2) {
          r.emplace_back(r.back() + a[i + 1] * 2);
          ans += r.end() - upper_bound(ALL(r), -even[i]);
        }
        r.assign(1, 0);
        for (int i = n - 4; i > 0; i -= 2) {
          if (i + 1 <= n - 4) r.emplace_back(r.back() + a[i + 1] * 2);
          ans += r.end() - upper_bound(ALL(r), -odd[i]);
        }
      }
    }
    // PCC ... PCPC ... (PPP)
    {
      ans += sum[n] - sum[1] < a[0];
      vector<ll> even(n, a[0]), odd(n, a[0]);
      for (int i = n - 2; i >= 2; i -= 2) {
        if (i + 2 < n) even[i] = even[i + 2];
        even[i] += a[i] - a[i + 1];
      }
      for (int i = n - 2; i >= 2; i -= 2) even[i] -= sum[i] - sum[1];
      for (int i = n - 1; i >= 2; i -= 2) {
        if (i + 2 < n) odd[i] = odd[i + 2];
        odd[i] += a[i];
        if (i + 1 < n) odd[i] -= a[i + 1];
      }
      for (int i = n - 1; i >= 2; i -= 2) odd[i] -= sum[i] - sum[1];
      vector<ll> r{0};
      for (int i = n - 2; i >= 2; i -= 2) {
        r.emplace_back(r.back() + a[i + 1] * 2);
        ans += r.end() - upper_bound(ALL(r), -even[i]);
      }
      r.assign(1, 0);
      for (int i = n - 1; i >= 2; i -= 2) {
        if (i + 1 < n) r.emplace_back(r.back() + a[i + 1] * 2);
        ans += r.end() - upper_bound(ALL(r), -odd[i]);
      }
    }
    // PCC ... PPC
    if (n >= 5) {
      ans += sum[n - 3] - sum[1] + a[n - 1] < 1LL * a[0] + a[n - 3] + a[n - 2];
      if (n > 5) {
        vector<ll> even(n, 1LL * a[n - 3] + a[n - 2] - a[n - 1] + a[0]), odd(n, 1LL * a[n - 3] + a[n - 2] - a[n - 1] + a[0]);
        for (int i = n - 5; i >= 2; i -= 2) {
          if (i + 2 <= n - 5) even[i] = even[i + 2];
          even[i] += a[i] - a[i + 1];
        }
        for (int i = n - 5; i >= 2; i -= 2) even[i] -= sum[i] - sum[1];
        for (int i = n - 4; i >= 2; i -= 2) {
          if (i + 2 <= n - 4) odd[i] = odd[i + 2];
          odd[i] += a[i];
          if (i + 1 <= n - 4) odd[i] -= a[i + 1];
        }
        for (int i = n - 4; i >= 2; i -= 2) odd[i] -= sum[i] - sum[1];
        vector<ll> r{0};
        for (int i = n - 5; i >= 2; i -= 2) {
          r.emplace_back(r.back() + a[i + 1] * 2);
          ans += r.end() - upper_bound(ALL(r), -even[i]);
        }
        r.assign(1, 0);
        for (int i = n - 4; i >= 2; i -= 2) {
          if (i + 1 <= n - 4) r.emplace_back(r.back() + a[i + 1] * 2);
          ans += r.end() - upper_bound(ALL(r), -odd[i]);
        }
      }
    }
    // PP ... (CCC)
    ll cur = a[0] - (sum[n] - sum[1]);
    FOR(i, 1, n) {
      cur += a[i] * 2;
      ans += cur > 0;
    }
    cout << ans << '\n';
  }
  return 0;

  constexpr int N = 10;
  REP(b, 1 << N) {
    vector<int> c, p;
    REP(i, N) (b >> (N - 1 - i) & 1 ? p : c).emplace_back(i);
    bool is_valid = true;
    FOR(i, 2, c.size()) is_valid &= c[i - 1] - c[i - 2] <= c[i] - c[i - 1];
    FOR(i, 2, p.size()) is_valid &= p[i - 1] - p[i - 2] >= p[i] - p[i - 1];
    if (is_valid) cout << bitset<N>(b) << '\n';
  }
}