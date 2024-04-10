#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_unity())) {}

  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2 << 1, T::o_unity());
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
    int ctz = __builtin_ctz(left);
    for (int i = height; i > ctz; --i) propagate(left >> i);
    ctz = __builtin_ctz(right);
    for (int i = height; i > ctz; --i) propagate(right >> i);
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

int solve(vector<int> &a, int mn, int mx) {
  int n = a.size();
  if (n == 0) return 0;
  mx -= n + 1;
  vector<int> b{mn};
  REP(i, n) {
    a[i] -= i + 1;
    if (mn <= a[i] && a[i] <= mx) b.emplace_back(a[i]);
  }
  if (b.size() == 1) return n;
  sort(ALL(b));
  b.erase(unique(ALL(b)), b.end());
  int m = b.size();
  LazySegmentTree<monoid::RangeMinimumAndAddQuery<int, INF>> seg(m);
  seg.set(0, 0);
  int ans = 0;
  REP(i, n) {
    if (mn <= a[i] && a[i] <= mx) {
      int idx = lower_bound(ALL(b), a[i]) - b.begin(), q = seg.get(0, idx + 1);
      seg.apply(0, m, 1);
      seg.set(idx, q);
    } else {
      ++ans;
    }
  }
  return seg.get(0, m) + ans;
}

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> b(k); REP(i, k) cin >> b[i], --b[i];
  FOR(i, 1, k) {
    if (a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) {
      cout << "-1\n";
      return 0;
    }
  }
  a.emplace_back(INF);
  b.emplace_back(n);
  int ans = 0;
  for (int i = 0, j = 0; j <= k; ++j) {
    vector<int> c;
    int x = i;
    while (x < b[j]) c.emplace_back(a[x++]);
    assert(x == b[j]);
    ans += solve(c, i == 0 ? -n * 2 : a[i - 1], a[x]);
    i = x + 1;
  }
  cout << ans << '\n';
  return 0;
}