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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
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
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::max(); }
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

ll f(const int n, const vector<int>& a) {
  vector<ll> b(n, 0);
  REP(i, n) {
    if (i > 0) b[i] = b[i - 1];
    if (i & 1) {
      b[i] -= a[i];
    } else {
      b[i] += a[i];
    }
  }
  vector<ll> even(n, LINF), odd(n, -LINF);
  for (int i = 0; i < n; i += 2) even[i] = b[i];
  for (int i = 1; i < n; i += 2) odd[i] = b[i];
  SegmentTree<monoid::RangeMinimumQuery<ll>> ev(even);
  SegmentTree<monoid::RangeMaximumQuery<ll>> od(odd);
  map<ll, deque<int>> pos;
  REP(i, n) pos[b[i]].emplace_back(i);
  ll cri = 0, ans = 0;
  for (int i = 0; i < n; i += 2) {
    int l = n;
    chmin(l, ev.find_right(i, [&](const ll x) -> bool { return x >= cri; }));
    chmin(l, od.find_right(i, [&](const ll x) -> bool { return x <= cri; }));
    if (pos.count(cri) == 1) {
      const deque<int>& que = pos[cri];
      int lb = -1, ub = que.size();
      while (ub - lb > 1) {
        const int mid = (lb + ub) >> 1;
        (que[mid] < l ? lb : ub) = mid;
      }
      ans += lb + 1;
    }
    cri += a[i];
    ev.set(i, LINF);
    pos[b[i]].pop_front();
    if (pos[b[i]].empty()) pos.erase(b[i]);
    if (i + 1 < n) {
      cri -= a[i + 1];
      od.set(i + 1, -LINF);
      pos[b[i + 1]].pop_front();
      if (pos[b[i + 1]].empty()) pos.erase(b[i + 1]);
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  ll ans = f(n, a);
  if (n > 1) {
    a.erase(a.begin());
    ans += f(n - 1, a);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}