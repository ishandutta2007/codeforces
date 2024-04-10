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
  unsigned val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
  static int get_mod() { return MOD; }
  static void set_mod(int divisor) { assert(divisor == MOD); }
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
  MInt &operator/=(const MInt &x) {
    // assert(std::__gcd(static_cast<int>(x.val), MOD) == 1);
    unsigned a = x.val, b = MOD; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
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
template <int MOD>
struct Combinatorics {
  using ModInt = MInt<MOD>;
  int val;  // "val!" and "mod" must be disjoint.
  std::vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : nCk(n + k - 1, k);
  }
};
using ModInt = MInt<MOD>;

template <typename T>
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_unity())) {}

  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2, T::o_unity());
    dat.assign(p2 << 1, T::m_unity());
    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];
    for (int i = p2 - 1; i > 0; --i) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = val;
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int idx, const OperatorMonoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = T::apply(dat[idx], val);
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) return;
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sub_apply(l++, val);
      if (r & 1) sub_apply(--r, val);
    }
    for (int i = left >> (left_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
    for (int i = right >> (right_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  Monoid get(int left, int right) {
    if (right <= left) return T::m_unity();
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    Monoid l_res = T::m_unity(), r_res = T::m_unity();
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = T::m_merge(l_res, dat[left++]);
      if (right & 1) r_res = T::m_merge(dat[--right], r_res);
    }
    return T::m_merge(l_res, r_res);
  }

  Monoid operator[](const int idx) {
    int node = idx + p2;
    for (int i = height; i > 0; --i) propagate(node >> i);
    return dat[node];
  }

  template <typename G>
  int find_right(int left, G g) {
    if (left >= n) return n;
    left += p2;
    for (int i = height; i > 0; --i) propagate(left >> i);
    Monoid val = T::m_unity();
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nx = T::m_merge(val, dat[left]);
      if (!g(nx)) {
        while (left < p2) {
          propagate(left);
          left <<= 1;
          nx = T::m_merge(val, dat[left]);
          if (g(nx)) {
            val = nx;
            ++left;
          }
        }
        return left - p2;
      }
      val = nx;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, G g) {
    if (right <= 0) return -1;
    right += p2;
    for (int i = height; i > 0; --i) propagate((right - 1) >> i);
    Monoid val = T::m_unity();
    do {
      --right;
      while (right > 1 && !(right & 1)) right >>= 1;
      Monoid nx = T::m_merge(dat[right], val);
      if (!g(nx)) {
        while (right < p2) {
          propagate(right);
          right = (right << 1) + 1;
          nx = T::m_merge(dat[right], val);
          if (g(nx)) {
            val = nx;
            --right;
          }
        }
        return right - p2;
      }
      val = nx;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

private:
  int n, p2, height = 0;
  std::vector<Monoid> dat;
  std::vector<OperatorMonoid> lazy;

  void sub_apply(int idx, const OperatorMonoid &val) {
    dat[idx] = T::apply(dat[idx], val);
    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx], val);
  }

  void propagate(int idx) {
    // assert(1 <= idx && idx < p2);
    sub_apply(idx << 1, lazy[idx]);
    sub_apply((idx << 1) + 1, lazy[idx]);
    lazy[idx] = T::o_unity();
  }
};

namespace monoid {
template <typename T>
struct RangeMinimumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr T m_unity() { return std::numeric_limits<T>::max(); }
  static constexpr T o_unity() { return std::numeric_limits<T>::max(); }
  static T m_merge(const T &a, const T &b) { return std::min(a, b); }
  static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
  static T apply(const T &a, const T &b) { return b == o_unity()? a : b; }
};

template <typename T>
struct RangeMaximumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr T m_unity() { return std::numeric_limits<T>::min(); }
  static constexpr T o_unity() { return std::numeric_limits<T>::min(); }
  static T m_merge(const T &a, const T &b) { return std::max(a, b); }
  static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
  static T apply(const T &a, const T &b) { return b == o_unity()? a : b; }
};

template <typename T, T TINF>
struct RangeMinimumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr T m_unity() { return TINF; }
  static constexpr T o_unity() { return 0; }
  static T m_merge(const T &a, const T &b) { return std::min(a, b); }
  static T o_merge(const T &a, const T &b) { return a + b; }
  static T apply(const T &a, const T &b) { return a + b; }
};

template <typename T, T TINF>
struct RangeMaximumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr T m_unity() { return -TINF; }
  static constexpr T o_unity() { return 0; }
  static T m_merge(const T &a, const T &b) { return std::max(a, b); }
  static T o_merge(const T &a, const T &b) { return a + b; }
  static T apply(const T &a, const T &b) { return a + b; }
};

template <typename T>
struct RangeSumAndUpdateQuery {
  struct Node {
    T sum;
    int len;
  };
  static std::vector<Node> init(int n) { return std::vector<Node>(n, Node{0, 1}); }
  using Monoid = Node;
  using OperatorMonoid = T;
  static constexpr Node m_unity() { return {0, 0}; }
  static constexpr T o_unity() { return std::numeric_limits<T>::max(); }
  static Node m_merge(const Node &a, const Node &b) { return Node{a.sum + b.sum, a.len + b.len}; }
  static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
  static Node apply(const Node &a, const T &b) { return Node{b == o_unity() ? a.sum : b * a.len, a.len}; }
};

template <typename T>
struct RangeSumAndAddQuery {
  struct Node {
    T sum;
    int len;
  };
  static std::vector<Node> init(int n) { return std::vector<Node>(n, Node{0, 1}); }
  using Monoid = Node;
  using OperatorMonoid = T;
  static constexpr Node m_unity() { return {0, 0}; }
  static constexpr T o_unity() { return 0; }
  static Node m_merge(const Node &a, const Node &b) { return Node{a.sum + b.sum, a.len + b.len}; }
  static T o_merge(const T &a, const T &b) { return a + b; }
  static Node apply(const Node &a, const T &b) { return Node{a.sum + b * a.len, a.len}; }
};
}  // monoid

int main() {
  int n, k, l; cin >> n >> k >> l;
  vector<int> x(n), y(n), c(n), ys{0, l}, xs{0, l};
  REP(i, n) {
    cin >> x[i] >> y[i] >> c[i]; --c[i];
    ys.emplace_back(y[i]);
    ys.emplace_back(y[i] + 1);
    xs.emplace_back(x[i]);
    xs.emplace_back(x[i] + 1);
  }
  sort(ALL(ys));
  ys.erase(unique(ALL(ys)), ys.end());
  int Y = ys.size();
  sort(ALL(xs));
  xs.erase(unique(ALL(xs)), xs.end());
  int X = xs.size();
  vector<vector<int>> ins(Y);
  REP(i, n) {
    y[i] = lower_bound(ALL(ys), y[i]) - ys.begin();
    x[i] = lower_bound(ALL(xs), x[i]) - xs.begin();
    ins[y[i]].emplace_back(i);
  }
  vector<int> prv(n, -1), nxt(n, -1);
  vector<vector<int>> looked(X);
  ModInt ans = 0;
  FOR(yu, 1, Y) {
    for (int look : ins[yu - 1]) {
      REP(i, X) {
        for (int e : looked[i]) {
          if (c[e] != c[look]) continue;
          if (x[look] <= x[e]) {
            if (prv[e] == -1 || x[prv[e]] < x[look]) prv[e] = look;
          }
          if (x[e] <= x[look]) {
            if (nxt[e] == -1 || x[look] < x[nxt[e]]) nxt[e] = look;
          }
        }
      }
    }
    for (int look : ins[yu - 1]) looked[x[look]].emplace_back(look);
    vector<monoid::RangeSumAndUpdateQuery<ll>::Monoid> f = monoid::RangeSumAndUpdateQuery<ll>::init(X);
    REP(i, X) f[i].sum = INF;
    map<int, int> candy;
    int j = 0;
    ModInt sum = 0;
    REP(i, X) {
      while (j < X && candy.size() < k) {
        for (int e : looked[j++]) ++candy[c[e]];
      }
      if (candy.size() == k) {
        assert(j < X);
        f[i].sum = xs[j];
        sum += ModInt(xs[i + 1] - xs[i]) * (l - xs[j] + 1);
      }
      for (int e : looked[i]) {
        --candy[c[e]];
        if (candy[c[e]] == 0) candy.erase(c[e]);
      }
    }
    LazySegmentTree<monoid::RangeSumAndUpdateQuery<ll>> seg(f);
    REP(yd, yu) {
      if (yd + 1 == yu && sum > 0) assert(ys[yd] + 1 == ys[yu]);
      // cout << '[' << ys[yd] << ',' << ys[yu] << "] " << sum << ' ' << (ys[yu] - ys[yu - 1]) * (ys[yd + 1] - ys[yd]) << " : ";
      // REP(i, X) cout << (seg[i].sum == INF ? -1 : seg[i].sum) << " \n"[i + 1 == X];
      ans += sum * (ys[yu] - ys[yu - 1]) * (ys[yd + 1] - ys[yd]);
      for (int e : ins[yd]) {
        int xl = prv[e] == -1 ? 0 : x[prv[e]] + 1, mx = nxt[e] == -1 ? INF : xs[x[nxt[e]]] + 1;
        int lb = xl - 1, ub = X;
        while (ub - lb > 1) {
          int mid = (lb + ub) >> 1;
          (seg[mid].sum < mx ? lb : ub) = mid;
        }
        while (xl <= lb) {
          ll val = seg[xl].sum;
          int r = min(seg.find_right(xl, [&](auto b) { return b.sum == val * b.len; }), lb + 1);
          sum -= ModInt(xs[r] - xs[xl]) * (l - val + 1);
          if (mx != INF) sum += ModInt(xs[r] - xs[xl]) * (l - mx + 1);
          seg.apply(xl, r, mx);
          xl = r;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}