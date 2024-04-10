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
  static constexpr T unity() { return std::numeric_limits<T>::max(); }
  static T merge(const T &a, const T &b) { return std::min(a, b); }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr T unity() { return std::numeric_limits<T>::min(); }
  static T merge(const T &a, const T &b) { return std::max(a, b); }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr T unity() { return 0; }
  static T merge(const T &a, const T &b) { return a + b; }
};
}  // monoid

int main() {
  struct Node {
    using Monoid = struct { double x, y, angle; };
    static Monoid unity() { return Monoid{0, 0, 0}; }
    static Monoid merge(const Monoid &a, const Monoid &b) {
      double x = a.x + cos(a.angle) * b.x - sin(a.angle) * b.y;
      double y = a.y + sin(a.angle) * b.x + cos(a.angle) * b.y;
      return Monoid{x, y, a.angle + b.angle};
    }
  };
  int n, q; cin >> n >> q;
  vector<int> len(n, 1), angle(n, 0);
  SegmentTree<Node> seg(n);
  REP(i, n) seg.set(i, Node::Monoid{1, 0, 0});
  while (q--) {
    int x, y, z; cin >> x >> y >> z; --y;
    if (x == 1) {
      len[y] += z;
    } else if (x == 2) {
      angle[y] -= z;
      if (angle[y] < 0) angle[y] += 360;
    }
    seg.set(y, Node::Monoid{len[y] * cos(angle[y] * M_PI / 180), len[y] * sin(angle[y] * M_PI / 180), angle[y] * M_PI / 180});
    auto ans = seg.get(0, n);
    cout << ans.x << ' ' << ans.y << '\n';
  }
  return 0;
}