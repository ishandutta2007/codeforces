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

int main() {
  int n; cin >> n;
  vector<vector<pair<int, int> > > graph(n);
  REP(i, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v, i);
    graph[v].emplace_back(u, i);
  }
  int now = 0;
  vector<int> ans(n - 1, -1);
  REP(i, n) {
    if (graph[i].size() >= 3) {
      REP(j, 3) ans[graph[i][j].second] = now++;
      break;
    }
  }
  REP(i, n - 1) {
    if (ans[i] == -1) ans[i] = now++;
  }
  REP(i, n - 1) cout << ans[i] << '\n';
  return 0;
}