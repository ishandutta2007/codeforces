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
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<vector<int> > a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  int x = 0, y = 0, ans = 0;
  REP(bit, 1 << (m - 1)) {
    int lb = 0, ub = 1000000001;
    vector<int> v1, v2;
    REP(i, m) (bit >> i & 1 ? v1 : v2).emplace_back(i);
    int v1_mx = 0, v2_mx = 0, p = 0, q = 0;
    REP(i, n) {
      int mx = INF;
      for (int j : v1) chmin(mx, a[i][j]);
      if (mx > v1_mx) {
        v1_mx = mx;
        p = i;
      }
      mx = INF;
      for (int j : v2) chmin(mx, a[i][j]);
      if (mx > v2_mx) {
        v2_mx = mx;
        q = i;
      }
    }
    if (min(v1_mx, v2_mx) > ans) {
      ans = min(v1_mx, v2_mx);
      x = p;
      y = q;
    }
  }
  cout << x + 1 << ' ' << y + 1 << '\n';
  return 0;
}