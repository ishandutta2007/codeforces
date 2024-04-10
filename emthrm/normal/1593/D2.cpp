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

struct Divisor {
  std::vector<int> smallest_prime_factor;

  Divisor(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<int> query(int n) {
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
    // std::sort(res.begin(), res.end());
    return res;
  }
};

constexpr int M = 2000000;
Divisor divisor(M);

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  const int need = (n + 1) / 2;
  int ans = 1;
  for (int i = 0; i + need <= n;) {
    int j = i + 1;
    while (j < n && a[j] == a[i]) ++j;
    if (j - i >= need) {
      cout << "-1\n";
      return;
    }
    map<int, int> m;
    FOR(k, j, n) {
      for (int d : divisor.query(a[k] - a[i])) ++m[d];
    }
    for (auto [k, num] : m) {
      if (j - i + num >= need) chmax(ans, k);
    }
    i = j;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}