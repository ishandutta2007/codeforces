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
  int n, k; string s; cin >> n >> k >> s;
  vector<vector<int>> cnt(k, vector<int>(26, 0));
  REP(i, n) ++cnt[i % k][s[i] - 'a'];
  for (int i = 0; i < n - 1 - i; ++i) {
    int a = i % k, b = (n - 1 - i) % k;
    if (a > b) swap(a, b);
    if (a < b) {
      REP(j, 26) {
        cnt[a][j] += cnt[b][j];
        cnt[b][j] = 0;
      }
    }
  }
  int ans = 0;
  REP(i, k) ans += accumulate(ALL(cnt[i]), 0) - *max_element(ALL(cnt[i]));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}