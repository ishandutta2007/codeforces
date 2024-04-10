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

private:
  int n, p2 = 1;
  std::vector<Monoid> dat;
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

// https://twitter.com/noshi91/status/1306434160437817344
vector<int> range_mex_query(const vector<int> &a, const vector<int> &left, const vector<int> &right) {
  int n = a.size(), q = left.size();
  vector<vector<int>> l(n);
  REP(i, q) {
    if (right[i] > 0) l[right[i] - 1].emplace_back(i);
  }
  vector<int> res(q, 0);
  SegmentTree<monoid::RangeMinimumQuery<int>> seg(vector<int>(n, -1));
  REP(i, n) {
    if (a[i] < n) seg.set(a[i], i);
    for (int e : l[i]) res[e] = seg.find_right(0, [&](int x) { return x >= left[e]; });
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  if (count(ALL(a), 0) == n) {
    cout << 1 << '\n';
    return 0;
  }
  vector pos(n + 1, vector<int>{-1});
  REP(i, n) pos[a[i]].emplace_back(i);
  REP(i, n + 1) pos[i].emplace_back(n);
  vector<int> left, right, val;
  for (int mex = 1; mex <= n; ++mex) {
    for (int j = 0; j + 1 < pos[mex].size(); ++j) {
      left.emplace_back(pos[mex][j] + 1);
      right.emplace_back(pos[mex][j + 1]);
      val.emplace_back(mex);
    }
  }
  vector<bool> ans(n + 1, true);
  vector<int> rmq = range_mex_query(a, left, right);
  REP(i, val.size()) {
    if (rmq[i] == val[i]) ans[val[i]] = false;
  }
  for (int mex = 1; mex <= n; ++mex) {
    if (ans[mex]) {
      cout << mex + 1 << '\n';
      return 0;
    }
  }
  cout << n + 2 << '\n';
  return 0;
}