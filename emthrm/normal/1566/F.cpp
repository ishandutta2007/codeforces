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
  static constexpr Monoid id() { return LINF; }
  static Monoid merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::lowest(); }
  static Monoid merge(const Monoid &a, const Monoid &b) { return std::max(a, b); }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return 0; }
  static Monoid merge(const Monoid &a, const Monoid &b) { return a + b; }
};
}  // monoid

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n), l, r;
  REP(i, n) cin >> a[i];
  sort(ALL(a));
  while (m--) {
    int li, ri; cin >> li >> ri;
    auto it = lower_bound(ALL(a), li);
    if (it != a.end() && *it <= ri) continue;
    l.emplace_back(li);
    r.emplace_back(ri);
  }
  m = l.size();
  if (m == 0) {
    cout << 0 << '\n';
    return;
  }
  vector<int> x(n + m + m);
  copy(ALL(a), x.begin());
  copy(ALL(l), x.begin() + n);
  copy(ALL(r), x.begin() + (n + m));
  sort(ALL(x));
  x.erase(unique(ALL(x)), x.end());
  const int s = x.size();
  REP(i, n) a[i] = lower_bound(ALL(x), a[i]) - x.begin();
  sort(ALL(a));
  REP(i, m) l[i] = lower_bound(ALL(x), l[i]) - x.begin();
  REP(i, m) r[i] = lower_bound(ALL(x), r[i]) - x.begin();

  vector<vector<int>> ls(s + 1);
  REP(i, m) ls[l[i]].emplace_back(i);
  SegmentTree<monoid::RangeMinimumQuery<ll>> seg(s + 1);
  int r_min = a[0];
  REP(pos, a[0]) {
    for (const int id : ls[pos]) {
      chmin(r_min, r[id]);
    }
  }
  seg.set(r_min, 0);
  REP(i, n) {
    const int left = (i == 0 ? r_min : a[i - 1] + 1), right = (i + 1 == n ? s : a[i + 1]);
    for (int pos = a[i] - 1; pos >= left; --pos) {
      seg.set(pos, seg[pos] + x[a[i]] - x[pos]);
    }
    multiset<int> rs;
    FOR(pos, a[i] + 1, right) {
      for (const int id : ls[pos]) {
        rs.emplace(r[id]);
      }
    }
    seg.set(rs.empty() ? right : *rs.begin(), seg.get(left, a[i] + 1));
    // cout << a[i] << endl << a[i] << ':';
    // REP(j, s + 1) cout << ' ' << (seg[j] >= LINF ? -1 : seg[j]);
    // cout << endl;
    int idx = a[i];
    FOR(pos, a[i] + 1, right) {
      for (const int id : ls[pos]) {
        rs.erase(rs.lower_bound(r[id]));
      }
      while (idx > left && x[pos] - x[a[i]] > x[a[i]] - x[idx - 1]) {
        --idx;
        seg.set(idx, seg[idx] + x[a[i]] - x[idx]);
      }
      const int nx = (rs.empty() ? right : *rs.begin());
      ll val = min(seg.get(idx, a[i] + 1) + x[pos] - x[a[i]], seg.get(left, idx) + (x[pos] - x[a[i]]) * 2);
      if (val < seg[nx]) seg.set(nx, val);
      // cout << pos << ':';
      // REP(j, s + 1) cout << ' ' << (seg[j] >= LINF ? -1 : seg[j]);
      // cout << endl;
    }
  }
  cout << seg[s] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}