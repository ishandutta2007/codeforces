#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  while (m--) {
    int x, y; cin >> x >> y; --x; --y;
    graph[y].emplace_back(x);
  }
  vector dp(n, 0);
  vector usable(n, true);
  REP(i, n) {
    for (int e : graph[i]) {
      if (usable[e]) chmax(dp[i], dp[e] + 1);
    }
    if (dp[i] == 2) usable[i] = false;
  }
  vector<int> ans;
  REP(i, n) {
    if (!usable[i]) ans.emplace_back(i);
  }
  int k = ans.size();
  assert(k <= 4 * n / 7);
  cout << k << '\n';
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}