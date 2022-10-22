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
  vector<string> s(n); REP(i, n) cin >> s[i];
  map<int, string> dp;
  dp[0] = "";
  REP(j, m) {
    map<int, string> nx;
    for (auto [used, t] : dp) {
      REP(i, n) {
        int use = used;
        string u = t + s[i][j];
        REP(k, n) {
          if (s[k][j] != s[i][j]) {
            if (used >> k & 1) {
              use = INF;
              break;
            }
            use |= 1 << k;
          }
        }
        if (use != INF) nx[use] = u;
      }
    }
    dp.swap(nx);
  }
  cout << (dp.empty() ? "-1" : dp.begin()->second) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}