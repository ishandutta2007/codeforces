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
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i], --a[i];
  REP(i, n) cin >> b[i], --b[i];
  vector<vector<int>> must(n);
  vector<int> same(n, -1);
  REP(i, n) {
    if (a[i] == b[i]) {
      same[b[i]] = i;
    } else {
      must[b[i]].emplace_back(i);
    }
  }
  vector<int> c(m);
  REP(i, m) cin >> c[i], --c[i];
  int decided = -1;
  vector<int> ans(m);
  for (int i = m - 1; i >= 0; --i) {
    if (must[c[i]].empty()) {
      if (decided == -1) {
        if (same[c[i]] == -1) {
          cout << "NO\n";
          return;
        }
        decided = same[c[i]];
        ans[i] = same[c[i]];
      } else {
        ans[i] = decided;
      }
    } else {
      decided = must[c[i]].back();
      ans[i] = must[c[i]].back();
      must[c[i]].pop_back();
    }
  }
  REP(i, n) {
    if (!must[i].empty()) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  REP(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}