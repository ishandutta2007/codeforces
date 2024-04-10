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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
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

  explicit SegmentTree(int n) : SegmentTree(std::vector<Monoid>(n, T::id())) {}

  explicit SegmentTree(const std::vector<Monoid>& a) : n(a.size()), p2(1) {
    while (p2 < n) p2 <<= 1;
    dat.assign(p2 << 1, T::id());
    std::copy(a.begin(), a.end(), dat.begin() + p2);
    for (int i = p2 - 1; i > 0; --i) {
      dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);
    }
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    dat[idx] = val;
    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx << 1) + 1]);
  }

  Monoid get(int left, int right) const {
    Monoid res_l = T::id(), res_r = T::id();
    for (left += p2, right += p2; left < right; left >>= 1, right >>= 1) {
      if (left & 1) res_l = T::merge(res_l, dat[left++]);
      if (right & 1) res_r = T::merge(dat[--right], res_r);
    }
    return T::merge(res_l, res_r);
  }

  Monoid operator[](const int idx) const { return dat[idx + p2]; }

  template <typename G>
  int find_right(int left, const G g) {
    if (left >= n) return n;
    Monoid val = T::id();
    left += p2;
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nxt = T::merge(val, dat[left]);
      if (!g(nxt)) {
        while (left < p2) {
          left <<= 1;
          nxt = T::merge(val, dat[left]);
          if (g(nxt)) {
            val = nxt;
            ++left;
          }
        }
        return left - p2;
      }
      val = nxt;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, const G g) {
    if (right <= 0) return -1;
    Monoid val = T::id();
    right += p2;
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nxt = T::merge(dat[right], val);
      if (!g(nxt)) {
        while (right < p2) {
          right = (right << 1) + 1;
          nxt = T::merge(dat[right], val);
          if (g(nxt)) {
            val = nxt;
            --right;
          }
        }
        return right - p2;
      }
      val = nxt;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

 private:
  const int n;
  int p2;
  std::vector<Monoid> dat;
};

namespace monoid {

template <typename T>
struct RangeMinimumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::max(); }
  static Monoid merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::lowest(); }
  static Monoid merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return 0; }
  static Monoid merge(const Monoid& a, const Monoid& b) { return a + b; }
};

}  // namespace monoid

int main() {
  int n, q; cin >> n >> q;
  vector<int> x(n), w(n); REP(i, n) cin >> x[i] >> w[i];
  const auto wd = [&](int i, int j) -> ll {
    if (i > j) swap(i, j);
    return 1LL * (x[j] - x[i]) * (w[i] + w[j]);
  };
  map<int, vector<int>> m;
  REP(i, n) m[w[i]].emplace_back(i);
  set<int> added;
  vector<vector<pair<int, ll>>> segments(n);
  for (const auto [_, points] : m) {
    copy(ALL(points), inserter(added, added.end()));
    for (int i : points) {
      const auto it = added.find(i);
      if (it != added.begin()) segments[i].emplace_back(*prev(it), wd(*prev(it), i));
      if (next(it) != added.end() && w[*next(it)] < w[i]) segments[*next(it)].emplace_back(i, wd(i, *next(it)));
    }
  }
  vector<int> l(q);
  vector<vector<int>> queries(n);
  REP(i, q) {
    int r; cin >> l[i] >> r; --l[i]; --r;
    queries[r].emplace_back(i);
  }
  SegmentTree<monoid::RangeMinimumQuery<ll>> dp(n);
  vector<ll> ans(q);
  REP(i, n) {
    for (const auto [li, wi] : segments[i]) {
      if (wi < dp[li]) dp.set(li, wi);
    }
    for (int id : queries[i]) ans[id] = dp.get(l[id], i + 1);
  }
  REP(i, q) cout << ans[i] << '\n';
  return 0;
}