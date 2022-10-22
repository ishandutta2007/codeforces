#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  constexpr int X = 1000;
  vector<vector<int>> ans(X + 1);
  for (int i = 0; i * 3 <= X; ++i) for (int j = 0; i * 3 + j * 5 <= X; ++j) for (int k = 0; i * 3 + j * 5 + k * 7 <= X; ++k) {
    ans[i * 3 + j * 5 + k * 7] = {i, j, k};
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (ans[n].empty()) {
      cout << "-1\n";
    } else {
      REP(i, 3) cout << ans[n][i] << " \n"[i + 1 == 3];
    }
  }
  return 0;
}