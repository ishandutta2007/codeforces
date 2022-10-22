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

ll bin_search(const ll r, const function<ll(ll)> fn) {
  ll lb = 0, ub = min(r + 1, 1000000001LL);
  while (ub - lb > 1) {
    const ll mid = (lb + ub) / 2;
    (fn(mid) <= r ? lb : ub) = mid;
  }
  return lb;
}

const function<ll(ll)> fn1 = [](const ll n) -> ll { return n * n; };
const function<ll(ll)> fn2 = [](const ll n) -> ll { return n * (n + 1); };
const function<ll(ll)> fn3 = [](const ll n) -> ll { return n * (n + 2); };

// https://oeis.org/A006446
ll f(const ll n) {
  if (n == 0) return 0;
  return bin_search(n, fn1) + bin_search(n, fn2) + bin_search(n, fn3);
}

void solve() {
  ll l, r; cin >> l >> r;
  cout << f(r) - f(l - 1) << '\n';
}

int main() {
  // for (int i = 1; i <= N; ++i) {
  //   if (i % static_cast<int>(floor(sqrt(i))) == 0) cout << i << '\n';
  // }

  int t; cin >> t;
  while (t--) solve();
  return 0;
}