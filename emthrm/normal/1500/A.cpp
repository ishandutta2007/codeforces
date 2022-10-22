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

int main() {
  constexpr int M = 2500000;
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int>> b(M + 1);
  REP(i, n) b[a[i]].emplace_back(i);
  vector<int> two;
  FOR(i, 1, M + 1) {
    if (b[i].size() >= 4) {
      cout << "YES\n";
      REP(j, 4) cout << b[i][j] + 1 << " \n"[j + 1 == 4];
      return 0;
    }
    if (b[i].size() >= 2) two.emplace_back(i);
  }
  if (two.size() >= 2) {
    cout << "YES\n";
    REP(i, 2) cout << b[two[0]][i] + 1 << ' ' << b[two[1]][i] + 1 << " \n"[i + 1 == 2];
    return 0;
  }
  int ignore1 = -1, ignore2 = -1;
  if (two.size() == 1) {
    for (int l = two[0] - 1, r = two[0] + 1; l >= 1 && r <= M; --l, ++r) {
      if (!b[l].empty() && !b[r].empty()) {
        cout << "YES\n";
        REP(i, 2) cout << b[two[0]][i] + 1 << ' ';
        cout << b[l][0] + 1 << ' ' << b[r][0] + 1 << '\n';
        return 0;
      }
    }
    ignore1 = b[two[0]][1];
    if (b[two[0]].size() == 3) ignore2 = b[two[0]][2];
  }
  vector<vector<int>> pigeon(M * 2 + 1);
  REP(i, n) {
    if (i == ignore1 || i == ignore2) continue;
    FOR(j, i + 1, n) {
      if (j == ignore1 || j == ignore2) continue;
      int sum = a[i] + a[j];
      if (!pigeon[sum].empty()) {
        cout << "YES\n";
        REP(i, 2) cout << pigeon[sum][i] + 1 << ' ';
        cout << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
      pigeon[sum].emplace_back(i);
      pigeon[sum].emplace_back(j);
    }
  }
  cout << "NO\n";
  return 0;
}