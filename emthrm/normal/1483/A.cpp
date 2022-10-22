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
  int n, m; cin >> n >> m;
  vector<int> must(n, 0), have(n, 0), ans(m, -1);
  vector<vector<int>> f(m), fri(n);
  REP(i, m) {
    int k; cin >> k;
    f[i].resize(k);
    REP(j, k) {
      cin >> f[i][j]; --f[i][j];
      ++have[f[i][j]];
    }
    if (k == 1) {
      ++must[f[i][0]];
      ans[i] = f[i][0];
    } else {
      REP(j, k) fri[f[i][j]].emplace_back(i);
    }
  }
  REP(i, n) {
    if (must[i] > (m + 1) / 2) {
      cout << "NO\n";
      return;
    }
  }
  int hard = -1;
  REP(i, n) {
    if (have[i] >= (m + 1) / 2) {
      hard = i;
      REP(j, (m + 1) / 2 - must[i]) ans[fri[i][j]] = i;
      break;
    }
  }
  REP(i, m) {
    if (ans[i] == -1) ans[i] = (f[i][0] == hard ? f[i][1] : f[i][0]);
  }
  cout << "YES\n";
  REP(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}