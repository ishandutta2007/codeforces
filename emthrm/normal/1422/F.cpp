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

std::vector<bool> sieve_of_eratosthenes(int val) {
  std::vector<bool> res(val + 1, true);
  res[0] = false;
  if (val >= 1) res[1] = false;
  for (int i = 2; i * i <= val; ++i) {
    if (res[i]) {
      for (int j = i * i; j <= val; j += i) res[j] = false;
    }
  }
  return res;
}

template <typename T>
std::vector<std::pair<T, int>> prime_factorization(T val) {
  std::vector<std::pair<T, int>> res;
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

template <typename T>
struct SegmentTree {
  using Monoid = typename T::Monoid;

  SegmentTree(int n) : SegmentTree(std::vector<Monoid>(n, T::unity())) {}

  SegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while (p2 < n) p2 <<= 1;
    dat.assign(p2 << 1, T::unity());
    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];
    for (int i = p2 - 1; i > 0; --i) dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  void set(int idx, Monoid val) {
    idx += p2;
    dat[idx] = val;
    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx << 1) + 1]);
  }

  Monoid get(int left, int right) const {
    Monoid l_res = T::unity(), r_res = T::unity();
    for (left += p2, right += p2; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = T::merge(l_res, dat[left++]);
      if (right & 1) r_res = T::merge(dat[--right], r_res);
    }
    return T::merge(l_res, r_res);
  }

  Monoid operator[](const int idx) const { return dat[idx + p2]; }

  template <typename G>
  int find_right(int left, G g) {
    if (left >= n) return n;
    Monoid val = T::unity();
    left += p2;
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nx = T::merge(val, dat[left]);
      if (!g(nx)) {
        while (left < p2) {
          left <<= 1;
          nx = T::merge(val, dat[left]);
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
    Monoid val = T::unity();
    right += p2;
    do {
      --right;
      while (right > 1 && !(right & 1)) right >>= 1;
      Monoid nx = T::merge(val, dat[right]);
      if (!g(nx)) {
        while (right < p2) {
          right = (right << 1) + 1;
          nx = T::merge(val, dat[right]);
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

  std::vector<Monoid> dat;
private:
  int n, p2 = 1;
};

namespace monoid {
template <typename T>
struct RangeMinimumQuery {
  using Monoid = T;
  static constexpr T unity() { return std::numeric_limits<T>::max(); }
  static T merge(const T &a, const T &b) { return std::min(a, b); }
  static auto find(const T &b) { return [&](const T &a) -> bool { return a > b; }; }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr T unity() { return std::numeric_limits<T>::min(); }
  static T merge(const T &a, const T &b) { return std::max(a, b); }
  static auto find(const T &b) { return [&](const T &a) -> bool { return a < b; }; }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr T unity() { return 0; }
  static T merge(const T &a, const T &b) { return a + b; }
};
}  // monoid

int main() {
  constexpr int M = 449;

  struct Node1 {
    using Monoid = struct {
      vector<pair<int, int>> ps;
      vector<ModInt> prod;
    };
    static Monoid unity() { return Monoid{}; }
    static Monoid merge(const Monoid &a, const Monoid &b) {
      Monoid res;
      std::merge(ALL(a.ps), ALL(b.ps), back_inserter(res.ps));
      ModInt cur = 1;
      for (const auto &[_, v] : res.ps) {
        cur *= v;
        res.prod.emplace_back(cur);
      }
      return res;
    }
  };

  int n; cin >> n;
  vector<vector<pair<int, int>>> cnt(n);
  vector<int> b(n, -1);
  REP(i, n) {
    int a; cin >> a;
    for (auto [p, e] : prime_factorization(a)) {
      if (p < M) {
        cnt[i].emplace_back(p, e);
      } else {
        b[i] = p;
      }
    }
  }

  struct Node2 {
    using Monoid = vector<pair<int, int>>;
    static Monoid unity() { return Monoid{}; }
    static Monoid merge(const Monoid &a, const Monoid &b) {
      vector<pair<int, int>> c;
      int a_pos = 0, b_pos = 0, a_size = a.size(), b_size = b.size();
      while (a_pos < a_size || b_pos < b_size) {
        if (a_pos == a_size) {
          while (b_pos < b_size) c.emplace_back(b[b_pos++]);
        } else if (b_pos == b_size) {
          while (a_pos < a_size) c.emplace_back(a[a_pos++]);
        } else if (a[a_pos].first == b[b_pos].first) {
          c.emplace_back(a[a_pos].first, max(a[a_pos].second, b[b_pos].second));
          ++a_pos;
          ++b_pos;
        } else if (a[a_pos].first < b[b_pos].first) {
          c.emplace_back(a[a_pos++]);
        } else {
          c.emplace_back(b[b_pos++]);
        }
      }
      assert(c.size() <= 86);
      return c;
    }
  };
  SegmentTree<Node2> dst(cnt);

  vector<Node1::Monoid> init(n);
  map<int, int> prev;
  REP(i, n) {
    if (b[i] != -1) {
      init[i].ps.emplace_back(prev.count(b[i]) == 1 ? prev[b[i]] : -1, b[i]);
      init[i].prod.emplace_back(b[i]);
      prev[b[i]] = i;
    }
  }
  SegmentTree<Node1> seg(init);
  auto query = [&](auto &&query, int node, int left, int right, int l, int r) -> ModInt {
    if (right <= l || r <= left) return 1;
    if (l <= left && right <= r) {
      int idx = lower_bound(ALL(seg.dat[node].ps), make_pair(l, 0)) - seg.dat[node].ps.begin();
      return idx > 0 ? seg.dat[node].prod[idx - 1] : 1;
    }
    return query(query, node << 1, left, (left + right) >> 1, l, r) * query(query, (node << 1) + 1, (left + right) >> 1, right, l, r);
  };

  int q; cin >> q;
  int last = 0;
  while (q--) {
    last %= n;
    int x, y; cin >> x >> y;
    int l = (last + x) % n, r = (last + y) % n;
    if (l > r) swap(l, r);
    ModInt ans = 1;
    for (auto [p, c] : dst.get(l, r + 1)) ans *= ModInt(p).pow(c);
    ans *= query(query, 1, 0, seg.dat.size() >> 1, l, r + 1);
    cout << ans << '\n';
    last = ans.val;
  }
  return 0;
}