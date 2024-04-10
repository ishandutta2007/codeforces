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

std::vector<int> prime_sieve(int n, bool get_only_prime) {
  std::vector<int> prime, smallest_prime_factor(n + 1);
  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) prime.emplace_back(i);
    for (int p : prime) {
      if (i * p > n || p > smallest_prime_factor[i]) break;
      smallest_prime_factor[i * p] = p;
    }
  }
  return get_only_prime ? prime : smallest_prime_factor;
}

struct osa_k {
  std::vector<int> smallest_prime_factor;

  osa_k(int n = 10000000) : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<std::pair<int, int>> query(int n) const {
    std::vector<std::pair<int, int>> res;
    while (n > 1) {
      int prime = smallest_prime_factor[n], exponent = 0;
      while (smallest_prime_factor[n] == prime) {
        ++exponent;
        n /= prime;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }
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

int main() {
  constexpr int M = 10000000;
  osa_k osa(M);
  vector<int> last(M, -1);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n, 1);
    REP(i, n) {
      int ai; cin >> ai;
      for (auto [p, e] : osa.query(ai)) {
        if (e & 1) a[i] *= p;
      }
    }
    set<int> inc{-1};
    vector dp(k + 1, vector(n, INF));
    REP(i, n) {
      if (last[a[i]] != -1) inc.emplace(last[a[i]]);
      last[a[i]] = i;
      int add = 0;
      for (auto it = inc.rbegin(); it != inc.rend() && add <= k; ++it, ++add) {
        for (int j = 0; j + add <= k; ++j) {
          chmin(dp[j + add][i], (*it == -1 ? 0 : dp[j][*it]) + 1);
        }
      }
    }
    int ans = n;
    REP(j, k + 1) chmin(ans, dp[j][n - 1]);
    cout << ans << '\n';
    REP(i, n) last[a[i]] = -1;
  }
  return 0;
}