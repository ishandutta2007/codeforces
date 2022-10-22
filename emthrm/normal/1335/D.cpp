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
  vector<vector<int>> nikoli(9, vector<int>(9));
  REP(i, 9) REP(j, 9) {
    char c; cin >> c;
    nikoli[i][j] = c - '0' - 1;
  }
  (nikoli[0][0] += 1) %= 9;
  (nikoli[1][3] += 1) %= 9;
  (nikoli[2][6] += 1) %= 9;
  (nikoli[3][1] += 1) %= 9;
  (nikoli[4][4] += 1) %= 9;
  (nikoli[5][7] += 1) %= 9;
  (nikoli[6][2] += 1) %= 9;
  (nikoli[7][5] += 1) %= 9;
  (nikoli[8][8] += 1) %= 9;
  REP(i, 9) {
    REP(j, 9) cout << nikoli[i][j] + 1;
    cout << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}