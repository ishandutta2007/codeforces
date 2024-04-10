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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

std::vector<int> prime_sieve(const int n, const bool get_only_prime) {
  std::vector<int> smallest_prime_factor(n + 1), prime;
  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) prime.emplace_back(i);
    for (const int p : prime) {
      if (i * p > n || p > smallest_prime_factor[i]) break;
      smallest_prime_factor[i * p] = p;
    }
  }
  return get_only_prime ? prime : smallest_prime_factor;
}

struct OsaK {
  const std::vector<int> smallest_prime_factor;

  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<std::pair<int, int>> query(int n) const {
    std::vector<std::pair<int, int>> res;
    while (n > 1) {
      const int prime = smallest_prime_factor[n];
      int exponent = 0;
      for (; smallest_prime_factor[n] == prime; n /= prime) {
        ++exponent;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }
};

int main() {
  constexpr int N = 200000;
  OsaK osa_k(N);
  vector<int> ds[N + 1]{};

  int a[N], p[N], x[N];
  ll ans[N + 1];
  int b[N];
  vector<ll> scores;
  multiset<ll> s;

  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    REP(i, n) cin >> a[i];
    REP(i, q) cin >> p[i] >> x[i], --p[i];
    if (ds[n].empty()) {
      for (const auto& [p, _] : osa_k.query(n)) {
        ds[n].emplace_back(n / p);
      }
    }
    fill(ans, ans + (q + 1), 0);
    for (const int d : ds[n]) {
      copy(a, a + n, b);
      scores.assign(d, 0);
      for (int i = 0, j = 0; i < n; ++i, ++j) {
        if (j == d) j = 0;
        scores[j] += b[i];
      }
      s = multiset<ll>(ALL(scores));
      chmax(ans[0], *s.rbegin() * d);
      REP(i, q) {
        const int idx = p[i] % d;
        s.erase(s.find(scores[idx]));
        scores[idx] += x[i] - b[p[i]];
        s.emplace(scores[idx]);
        chmax(ans[i + 1], *s.rbegin() * d);
        b[p[i]] = x[i];
      }
    }
    REP(i, q + 1) cout << ans[i] << '\n';
  }
  return 0;
}