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

int main() {
  constexpr ll N = 1000000000000;
  vector<ll> fact{6};
  for (int i = 4; fact.back() * i <= N; ++i) {
    const ll nxt = fact.back() * i;
    fact.emplace_back(nxt);
  }
  map<ll, int> dp;
  REP(b, 1 << fact.size()) {
    ll v = 0;
    REP(i, fact.size()) {
      if (b >> i & 1) v += fact[i];
    }
    if (v <= N) {
      if (!dp.count(v)) dp[v] = INF;
      chmin(dp[v], __builtin_popcount(b));
    }
  }

  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    int ans = INF;
    for (const auto [v, num] : dp) {
      if (v > n) break;
      chmin(ans, num + __builtin_popcountll(n - v));
    }
    cout << ans << '\n';
  }
  return 0;
}