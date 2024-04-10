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
const int MOD = 998244353;
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

template <typename T>
vector<pair<T, int>> prime_factorization(T val) {
  vector<pair<T, int>> res;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(ll x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(ll exponent) {
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
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
};

int main() {
  ll d; cin >> d;
  auto pf = prime_factorization(d);
  int n = pf.size();
  Combinatorics com(n * 50);
  map<ll, vector<int>> divs;
  function<void(ll, vector<int>&)> rec = [&](ll now, vector<int> &ex) {
    int idx = ex.size();
    // cout << now << ' ' << idx << endl;
    if (idx == n) {
      divs[now] = ex;
      return;
    }
    REP(i, pf[idx].second + 1) {
      ex.emplace_back(i);
      rec(now, ex);
      if (i < pf[idx].second) now *= pf[idx].first;
      ex.pop_back();
    }
  };
  vector<int> vec;
  rec(1, vec);
  // for (auto [divis, ignore] : divs) cout << divis << '\n';
  function<ModInt(ll, ll)> solve = [&](ll u, ll v) {
    const vector<int> &ex_u = divs[u], &ex_v = divs[v];
    ModInt ans = 1;
    int sum = 0;
    REP(i, n) {
      ans *= com.fact_inv[ex_v[i] - ex_u[i]];
      sum += ex_v[i] - ex_u[i];
    }
    return ans * com.fact[sum];
  };
  int q; cin >> q;
  while (q--) {
    ll u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    cout << (v % u == 0 ? solve(u, v) : solve(__gcd(u, v), u) * solve(__gcd(u, v), v)) << '\n';
  }
  return 0;
}