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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  function<int(int, int, int)> solve = [&](int l, int r, int sub) {
    // if (r <= l) return;
    int mn = INF;
    FOR(i, l, r) chmin(mn, a[i] - sub);
    ll res = mn;
    for (int i = l; i < r;) {
      if (a[i] - sub == mn) {
        ++i;
        continue;
      }
      int j = i + 1;
      while (j < r && a[j] - sub > mn) ++j;
      res += solve(i, j, mn + sub);
      i = j;
    }
    return min(res, 1LL * r - l);
  };
  int ans = 0;
  for (int i = 0; i < n;) {
    if (a[i] == 0) {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && a[j] > 0) ++j;
    ans += solve(i, j, 0);
    i = j;
  }
  cout << ans << '\n';
  return 0;
}