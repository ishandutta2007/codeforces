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

void solve() {
  string s, t; cin >> s >> t;
  int n = s.length(), m = t.length();
  if (m == 1) {
    cout << (count(ALL(s), t[0]) > 0 ? "YES\n" : "NO\n");
    return;
  }
  FOR(del, 1, m) {
    vector<vector<int> > dp(n + 1, vector<int>(del + 1, -INF));
    dp[0][0] = del;
    REP(i, n) REP(j, del + 1) {
      if (dp[i][j] < del) continue;
      chmax(dp[i + 1][j], dp[i][j] + (dp[i][j] < m && s[i] == t[dp[i][j]]));
      if (j < del && s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j]);
    }
    if (dp[n][del] == m) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}