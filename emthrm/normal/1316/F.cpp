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

template <typename Monoid>
struct SegmentTree {
  using Fn = function<Monoid(Monoid, Monoid)>;

  SegmentTree(int sz, Fn fn, const Monoid UNITY) : fn(fn), UNITY(UNITY) {
    init(sz);
    dat.assign(n << 1, UNITY);
  }

  SegmentTree(const vector<Monoid> &a, Fn fn, const Monoid UNITY) : fn(fn), UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize(n << 1);
    REP(i, a_sz) dat[i + n] = a[i];
    for (int i = n - 1; i > 0; --i) dat[i] = fn(dat[i << 1], dat[(i << 1) + 1]);
  }

  void update(int node, Monoid val) {
    node += n;
    dat[node] = val;
    while (node >>= 1) dat[node] = fn(dat[node << 1], dat[(node << 1) + 1]);
  }

  Monoid query(int left, int right) {
    Monoid l_res = UNITY, r_res = UNITY;
    for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = fn(l_res, dat[left++]);
      if (right & 1) r_res = fn(dat[--right], r_res);
    }
    return fn(l_res, r_res);
  }

  Monoid operator[](const int idx) const { return dat[idx + n]; }

private:
  int n = 1;
  Fn fn;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }
};

int main() {
  int n; cin >> n;
  vector<ModInt> two(n + 1, 1);
  FOR(i, 1, n + 1) two[i] = two[i - 1] * 2;
  vector<int> p(n); REP(i, n) cin >> p[i];
  int q; cin >> q;
  vector<int> is(q), x(q); REP(i, q) cin >> is[i] >> x[i], --is[i];
  vector<pair<int, int>> seq(n + q);
  REP(i, n) seq[i] = {p[i], i};
  REP(i, q) seq[n + i] = {x[i], n + i};
  sort(ALL(seq));
  vector<int> now(n), pos(q);
  REP(i, n + q) {
    int idx = seq[i].second;
    if (idx < n) {
      now[idx] = i;
    } else {
      pos[idx - n] = i;
    }
  }
  ModInt den = ModInt(1) / two[n];
  struct Node {
    ModInt val, l, r;
    int num;
    Node(ModInt val = 0, int num = 0, ModInt l = 0, ModInt r = 0) : val(val), num(num), l(l), r(r) {}
  };
  auto f = [&](Node a, Node b) {
    Node res;
    res.val = a.val * two[b.num] + b.val * two[a.num] + a.l * b.r;
    res.num = a.num + b.num;
    res.l = a.l + b.l * two[a.num];
    res.r = b.r + a.r * two[b.num];
    return res;
  };
  SegmentTree<Node> seg(n + q, f, Node());
  REP(i, n) seg.update(now[i], Node(0, 1, p[i], p[i]));
  cout << seg.query(0, n + q).val * den << '\n';
  REP(i, q) {
    seg.update(now[is[i]], Node());
    now[is[i]] = pos[i];
    seg.update(pos[i], Node(0, 1, x[i], x[i]));
    cout << seg.query(0, n + q).val * den << '\n';
  }
  return 0;
}