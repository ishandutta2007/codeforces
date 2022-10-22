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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  vector<int> est(n, n);
  REP(i, n) --est[(n + i - p[i]) % n];
  vector<int> ans;
  REP(k, n) {
    if ((est[k] + 1) / 2 > m) continue;
    vector<int> pos(n);
    REP(i, n) pos[p[i]] = i;
    vector<int> a = p;
    int sw = 0;
    REP(i, n) {
      int ideal = (n - k + i) % n;
      if (a[i] != ideal) {
        int memo = a[i];
        swap(a[i], a[pos[ideal]]);
        swap(pos[memo], pos[ideal]);
        ++sw;
      }
    }
    if (sw <= m) ans.emplace_back(k);
  }
  const int r = ans.size();
  if (r == 0) {
    cout << 0 << '\n';
  } else {
    cout << r << ' ';
    REP(i, r) cout << ans[i] << " \n"[i + 1 == r];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}