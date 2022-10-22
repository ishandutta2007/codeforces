#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector a(n, vector(m, 0)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector mnr = a, mxr = a;
  for (int j = m - 2; j >= 0; --j) {
    REP(i, n) {
      chmin(mnr[i][j], mnr[i][j + 1]);
      chmax(mxr[i][j], mxr[i][j + 1]);
    }
  }
  vector<int> mnl(n, INF), mxl(n, 0);
  REP(j, m - 1) {
    REP(i, n) {
      chmin(mnl[i], a[i][j]);
      chmax(mxl[i], a[i][j]);
    }
    vector<int> id(n);
    iota(ALL(id), 0);
    sort(ALL(id), [&](int l, int r) -> bool {
      return mxl[l] != mxl[r] ? mxl[l] < mxl[r] : mnl[l] > mnl[r];
    });
    vector<int> mn_mnl(n, INF), mx_mxr(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      mn_mnl[i] = mnl[id[i]];
      mx_mxr[i] = mxr[id[i]][j + 1];
      if (i + 1 < n) {
        chmin(mn_mnl[i], mn_mnl[i + 1]);
        chmax(mx_mxr[i], mx_mxr[i + 1]);
      }
    }
    int mn_mnr = INF;
    REP(i, n - 1) {
      chmin(mn_mnr, mnr[id[i]][j + 1]);
      if (mxl[id[i]] < mn_mnl[i + 1] && mn_mnr > mx_mxr[i + 1]) {
        string ans(n, 'R');
        REP(x, i + 1) ans[id[x]] = 'B';
        cout << "YES\n" << ans << ' ' << j + 1 << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}