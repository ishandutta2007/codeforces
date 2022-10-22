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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  string b; cin >> b;
  osa_k osa(*max_element(ALL(a)));
  vector<int> l(n);
  iota(ALL(l), 0);
  vector<map<int, int>> rem(n);
  REP(i, n) {
    if (b[i] == '*') continue;
    map<int, int> di;
    for (auto [p, ex] : osa.query(a[i])) di[p] = ex;
    while (!di.empty()) {
      if (--l[i] < 0) break;
      if (b[l[i]] == '/') {
        if (l[l[i]] == -1) {
          l[i] = -1;
          break;
        }
        if (rem[l[i]].size() < di.size()) {
          for (auto [p, ex_] : rem[l[i]]) {
            int ex = ex_;
            if (di.count(p) == 1) {
              int sub = min(di[p], ex);
              di[p] -= sub;
              ex -= sub;
              if (di[p] == 0) di.erase(p);
            }
            if (ex > 0) rem[i][p] += ex;
          }
        } else {
          for (auto it = di.begin(); it != di.end();) {
            const int p = it->first;
            if (rem[l[i]].count(p) == 1) {
              int sub = min(it->second, rem[l[i]][p]);
              it->second -= sub;
              rem[l[i]][p] -= sub;
              if (rem[l[i]][p] == 0) rem[l[i]].erase(p);
            }
            if (it->second == 0) {
              it = di.erase(it);
            } else {
              it = next(it);
            }
          }
          if (rem[l[i]].size() > rem[i].size()) swap(rem[l[i]], rem[i]);
          for (auto [p, ex] : rem[l[i]]) rem[i][p] += ex;
        }
        l[i] = l[l[i]];
      } else {
        for (auto [p, ex_] : osa.query(a[l[i]])) {
          int ex = ex_;
          if (di.count(p) == 1) {
            int sub = min(di[p], ex);
            di[p] -= sub;
            ex -= sub;
            if (di[p] == 0) di.erase(p);
          }
          if (ex > 0) rem[i][p] += ex;
        }
      }
    }
    if (l[i] == -1) rem[i].clear();
  }
  vector<ll> dp(n, 0);
  REP(i, n) {
    if (l[i] == -1) continue;
    dp[i] = (l[i] == 0 ? 0 : dp[l[i] - 1]) + 1;
  }
  cout << accumulate(ALL(dp), 0LL) << '\n';
  return 0;
}