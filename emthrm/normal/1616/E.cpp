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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery {
  FenwickTreeSupportingRangeAddQuery(int n_, const Abelian ID = 0) : n(n_), ID(ID) {
    ++n;
    dat_const.assign(n, ID);
    dat_linear.assign(n, ID);
  }

  void add(int left, int right, Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      dat_const[i] -= val * (left - 1);
      dat_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      dat_const[i] += val * right;
      dat_linear[i] -= val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat_const, dat_linear;
};

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

constexpr int C = 26;

void solve() {
  constexpr int inf = monoid::RangeMinimumQuery<int>::id();
  int n; string s, t; cin >> n >> s >> t;
  vector<int> pos[C]{};
  REP(i, n) pos[s[i] - 'a'].emplace_back(i);
  REP(i, C) reverse(ALL(pos[i]));
  SegmentTree<monoid::RangeMinimumQuery<int>> seg(C);
  REP(i, C) {
    if (!pos[i].empty()) seg.set(i, pos[i].back());
  }
  FenwickTreeSupportingRangeAddQuery<ll> bit(n);
  FOR(i, 1, n) bit.add(i, n, 1);
  vector<int> is_used(n, false);
  int p = 0;
  ll ans = LINF, cur = 0;
  REP(i, n) {
    while (is_used[p]) ++p;
    if (s[p] < t[i]) {
      chmin(ans, cur);
      break;
    }
    const int ti = t[i] - 'a';
    if (const int mn = seg.get(0, ti); mn != inf) chmin(ans, cur + bit[mn]);
    if (pos[ti].empty()) break;
    const int nxt = pos[ti].back();
    pos[ti].pop_back();
    seg.set(ti, pos[ti].empty() ? inf : pos[ti].back());
    cur += bit[nxt];
    bit.add(nxt + 1, n, -1);
    is_used[nxt] = true;
  }
  cout << (ans == LINF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}