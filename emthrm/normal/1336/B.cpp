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
  int t; cin >> t;
  while (t--) {
    vector<int> n(3); REP(i, 3) cin >> n[i];
    vector<vector<int>> rgb(3);
    REP(i, 3) {
      rgb[i].resize(n[i]);
      REP(j, n[i]) cin >> rgb[i][j];
      sort(ALL(rgb[i]));
      rgb[i].erase(unique(ALL(rgb[i])), rgb[i].end());
      n[i] = rgb[i].size();
    }
    ll ans = LINF;
    REP(_, 3) {
      REP(i, n[0]) {
        int idx = lower_bound(ALL(rgb[1]), rgb[0][i]) - rgb[1].begin();
        int idx2 = lower_bound(ALL(rgb[2]), rgb[0][i]) - rgb[2].begin();
        for (int j = max(idx - 5, 0); j < min(idx + 5, n[1]); ++j) {
          for (int k = max(idx2 - 5, 0); k < min(idx2 + 5, n[2]); ++k) {
            vector<ll> now{rgb[0][i], rgb[1][j], rgb[2][k]};
            ll tmp = 0;
            REP(i, 3) tmp += (now[i] - now[(i + 1) % 3]) * (now[i] - now[(i + 1) % 3]);
            chmin(ans, tmp);
          }
        }
      }
      swap(n[0], n[1]); swap(n[1], n[2]);
      swap(rgb[0], rgb[1]); swap(rgb[1], rgb[2]);
    }
    cout << ans << '\n';
  }
  return 0;
}