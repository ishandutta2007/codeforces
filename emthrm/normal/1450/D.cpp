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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<vector<int>> pos(n);
  REP(i, n) pos[a[i]].emplace_back(i);
  string ans(n, '0');
  if (pos[0].empty()) {
    cout << ans << '\n';
    return;
  }
  ans[0] = '1';
  REP(i, n) {
    if (pos[i].size() != 1) ans[0] = '0';
  }
  int l = 0, r = n - 1;
  REP(i, n - 1) {
    if (pos[i].empty()) {
      cout << ans << '\n';
      return;
    }
    ans[n - 1 - i] = '1';
    if (pos[i].size() >= 2 || (l < pos[i][0] && pos[i][0] < r)) {
      cout << ans << '\n';
      return;
    }
    if (pos[i][0] == l) ++l;
    if (pos[i][0] == r) --r;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}