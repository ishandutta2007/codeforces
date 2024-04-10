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
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  if (s[0][0] == '1') {
    cout << "-1\n";
    return;
  }
  vector<tuple<int, int, int, int>> ans;
  for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
    if (s[i][j] == '1') {
      if (j > 0) {
        ans.emplace_back(i, j - 1, i, j);
      } else {
        assert(i > 0);
        ans.emplace_back(i - 1, j, i, j);
      }
    }
  }
  cout << ans.size() << '\n';
  for (const auto [y, u, k, i] : ans) {
    cout << y + 1 << ' ' << u + 1 << ' ' << k + 1 << ' ' << i + 1 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}