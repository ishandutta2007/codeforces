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

template <typename T>
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}

  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2, T::o_id());
    dat.assign(p2 << 1, T::m_id());
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
    if (right <= left) return T::m_id();
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    Monoid l_res = T::m_id(), r_res = T::m_id();
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
    Monoid val = T::m_id();
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
    Monoid val = T::m_id();
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
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
    lazy[idx] = T::o_id();
  }
};

namespace monoid {
template <typename T>
struct RangeMinimumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::max(); }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::max(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return b == o_id()? a : b; }
};

template <typename T>
struct RangeMaximumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::lowest(); }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::lowest(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::max(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return b == o_id()? a : b; }
};

template <typename T, T Inf>
struct RangeMinimumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return a + b; }
};

template <typename T, T Inf>
struct RangeMaximumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return -Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::max(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return a + b; }
};

template <typename T>
struct RangeSumAndUpdateQuery {
  using Monoid = struct {
    T sum;
    int len;
  };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(int n) { return std::vector<Monoid>(n, Monoid{0, 1}); }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::max(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return Monoid{b == o_id() ? a.sum : b * a.len, a.len}; }
};

template <typename T>
struct RangeSumAndAddQuery {
  using Monoid = struct {
    T sum;
    int len;
  };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(int n) { return std::vector<Monoid>(n, Monoid{0, 1}); }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return Monoid{a.sum + b * a.len, a.len}; }
};
}  // monoid

template <typename Abelian>
struct FenwickTree {
  FenwickTree(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat;
};

void solve() {
  int n; cin >> n;
  vector<int> b(n); REP(i, n) cin >> b[i];
  vector<int> c(b);
  sort(ALL(c));
  c.erase(unique(ALL(c)), c.end());
  int m = c.size();
  REP(i, n) b[i] = lower_bound(ALL(c), b[i]) - c.begin();
  FenwickTree<int> bit(m);
  LazySegmentTree<monoid::RangeSumAndUpdateQuery<int>> ngt(monoid::RangeSumAndUpdateQuery<int>::init(m));
  LazySegmentTree<monoid::RangeSumAndUpdateQuery<int>> nlt(monoid::RangeSumAndUpdateQuery<int>::init(m));
  bit.add(b[0], 1);
  FOR(i, 1, n) {
    int sum = ngt.get(b[i], m).sum;
    ngt.apply(b[i], m, 0);
    ngt.apply(b[i], b[i] + 1, sum);
    sum = nlt.get(0, b[i] + 1).sum;
    nlt.apply(0, b[i] + 1, 0);
    nlt.set(b[i], {sum, 1});
    int right = 2;
    for (; right > 0 && bit.sum(0, b[i] + 1) + ngt.get(0, b[i] + 1).sum < i; --right) {
      ngt.set(b[i], {ngt[b[i]].sum + 1, 1});
    }
    for (; right > 0 && bit.sum(b[i], m) + nlt.get(b[i], m).sum < i; --right) {
      nlt.set(b[i], {nlt[b[i]].sum + 1, 1});
    }
    if (bit.sum(0, b[i] + 1) + ngt.get(0, b[i] + 1).sum < i || bit.sum(b[i], m) + nlt.get(b[i], m).sum < i) {
      cout << "NO\n";
      return;
    }
    if (bit[b[i]] == 0) {
      if (right == 0) {
        cout << "NO\n";
        return;
      }
      --right;
      bit.add(b[i], 1);
    }
    for (; right > 0 && bit.sum(0, b[i] + 1) + ngt.get(0, b[i] + 1).sum <= i; --right) {
      ngt.set(b[i], {ngt[b[i]].sum + 1, 1});
    }
    for (; right > 0 && bit.sum(b[i], m) + nlt.get(b[i], m).sum <= i; --right) {
      nlt.set(b[i], {nlt[b[i]].sum + 1, 1});
    }
    if (bit.sum(0, b[i] + 1) + ngt.get(0, b[i] + 1).sum <= i || bit.sum(b[i], m) + nlt.get(b[i], m).sum <= i) {
      cout << "NO\n";
      return;
    }
    assert(right == 0);
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}