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
struct SegmentTree {
  using Monoid = typename T::Monoid;

  SegmentTree(int n) : SegmentTree(std::vector<Monoid>(n, T::id())) {}

  SegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while (p2 < n) p2 <<= 1;
    dat.assign(p2 << 1, T::id());
    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];
    for (int i = p2 - 1; i > 0; --i) dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  void set(int idx, Monoid val) {
    idx += p2;
    dat[idx] = val;
    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx << 1) + 1]);
  }

  Monoid get(int left, int right) const {
    Monoid l_res = T::id(), r_res = T::id();
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
    Monoid val = T::id();
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
    Monoid val = T::id();
    right += p2;
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nx = T::merge(dat[right], val);
      if (!g(nx)) {
        while (right < p2) {
          right = (right << 1) + 1;
          nx = T::merge(dat[right], val);
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
  int n, p2 = 1;
  std::vector<Monoid> dat;
};

namespace monoid {
template <typename T>
struct RangeMinimumQuery {
  using Monoid = T;
  static constexpr T id() { return std::numeric_limits<T>::max(); }
  static T merge(const T &a, const T &b) { return std::min(a, b); }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr T id() { return std::numeric_limits<T>::lowest(); }
  static T merge(const T &a, const T &b) { return std::max(a, b); }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr T id() { return 0; }
  static T merge(const T &a, const T &b) { return a + b; }
};
}  // monoid

template <typename Semigroup, typename Fn>
struct DisjointSparseTable {
  DisjointSparseTable(const std::vector<Semigroup> &a, Fn fn) : fn(fn) {
    int n = a.size(), table_h = 1;
    while ((1 << table_h) < n) ++table_h;
    lg.assign(1 << table_h, 0);
    for (int i = 2; i < (1 << table_h); ++i) lg[i] = lg[i >> 1] + 1;
    dat.assign(table_h, std::vector<Semigroup>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) {
      int shift = 1 << i;
      for (int left = 0; left < n; left += shift << 1) {
        int mid = std::min(left + shift, n);
        dat[i][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= left; --j) dat[i][j] = fn(a[j], dat[i][j + 1]);
        if (n <= mid) break;
        int right = std::min(mid + shift, n);
        dat[i][mid] = a[mid];
        for (int j = mid + 1; j < right; ++j) dat[i][j] = fn(dat[i][j - 1], a[j]);
      }
    }
  }

  Semigroup query(int left, int right) const {
    assert(left < right);
    if (left == --right) return dat[0][left];
    int h = lg[left ^ right];
    return fn(dat[h][left], dat[h][right]);
  }

private:
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Semigroup>> dat;
};

int main() {
  int n; cin >> n;
  vector<int> h(n), b(n);
  REP(i, n) cin >> h[i];
  REP(i, n) cin >> b[i];
  DisjointSparseTable dst(h, [](int a, int b) { return min(a, b); });
  // vector<ll> dp(n, -LINF);
  // REP(j, n) REP(i, j + 1) chmax(dp[j], (i == 0 ? 0 : dp[i - 1]) + b[min_element(h.begin() + i, h.begin() + j + 1) - h.begin()]);
  // REP(i, n) cout << dp[i] << " \n"[i + 1 == n];
  SegmentTree<monoid::RangeMaximumQuery<ll>> seg(n);
  seg.set(0, b[0]);
  vector<int> sta{0};
  multiset<ll> st{b[0]};
  FOR(i, 1, n) {
    int l = -1, r = i;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      (dst.query(m, i + 1) == h[i] ? r : l) = m;
    }
    while (!sta.empty() && h[sta.back()] > h[i]) {
      st.erase(st.lower_bound(seg[sta.back()]));
      sta.pop_back();
    }
    ll v = (r == 0 ? max(seg.get(0, i), 0LL) : seg.get(r - 1, i)) + b[i];
    if (!sta.empty()) chmax(v, *st.rbegin());
    seg.set(i, v);
    sta.emplace_back(i);
    st.emplace(v);
  }
  // REP(i, n) cout << seg[i] << " \n"[i + 1 == n];
  cout << seg[n - 1] << '\n';
  return 0;
}