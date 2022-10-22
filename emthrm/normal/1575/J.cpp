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
  int n, m, k; cin >> n >> m >> k;
  vector a(n, vector(m, 2)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<set<int>> not2(m);
  REP(i, n) REP(j, m) {
    if (a[i][j] != 2) not2[j].emplace(i);
  }
  REP(q, k) {
    int c; cin >> c; --c;
    int row = 0;
    while (row < n) {
      auto it = not2[c].lower_bound(row);
      if (it == not2[c].end()) break;
      row = *it;
      not2[c].erase(it);
      c += (a[row][c] == 1 ? 1 : -1);
    }
    cout << c + 1 << " \n"[q + 1 == k];
  }
  return 0;
}