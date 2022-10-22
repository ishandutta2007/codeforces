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

// https://github.com/noshi91/Library/blob/0c144951896ea9272a0a8924b2033c01d0907de8/data_structure/range_mode_query.cpp
using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;
class range_mode_query {
  class b_node {
  public:
    usize value;
    usize rank;

    b_node(const usize value, const usize rank) : value(value), rank(rank) {}
  };

  class s_node {
  public:
    usize mode;
    usize freq;

    s_node(const usize mode, const usize freq) : mode(mode), freq(freq) {}
  };

  std::vector<b_node> b;
  std::vector<std::vector<usize>> q;
  std::vector<std::vector<s_node>> s;
  usize t;

public:
  range_mode_query() = default;

  range_mode_query(const std::vector<usize> a) : t(1) {
    const usize n = a.size();
    b.assign(n, b_node(0, 0));
    q.assign(n, {});
    while (t * t < n)
      t += 1;
    for (usize i = 0; i != n; i += 1) {
      const usize e = a[i];
      assert(e < n);
      b[i] = b_node(e, q[e].size());
      q[e].push_back(i);
    }
    s.assign(n / t + 1, std::vector<s_node>(n / t + 1, s_node(0, 0)));
    for (usize f = 0; f * t <= n; f += 1) {
      std::vector<usize> freq(n, 0);
      s_node cur(0, 0);
      for (usize l = f + 1; l * t <= n; l += 1) {
        for (usize i = (l - 1) * t; i != l * t; i += 1) {
          const usize e = a[i];
          freq[e] += 1;
          if (freq[e] > cur.freq)
            cur = s_node(e, freq[e]);
        }
        s[f][l] = cur;
      }
    }
  }

  usize query(const usize first, const usize last) const {
    assert(first < last);
    assert(last <= b.size());
    usize bf = first / t + 1;
    usize bl = last / t;
    if (bf >= bl) {
      s_node cur(0, 0);
      for (usize i = first; i != last; i += 1) {
        const b_node &e = b[i];
        const std::vector<usize> &v = q[e.value];
        usize idx;
        while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
          cur = s_node(e.value, cur.freq + 1);
      }
      return cur.freq;
      // return cur.mode;
    }
    s_node cur = s[bf][bl];
    for (usize i = first; i != bf * t; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
        cur = s_node(e.value, cur.freq + 1);
    }
    for (usize i = bl * t; i != last; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank - cur.freq) < v.size() && v[idx] >= first)
        cur = s_node(e.value, cur.freq + 1);
    }
    return cur.freq;
    // return cur.mode;
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<size_t> a(n); REP(i, n) cin >> a[i], --a[i];
  range_mode_query rmq(a);
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    int mode = rmq.query(l, r + 1), lb = 0, ub = r - l + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2, large = mode % mid, small = mid - large;
      (1LL * max(mode / mid - 1, 0) * small + 1LL * max((mode + mid - 1) / mid - 1, 0) * large <= r - l + 1 - mode ? ub : lb) = mid;
    }
    cout << ub << '\n';
  }
  return 0;
}