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

const int N = 20;

void solve() {
  int n; string a, b; cin >> n >> a >> b;
  vector reach(N, 0);
  REP(i, n) {
    if (a[i] != b[i]) reach[a[i] - 'a'] |= 1 << (b[i] - 'a');
  }
  vector is_dag(1 << N, false);
  is_dag[0] = true;
  REP(mask, 1 << N) REP(u, N) {
    if (mask >> u & 1) is_dag[mask] = is_dag[mask] || is_dag[mask ^ (1 << u)] && ((mask & reach[u]) == 0);
  }
  vector dp(1 << N, 0);
  REP(i, 1 << N) {
    if (is_dag[i]) chmax(dp[i], __builtin_popcount(i));
    REP(j, N) {
      if (i >> j & 1) continue;
      chmax(dp[i | (1 << j)], dp[i]);
    }
  }
  vector visited(N, false);
  int ans = 0;
  REP(s, N) {
    visited[s] = true;
    int con = 1 << s;
    queue<int> que;
    que.emplace(s);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      REP(i, N) {
        if (!visited[i] && ((reach[ver] >> i & 1) || (reach[i] >> ver & 1))) {
          visited[i] = true;
          con |= 1 << i;
          que.emplace(i);
        }
      }
    }
    ans += __builtin_popcount(con) * 2 - dp[con] - 1;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}