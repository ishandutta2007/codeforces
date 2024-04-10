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
  int n; cin >> n;
  vector<int> h(n), w(n);
  REP(i, n) {
    cin >> h[i] >> w[i];
    if (h[i] > w[i]) swap(h[i], w[i]);
  }
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int a, int b) { return make_pair(h[a], w[a]) < make_pair(h[b], w[b]); });
  vector<int> ans(n, -2);
  int fri = -1;
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && h[ord[i]] == h[ord[j]]) ++j;
    if (fri != -1) {
      FOR(k, i, j) {
        if (w[fri] < w[ord[k]]) ans[ord[k]] = fri;
      }
    }
    if (fri == -1 || w[ord[i]] < w[fri]) fri = ord[i];
    i = j;
  }
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}