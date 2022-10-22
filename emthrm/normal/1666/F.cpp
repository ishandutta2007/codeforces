#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int MOD = 998244353;
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }

template <int M>
struct MInt {
  unsigned int v;
  MInt() : v(0) {}
  MInt(const ll x) : v(x >= 0 ? x % M : x % M + M) {}
  static MInt inv(const int n) {
    int u = 1, v = 0;
    for (unsigned int a = n, b = M; b;) {
      const unsigned int q = a / b;
      swap(a -= q * b, b);
      swap(u -= q * v, v);
    }
    return u;
  }
  static MInt fact(int n) {
    static vector<MInt> factorial{1};
    const int prev = factorial.size();
    if (n >= prev) {
      factorial.resize(n + 1);
      FOR(i, prev, n + 1) factorial[i] = factorial[i - 1] * i;
    }
    return factorial[n];
  }
  static MInt fact_inv(int n) {
    static vector<MInt> f_inv{1};
    const int prev = f_inv.size();
    if (n >= prev) {
      f_inv.resize(n + 1);
      f_inv[n] = inv(fact(n).v);
      for (int i = n; i > prev; --i) f_inv[i - 1] = f_inv[i] * i;
    }
    return f_inv[n];
  }
  static MInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) : fact_inv(n - k) * fact_inv(k));
  }
  MInt pow(ll ex) const {
    MInt res = 1, tmp = *this;
    for (; ex > 0; ex >>= 1) {
      if (ex & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }
  MInt& operator+=(const MInt& x) {
    if ((v += x.v) >= M) v -= M;
    return *this;
  }
  MInt& operator-=(const MInt& x) {
    if ((v += M - x.v) >= M) v -= M;
    return *this;
  }
  MInt& operator*=(const MInt& x) {
    v = static_cast<unsigned long long>(v) * x.v % M;
    return *this;
  }
  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(v ? M - v : 0); }
  MInt operator+(const MInt& x) const { return MInt(*this) += x; }
  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }
  friend ostream& operator<<(ostream& os, const MInt& x) { return os << x.v; }
  friend istream& operator>>(istream& is, MInt& x) {
    ll v; is >> v;
    x = MInt(v);
    return is;
  }
};
using ModInt = MInt<MOD>;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (a[n - 2] == a[n - 1]) {
    cout << 0 << '\n';
    return;
  }
  if (n == 2) {
    cout << 1 << '\n';
    return;
  }
  ModInt inv = 1;
  for (int i = 0; i < n - 1;) {
    int j = i + 1;
    while (j < n - 1 && a[j] == a[i]) ++j;
    inv *= ModInt::fact_inv(j - i);
    i = j;
  }
  ModInt ans = 0;
  vector<ModInt> dp(n, 0);
  dp[0] = 1;
  for (int i = n - 2; i >= 0;) {
    int j = i;
    while (j > 0 && a[j - 1] == a[i]) --j;
    inv *= ModInt::fact(i - j + 1);
    vector<ModInt> nxt(n, 0);
    FOR(k, i - j + 1, n) nxt[k - (i - j + 1)] += dp[k] * ModInt::nCk(k, i - j + 1);
    FOR(k, i - j, n) {
      if (k - (i - j) + 1 < n) {
        nxt[k - (i - j) + 1] += dp[k] * ModInt::nCk(k, i - j);
        if (k - (i - j) + 2 == j) ans += dp[k] * ModInt::nCk(k, i - j) * ModInt::fact(j) * inv;
      }
    }
    dp.swap(nxt);
    // REP(k, n) cout << dp[k] << " \n"[k + 1 == n];
    i = j - 1;
  }
  cout << ans << '\n';

  // ModInt ans2 = 0;
  // do {
  //   bool is_valid = true;
  //   for (int i = 1; i < n; i += 2) is_valid &= a[i - 1] < a[i];
  //   for (int i = 2; i < n; i += 2) is_valid &= a[i - 1] > a[i];
  //   for (int i = 3; i < n; i += 2) is_valid &= a[i - 2] < a[i];
  //   ans2 = ans2 + is_valid;
  //   // if (is_valid) {
  //   //   REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  //   // }
  // } while (next_permutation(ALL(a)));
  // assert(ans2.v == ans.v);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}