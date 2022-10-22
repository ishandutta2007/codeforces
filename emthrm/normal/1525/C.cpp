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
  vector<int> x(n); REP(i, n) cin >> x[i];
  vector<char> c(n); REP(i, n) cin >> c[i];
  vector<ll> ans(n, -1);
  auto solve = [&](vector<int> &robot) -> void {
    if (robot.empty()) return;
    sort(ALL(robot), [&](int a, int b) -> bool { return x[a] < x[b]; });
    vector<int> sta{robot[0]};
    FOR(i, 1, robot.size()) {
      int id = robot[i];
      if (!sta.empty() && c[id] == 'L') {
        int ex = sta.back();
        sta.pop_back();
        ans[id] = ans[ex] = (x[id] - (c[ex] == 'L' ? -x[ex] : x[ex])) / 2;
      } else {
        sta.emplace_back(id);
      }
    }
    for (int i = int(sta.size()) - 2; i >= 0; i -= 2) {
      int a = sta[i], b = sta[i + 1];
      assert(c[b] == 'R');
      ans[a] = ans[b] = ((2 * m - x[b]) - (c[a] == 'L' ? -x[a] : x[a])) / 2;
    }
  };
  vector<int> robot[2];
  REP(i, n) robot[x[i] & 1].emplace_back(i);
  REP(i, 2) solve(robot[i]);
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}