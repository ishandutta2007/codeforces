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
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
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

template <int MOD>
struct MInt {
  unsigned int val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
  static constexpr int get_mod() { return MOD; }
  static void set_mod(int divisor) { assert(divisor == MOD); }
  static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }
  static MInt inv(int x, bool init = false) {
    // assert(0 <= x && x < MOD && std::__gcd(x, MOD) == 1);
    static std::vector<MInt> inverse{0, 1};
    int prev = inverse.size();
    if (init && x >= prev) {
      // "x!" and "MOD" must be disjoint.
      inverse.resize(x + 1);
      for (int i = prev; i <= x; ++i) inverse[i] = -inverse[MOD % i] * (MOD / i);
    }
    if (x < inverse.size()) return inverse[x];
    unsigned int a = x, b = MOD; int u = 1, v = 0;
    while (b) {
      unsigned int tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
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
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator-=(const MInt &x) { if((val += MOD - x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }
  MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == MOD) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? MOD - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x) { return x; } }
using ModInt = MInt<MOD>;

// template <typename T>
// std::vector<int> z_algorithm(const T &s) {
//   int n = s.size();
//   std::vector<int> res(n, 0);
//   for (int i = 1, j = 0; i < n; ++i) {
//     if (i + res[i - j] < j + res[j]) {
//       res[i] = res[i - j];
//     } else {
//       res[i] = std::max(j + res[j] - i, 0);
//       while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
//       j = i;
//     }
//   }
//   res[0] = n;
//   return res;
// }

int res[1000000 + 1 + 1998847 + 1 + 1998847] = {};
template <typename T>
int z_algorithm1(const T &s, int len) {
  int n = s.size(), m = n - len + 1, ans = 0;
  for (int i = 1, j = 0; i < m; ++i) {
    if (i + res[i - j] < j + res[j]) {
      res[i] = res[i - j];
      ans += res[i] == len;
    } else {
      res[i] = std::max(j + res[j] - i, 0);
      while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
      ans += res[i] == len;
      j = i;
    }
  }
  fill(res, res + n, 0);
  return ans;
}

template <typename T>
int z_algorithm2(const T &s, int t_len, int s_len) {
  int n = s.size(), m = t_len + 1 + s_len, l = m - t_len + 1, ans = 0;
  for (int i = 1, j = 0; i <= m; ++i) {
    if (i + res[i - j] < j + res[j]) {
      res[i] = res[i - j];
      ans += i >= l && res[i] == t_len;
    } else {
      res[i] = std::max(j + res[j] - i, 0);
      while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
      ans += i >= l && res[i] == t_len;
      j = i;
    }
  }
  fill(res, res + n, 0);
  return ans;
}

int main() {
  constexpr int L = 1000000;
  int n, q; cin >> n >> q;
  vector<string> s(1);
  string t; cin >> s[0] >> t;
  t = "$" + t;
  for (int i = 1; i <= n && s.back().length() < L; ++i) {
    s.emplace_back(s.back() + t[i] + s.back());
  }
  vector cnt(n + 1, vector(26, ModInt(0)));
  for (int i = 1; i <= n; ++i) {
    REP(j, 26) cnt[i][j] = cnt[i - 1][j] * 2;
    ++cnt[i][t[i] - 'a'];
  }
  vector<ModInt> p2(n + 1, 1);
  REP(i, n) p2[i + 1] = p2[i] * 2;
  while (q--) {
    int k; string t; cin >> k >> t;
    int level = min(int(s.size()) - 1, k);
    while (level > 0 && s[level - 1].length() >= t.length()) --level;
    if (s[min(int(s.size()) - 1, k)].length() < t.length()) {
      cout << 0 << '\n';
      continue;
    }
    ModInt ans = p2[k - level] * z_algorithm1(t + '$' + s[level], t.length());
    REP(c, 26) {
      ans += (cnt[k][c] - cnt[level][c] * p2[k - level]) * z_algorithm2(t + '$' + s[level] + char('a' + c) + s[level], t.length(), s[level].length());
    }
    cout << ans << '\n';
  }
  return 0;
}