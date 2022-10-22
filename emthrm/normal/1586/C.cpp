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

int main() {
  int n, m; cin >> n >> m;
  vector s(n + 1, string(m, '.')); FOR(i, 1, n + 1) cin >> s[i];
  int q; cin >> q;
  vector<vector<int>> r(m);
  vector<int> x2(q);
  REP(i, q) {
    int x1; cin >> x1 >> x2[i]; --x1; --x2[i];
    r[x1].emplace_back(i);
  }
  vector<int> ans(q, false);
  for (int j = 0; j < m;) {
    vector<int> can_visit(n + 1, true);
    REP(i, n + 1) {
      if (s[i][j] == 'X') can_visit[i] = false;
    }
    int k = j + 1;
    for (; k < m; ++k) {
      FOR(i, 1, n + 1) {
        if (can_visit[i - 1] && s[i - 1][k] == '.') can_visit[i] = true;
      }
      if (count(ALL(can_visit), true) < n + 1) break;
      REP(i, n + 1) {
        if (s[i][k] == 'X') can_visit[i] = false;
      }
    }
    for (; j < k; ++j) {
      for (int id : r[j]) ans[id] = x2[id] < k;
    }
  }
  REP(i, q) cout << (ans[i] ? "YES\n" : "NO\n");
  return 0;
}