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
  constexpr int A = 1000000;
  vector<int> is_prime = prime_sieve(A, false);

  int t; cin >> t;
  while (t--) {
    int n, e; cin >> n >> e;
    chmin(e, n);
    vector<vector<int>> a(e);
    REP(i, n) {
      int ai; cin >> ai;
      if (ai == 1) {
        a[i % e].emplace_back(0);
      } else if (is_prime[ai] == ai) {
        a[i % e].emplace_back(1);
      } else {
        a[i % e].emplace_back(2);
      }
    }
    ll ans = 0;
    for (const vector<int>& b : a) {
      int j = 0, one = -1;
      REP(i, b.size()) {
        chmax(j, i);
        for (; j < b.size() && (b[j] == 0 || (one == -1 && b[j] == 1)); ++j) {
          if (b[j] == 1) one = j;
        }
        if (one != -1) ans += j - max(one, i + 1);
        if (b[i] == 1) one = -1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}