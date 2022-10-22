#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
// const int MOD = 1000000007;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(long long x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(long long exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &rhs) { if((val += rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &rhs) { if((val += mod - rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &rhs) { val = static_cast<unsigned long long>(val) * rhs.val % mod; return *this; }
  ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
  bool operator==(const ModInt &rhs) const { return val == rhs.val; }
  bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
  bool operator<(const ModInt &rhs) const { return val < rhs.val; }
  bool operator<=(const ModInt &rhs) const { return val <= rhs.val; }
  bool operator>(const ModInt &rhs) const { return val > rhs.val; }
  bool operator>=(const ModInt &rhs) const { return val >= rhs.val; }
  ModInt &operator++() { if (++val == mod) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) { return os << rhs.val; }
  friend istream &operator>>(istream &is, ModInt &rhs) { long long x; is >> x; rhs = ModInt(x); return is; }
private:
  ModInt inv() const {
    // if (__gcd(val, mod) != 1) assert(false);
    unsigned a = val, b = mod; int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(x -= tmp * y, y);
    }
    return ModInt(x);
  }
};
int abs(const ModInt &x) { return x.val; }
struct Combinatorics {
  int val;
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

template <typename Semigroup>
struct DisjointSparseTable {
  using Fn = function<Semigroup(Semigroup, Semigroup)>;

  DisjointSparseTable(const vector<Semigroup> &a, const Fn fn) : fn(fn) {
    int n = a.size(), table_h = 1;
    while ((1 << table_h) < n) ++table_h;
    lg.assign(1 << table_h, 0);
    FOR(i, 2, 1 << table_h) lg[i] = lg[i >> 1] + 1;
    dat.assign(table_h, vector<Semigroup>(n));
    REP(j, n) dat[0][j] = a[j];
    FOR(i, 1, table_h) {
      int shift = 1 << i;
      for (int left = 0; left < n; left += shift << 1) {
        int mid = min(left + shift, n);
        dat[i][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= left; --j) dat[i][j] = fn(a[j], dat[i][j + 1]);
        if (n <= mid) break;
        int right = min(mid + shift, n);
        dat[i][mid] = a[mid];
        for (int j = mid + 1; j < right; ++j) dat[i][j] = fn(dat[i][j - 1], a[j]);
      }
    }
  }

  Semigroup query(int left, int right) {
    if (left == right) return dat[0][left];
    int h = lg[left ^ right];
    return fn(dat[h][left], dat[h][right]);
  }

private:
  const Fn fn;
  vector<int> lg;
  vector<vector<Semigroup> > dat;
};

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegTree {
  using MM = function<Monoid(Monoid, Monoid)>;
  using MOI = function<Monoid(Monoid, OperatorMonoid, int)>;
  using OO = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

  LazySegTree(int sz, const MM mm, const MOI moi, const OO oo, const Monoid &M_UNITY, const OperatorMonoid &O_UNITY)
    : mm(mm), moi(moi), oo(oo), M_UNITY(M_UNITY), O_UNITY(O_UNITY) {
    init(sz);
    dat.assign(n << 1, M_UNITY);
  }

  LazySegTree(const vector<Monoid> &a, const MM mm, const MOI moi, const OO oo, const Monoid &M_UNITY, const OperatorMonoid &O_UNITY)
    :  mm(mm), moi(moi), oo(oo), M_UNITY(M_UNITY), O_UNITY(O_UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize(n << 1);
    REP(i, a_sz) dat[i + n] = a[i];
    for (int i = n - 1; i > 0; --i) dat[i] = mm(dat[i << 1], dat[(i << 1) + 1]);
  }

  void update(int a, int b, const OperatorMonoid &value) { update(a, b, value, 1, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 1, 0, n); }

  Monoid operator[](const int idx) { return query(idx, idx + 1); }

private:
  int n = 1;
  const MM mm;
  const MOI moi;
  const OO oo;
  const Monoid M_UNITY;
  const OperatorMonoid O_UNITY;
  vector<Monoid> dat;
  vector<OperatorMonoid> lazy;
  vector<bool> need_to_be_eval;

  void init(int sz) {
    while (n < sz) n <<= 1;
    lazy.assign(n << 1, O_UNITY);
    need_to_be_eval.assign(n << 1, false);
  }

  inline void evaluate(int node, int len) {
    if (need_to_be_eval[node]) {
      dat[node] = moi(dat[node], lazy[node], len);
      if (node < n) {
        lazy[node << 1] = oo(lazy[node << 1], lazy[node]);
        need_to_be_eval[node << 1] = true;
        lazy[(node << 1) + 1] = oo(lazy[(node << 1) + 1], lazy[node]);
        need_to_be_eval[(node << 1) + 1] = true;
      }
      lazy[node] = O_UNITY;
      need_to_be_eval[node] = false;
    }
  }

  void update(int a, int b, const OperatorMonoid &value, int node, int left, int right) {
    evaluate(node, right - left);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] = oo(lazy[node], value);
      need_to_be_eval[node] = true;
      evaluate(node, right - left);
    } else {
      update(a, b, value, node << 1, left, (left + right) >> 1);
      update(a, b, value, (node << 1) + 1, (left + right) >> 1, right);
      dat[node] = mm(dat[node << 1], dat[(node << 1) + 1]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    evaluate(node, right - left);
    if (right <= a || b <= left) return M_UNITY;
    if (a <= left && right <= b) return dat[node];
    return mm(query(a, b, node << 1, left, (left + right) >> 1), query(a, b, (node << 1) + 1, (left + right) >> 1, right));
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<ModInt> p(n);
  REP(i, n) {
    int pi; cin >> pi;
    p[i] = ModInt(100) / pi;
  }
  DisjointSparseTable<ModInt> dst(p, [](ModInt a, ModInt b){ return a * b; });
  auto mm = [](ModInt m1, ModInt m2) { return m1 + m2; };
  auto moi = [](ModInt m, ModInt o, int i) { return m * o; };
  auto oo = [](ModInt o1, ModInt o2) { return o1 * o2; };
  vector<ModInt> init(n);
  REP(i, n) init[i] = dst.query(i, n - 1);
  LazySegTree<ModInt> seg(init, mm, moi, oo, 0, 1);
  set<int> checkpoints{0, n};
  while (q--) {
    int u; cin >> u; --u;
    auto it = checkpoints.lower_bound(u);
    if (checkpoints.count(u) == 0) {
      seg.update(*prev(it), u, ModInt(1) / dst.query(u, *it - 1));
      checkpoints.emplace(u);
    } else {
      seg.update(*prev(it), u, dst.query(u, *next(it) - 1));
      checkpoints.erase(u);
    }
    cout << seg.query(0, n) << '\n';
  }
  return 0;
}