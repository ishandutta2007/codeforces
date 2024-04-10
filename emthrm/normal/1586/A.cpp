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

int main() {
  constexpr int M = 100 * 200;
  vector<int> is_prime = prime_sieve(M, false);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); REP(i, n) cin >> a[i];
    int s = accumulate(ALL(a), 0);
    if (is_prime[s] != s) {
      cout << n << '\n';
      REP(i, n) cout << i + 1 << " \n"[i + 1 == n];
    } else {
      REP(i, n) {
        if (is_prime[s - a[i]] != s - a[i]) {
          cout << n - 1 << '\n';
          vector<int> ans(n);
          iota(ALL(ans), 0);
          ans.erase(ans.begin() + i);
          REP(i, n - 1) cout << ans[i] + 1 << " \n"[i + 1 == n - 1];
          break;
        }
      }
    }
  }
  return 0;
}