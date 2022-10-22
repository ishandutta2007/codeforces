#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<vector<int>> idx(n);
  REP(i, n) idx[a[i]].emplace_back(i);
  vector<int> ans(n + 1, INF);
  REP(i, n) {
    if (idx[i].empty()) continue;
    int mx = 0;
    chmax(mx, idx[i].front() + 1);
    chmax(mx, n - 1 - idx[i].back() + 1);
    FOR(j, 1, idx[i].size()) chmax(mx, idx[i][j] - idx[i][j - 1]);
    chmin(ans[mx], i);
  }
  FOR(i, 2, n + 1) chmin(ans[i], ans[i - 1]);
  FOR(i, 1, n + 1) cout << (ans[i] == INF ? -1 : ans[i] + 1) << " \n"[i == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}