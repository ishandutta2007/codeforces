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

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> dp{{-1, 0}};
  while (n--) {
    int a; cin >> a;
    if (dp.empty()) continue;
    vector<pair<int, int>> nxt{{a, 0}};
    int op = 0;
    do {
      a /= 2;
      ++op;
      nxt.emplace_back(a, op);
    } while (a > 0);
    while (!nxt.empty() && nxt.back().first <= dp.front().first) nxt.pop_back();
    int idx = dp.size() - 1;
    REP(i, nxt.size()) {
      while (dp[idx].first >= nxt[i].first) --idx;
      nxt[i].second += dp[idx].second;
    }
    reverse(ALL(nxt));
    FOR(i, 1, nxt.size()) {
      if (i > 0) chmin(nxt[i].second, nxt[i - 1].second);
    }
    dp.swap(nxt);
  }
  if (dp.empty()) {
    cout << "-1\n";
  } else {
    int ans = INF;
    for (const auto [_, op] : dp) chmin(ans, op);
    cout << ans << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}