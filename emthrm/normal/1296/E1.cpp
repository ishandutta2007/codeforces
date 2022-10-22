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
  int n; string s; cin >> n >> s;
  vector<vector<vector<bool> > > dp(n + 1, vector<vector<bool> >(27, vector<bool>(27, false)));
  vector<vector<vector<tuple<int, int> > > > prev(n + 1, vector<vector<tuple<int, int> > >(27, vector<tuple<int, int> >(27, {-1, -1})));
  dp[0][0][0] = true;
  FOR(i, 1, n + 1) {
    int c = s[i - 1] - 'a' + 1;
    REP(j, 27) {
      REP(y, c + 1) {
        if (dp[i - 1][j][y]) {
          dp[i][j][c] = true;
          prev[i][j][c] = {j, y};
        }
      }
    }
    REP(k, 27) {
      REP(x, c + 1) {
        if (dp[i - 1][x][k]) {
          dp[i][c][k] = true;
          prev[i][c][k] = {x, k};
        }
      }
    }
  }
  int sj = -1, sk = -1;
  REP(j, 27) {
    REP(k, 27) {
      if (dp[n][j][k]) {
        cout << "YES\n";
        sj = j;
        sk = k;
        break;
      }
    }
    if (sj != -1) break;
  }
  if (sj == -1) {
    cout << "NO\n";
    return 0;
  }
  vector<int> ans(n, -1);
  ans[n - 1] = (sj - 1 == s[n - 1] - 'a' ? 0 : 1);
  for (int i = n - 2; i >= 0; --i) {
    int nxj, nxk; tie(nxj, nxk) = prev[i + 2][sj][sk];
    ans[i] = (nxj - 1 == s[i] - 'a' ? 0 : 1);
    sj = nxj;
    sk = nxk;
  }
  REP(i, n) cout << ans[i];
  cout << '\n';
  return 0;
}