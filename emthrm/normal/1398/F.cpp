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
  int n; string s; cin >> n >> s;
  vector cnt(2, vector(n + 1, 0));
  REP(i, 2) REP(j, n) cnt[i][j + 1] = cnt[i][j] + (s[j] - '0' == i);
  vector<vector<int>> pos(2);
  REP(i, n) {
    if (s[i] != '?') pos[s[i] - '0'].emplace_back(i);
  }
  vector ex(n, -1);
  REP(i, n) {
    if (i > 0) ex[i] = ex[i - 1];
    if (s[i] != '?') ex[i] = s[i] - '0';
  }
  FOR(x, 1, n + 1) {
    int ans = 0;
    for (int i = 0; i + x <= n;) {
      if (cnt[0][i + x] - cnt[0][i] > 0 && cnt[1][i + x] - cnt[1][i] > 0) {
        i = *prev(lower_bound(ALL(pos[ex[i + x - 1] ^ 1]), i + x)) + 1;
      } else {
        ++ans;
        i += x;
      }
    }
    cout << ans << " \n"[x == n];
  }
  return 0;
}