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

std::vector<std::vector<int>> subsequence_dp(
    const std::string& s, const char basis = 'a', const int sigma = 26) {
  const int n = s.length();
  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());
    nx[i][s[i] - basis] = i;
  }
  return nx;
}

template <typename T = std::string>
struct RollingHash {
  T s;

  explicit RollingHash(const T& s, const int base = 10007,
                       const int mod = 1000000007)
      : base(base), mod(mod), hash({0}), power({1}) {
    const int n = s.size();
    this->s.reserve(n);
    hash.reserve(n + 1);
    power.reserve(n + 1);
    add(s);
  }

  long long get(const int left, const int right) const {
    const long long res =
        hash[right] - hash[left] * power[right - left] % mod;
    return res < 0 ? res + mod : res;
  }

  void add(const T& t) {
    for (const auto c : t) {
      s.push_back(c);
      const int hash_nxt = (hash.back() * base % mod + c) % mod;
      hash.emplace_back(hash_nxt);
      const int power_nxt = power.back() * base % mod;
      power.emplace_back(power_nxt);
    }
  }

  int longest_common_prefix(const int i, const int j) const {
    const int n = s.size();
    int lb = 0, ub = n + 1 - std::max(i, j);
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

  template <typename U>
  int longest_common_prefix(const RollingHash<U>& t,
                            const int i, const int j) const {
    int lb = 0;
    int ub = std::min(static_cast<int>(s.size()) - i,
                      static_cast<int>(t.s.size()) - j)
             + 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

 private:
  const int base, mod;
  std::vector<long long> hash, power;
};

void solve() {
  int n, m; string s, t; cin >> n >> m >> s >> t;
  const auto nxt = subsequence_dp(s);
  vector<int> from_left(n, 0);
  for (int i = 0, j = 0; i < m; ++i) {
    const int r = (j < n ? nxt[j][t[i] - 'a'] : j);
    if (r == n) {
      cout << "-1\n";
      return;
    }
    for (; j < r; ++j) from_left[j] = i;
    from_left[j++] = i + 1;
  }
  for (auto it = find(ALL(from_left), m); it != from_left.end(); it = next(it)) {
    *it = m;
  }
  reverse(ALL(s));
  const auto txn = subsequence_dp(s);
  vector<int> from_right(n, 0);
  for (int i = 0, j = 0; i < m; ++i) {
    const int r = txn[j][t[m - 1 - i] - 'a'];
    assert(r < n);
    for (; j < r; ++j) from_right[n - 1 - j] = i;
    from_right[n - 1 - j++] = i + 1;
  }
  for (int i = 0; i < n && from_right[i] == 0; ++i) {
    from_right[i] = m;
  }
  reverse(ALL(s));
  const RollingHash hash_s(s), hash_t(t);
  int ans = n;
  REP(i, n) REP(j, m) {
    if ((i == 0 ? 0 : from_left[i - 1]) >= j && from_right[i] >= m - j) {
      const int len = hash_s.longest_common_prefix(hash_t, i, j);
      if (i == 0) {
        chmin(ans, n - (i + len));
      } else {
        chmin(ans, n - (i + len) + 1 + i + (i - j));
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}