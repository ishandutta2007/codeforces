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

int main() {
  constexpr int M = 100000, P = 9592, B = 17;
  osa_k osa(M);
  vector<int> idx(M + 1, -1);
  int pos = 0;
  FOR(i, 2, M) {
    if (osa.smallest_prime_factor[i] == i) idx[i] = pos++;
  }
  int n, q; cin >> n >> q;
  vector<vector<int>> a(n);
  REP(i, n) {
    int ai; cin >> ai;
    for (auto [k, _] : osa.query(ai)) a[i].emplace_back(idx[k]);
  }
  vector dp(B, vector(n, n));
  vector<bool> pf(P, false);
  int r = 0;
  REP(i, n) {
    while (r < n) {
      bool is_valid = true;
      for (int p : a[r]) is_valid &= !pf[p];
      if (!is_valid) break;
      for (int p : a[r++]) pf[p] = true;
    }
    dp[0][i] = r - 1;
    for (int p : a[i]) pf[p] = false;
  }
  REP(i, B - 1) REP(j, n) dp[i + 1][j] = (dp[i][j] + 1 < n ? dp[i][dp[i][j] + 1] : n);
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    int lb = 0, ub = r - l + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2, left = l;
      REP(b, B) {
        if ((mid >> b & 1) && left < n) left = dp[b][left] + 1;
      }
      (left > r ? ub : lb) = mid;
    }
    cout << ub << '\n';
  }
  return 0;
}