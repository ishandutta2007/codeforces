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

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<int> s(n); REP(i, n) cin >> s[i];
  vector<map<int, ll>> dp(n);
  const auto f = [&](auto&& f, const int ver, const int num) -> ll {
    if (num == 0) return 0;
    if (graph[ver].empty()) return 1LL * s[ver] * num;
    if (const auto it = dp[ver].find(num); it != dp[ver].end()) return it->second;
    const int c_size = graph[ver].size(), fl = num / c_size;
    ll ans = 0;
    if (num % c_size == 0) {
      for (const int child : graph[ver]) ans += f(f, child, fl);
    } else {
      const int ce = (num + c_size - 1) / c_size;
      vector<ll> diff(c_size);
      REP(i, c_size) {
        const ll x = f(f, graph[ver][i], fl), y = f(f, graph[ver][i], ce);
        ans += x;
        diff[i] = y - x;
      }
      sort(ALL(diff), greater<ll>());
      ans += accumulate(diff.begin(), next(diff.begin(), num % c_size), 0LL);
    }
    return dp[ver][num] = ans + 1LL * s[ver] * num;
  };
  cout << f(f, 0, k) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}