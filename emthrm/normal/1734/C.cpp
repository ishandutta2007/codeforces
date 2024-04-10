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

struct Divisor {
  const std::vector<int> smallest_prime_factor;

  explicit Divisor(const int n)
      : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<int> query(int n) const {
    std::vector<int> res{1};
    while (n > 1) {
      const int prime_factor = smallest_prime_factor[n], d = res.size();
      int tmp = 1;
      for (; n % prime_factor == 0; n /= prime_factor) {
        tmp *= prime_factor;
        for (int i = 0; i < d; ++i) {
          res.emplace_back(res[i] * tmp);
        }
      }
    }
    std::sort(res.begin(), res.end());
    return res;
  }
};

int main() {
  Divisor divisor(1000000);

  int t; cin >> t;
  while (t--) {
    int n; string t; cin >> n >> t;
    vector<int> flag(n + 1, true);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (t[i - 1] == '0') {
        for (const int d : divisor.query(i)) {
          if (flag[d]) {
            ans += d;
            break;
          }
        }
      } else {
        for (const int d : divisor.query(i)) {
          flag[d] = false;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}