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
  string t; int n; cin >> t >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  const int l = t.length();
  vector<int> dp(l + 1, INF);
  dp[0] = 0;
  vector<pair<int, int>> prev(l + 1, {-1, -1});
  REP(i, l) {
    if (dp[i] == INF) continue;
    REP(j, n) {
      const int li = s[j].length();
      if (li <= l - i && t.substr(i, li) == s[j]) {
        FOR(k, 1, li + 1) {
          if (chmin(dp[i + k], dp[i] + 1)) prev[i + k] = {i, j};
        }
      }
    }
  }
  if (dp[l] == INF) {
    cout << "-1\n";
    return;
  }
  cout << dp[l] << '\n';
  for (int i = l; i > 0;) {
    const auto [pos, index] = prev[i];
    cout << index + 1 << ' ' << pos + 1 << '\n';
    i = pos;
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}