#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(ll x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(ll exponent) const {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &x) { if((val += x.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &x) { if((val += mod - x.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod; return *this; }
  ModInt &operator/=(const ModInt &x) {
    // assert(__gcd(static_cast<int>(x.val), mod) == 1);
    unsigned a = x.val, b = mod; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator<=(const ModInt &x) const { return val <= x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return val >= x.val; }
  ModInt &operator++() { if (++val == mod) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
  friend istream &operator>>(istream &is, ModInt &x) { ll val; is >> val; x = ModInt(val); return is; }
};
ModInt abs(const ModInt &x) { return x; }
struct Combinatorics {
  int val; // "val!" and "mod" must be disjoint.
  vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    FOR(i, 1, val + 1) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return ModInt(0);
    return k == 0 ? ModInt(1) : nCk(n + k - 1, k);
  }
};

int main() {
  const int BASE = 10007;
  struct RollingHash {
    vector<ModInt> p, hash;
    RollingHash(const string &s) {
      int n = s.length();
      p.resize(n + 1, 1);
      REP(i, n) p[i + 1] = p[i] * BASE;
      hash.resize(n + 1, 0);
      REP(i, n) hash[i + 1] = hash[i] * BASE + s[i];
    }
    int get(int r, int era) {
      return (era <= r ? hash[r + 1] - hash[era + 1] * p[r - era] + hash[era] * p[r - era] : hash[r + 1]).val;
    }
  };

  int n; cin >> n;
  vector<string> s(n);
  function<char(int, int, int)> get_c = [&](int idx, int pos, int era) {
    return s[idx][pos + (era <= pos)];
  };
  vector<RollingHash> rh;
  vector<vector<int>> sorted(n);
  REP(i, n) {
    cin >> s[i];
    rh.emplace_back(s[i]);
    int len = s[i].length();
    vector nxt(len, len - 1);
    for (int j = len - 2; j >= 0; --j) nxt[j] = s[i][j] == s[i][j + 1] ? nxt[j + 1] : j + 1;
    sorted[i].resize(len + 1);
    int l = 0, r = len;
    REP(j, len) sorted[i][s[i][j] < s[i][nxt[j]] ? r-- : l++] = j;
    assert(l == r);
    sorted[i][l] = len;
  }
  // REP(i, n) REP(j, sorted[i].size()) cout << sorted[i][j] << " \n"[j + 1 == sorted[i].size()];

  vector dp(s[0].length() + 1, ModInt(1));
  FOR(i, 1, n) {
    int len = s[i].length();
    vector nx(len + 1, ModInt(0));
    ModInt sum = 0;
    int pos = 0;
    REP(j, len + 1) {
      while (pos < sorted[i - 1].size()) {
        int prev_len = s[i - 1].length() - (sorted[i - 1][pos] < s[i - 1].length()), cur_len = s[i].length() - (sorted[i][j] < s[i].length());
        int lb = -1, ub = min(prev_len, cur_len);
        while (ub - lb > 1) {
          int mid = (lb + ub) >> 1;
          (rh[i - 1].get(mid + (sorted[i - 1][pos] <= mid), sorted[i - 1][pos]) == rh[i].get(mid + (sorted[i][j] <= mid), sorted[i][j]) ? lb : ub) = mid;
        }
        bool inc = [&](int idx) {
          if (prev_len == idx) return true;
          if (cur_len == idx) return false;
          char c1 = get_c(i - 1, idx, sorted[i - 1][pos]), c2 = get_c(i, idx, sorted[i][j]);
          assert(c1 != c2);
          return c1 < c2;
        } (lb + 1);
        if (!inc) break;
        sum += dp[pos++];
      }
      nx[j] = sum;
    }
    dp.swap(nx);
  }
  cout << accumulate(ALL(dp), ModInt(0)) << '\n';
  return 0;
}