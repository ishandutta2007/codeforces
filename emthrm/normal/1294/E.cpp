#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j], --a[i][j];
  int ans = 0;
  REP(j, m) {
    vector<int> shift(n, 0);
    REP(i, n) {
      if (a[i][j] % m != j || a[i][j] >= n * m) continue;
      int ideal = (a[i][j] - j) / m;
      ++shift[i >= ideal ? i - ideal : i + n - ideal];
    }
    int mn = INF;
    REP(i, n) chmin(mn, n - shift[i] + i);
    ans += mn;
    // REP(i, n) cout << shift[i] << ' ';
    // cout << '\n';
    // cout << ans << '\n';
  }
  cout << ans << '\n';
  return 0;
}