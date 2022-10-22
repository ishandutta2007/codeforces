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
  vector<vector<int>> a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j], --a[i][j];
  string s; cin >> s;
  int v[3]{0, 1, 2}, d[3]{};
  for (char c : s) {
    if (c == 'R') d[v[0]] = (d[v[0]] + 1) % n;
    if (c == 'L') d[v[0]] = (d[v[0]] + n - 1) % n;
    if (c == 'D') d[v[1]] = (d[v[1]] + 1) % n;
    if (c == 'U') d[v[1]] = (d[v[1]] + n - 1) % n;
    if (c == 'I') swap(v[0], v[2]);
    if (c == 'C') swap(v[1], v[2]);
  }
  vector ans(n, vector(n, -1));
  REP(i, n) REP(j, n) {
    int p[3]{(j + d[0]) % n, (i + d[1]) % n, (a[i][j] + d[2]) % n};
    ans[p[v[1]]][p[v[0]]] = p[v[2]];
  }
  REP(i, n) REP(j, n) cout << ans[i][j] + 1 << " \n"[j + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}