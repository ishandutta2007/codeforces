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
  constexpr int M = 10000000;
  osa_k osa(M);
  vector<int> ans(M + 1, -1);
  for (int n = M - 1; n >= 1; --n) {
    if (!(n & 1) && 1 + 2 + n / 2 + n > M) continue;
    int d = 1;
    for (auto [p, e] : osa.query(n)) {
      int s = 1, tmp = 1;
      while (e--) {
        tmp *= p;
        s += tmp;
      }
      if (d > M / s) {
        d = M + 1;
        break;
      }
      d *= s;
    }
    if (d <= M) ans[d] = n;
  }

  int t; cin >> t;
  while (t--) {
    int c; cin >> c;
    cout << ans[c] << '\n';
  }
  return 0;
}