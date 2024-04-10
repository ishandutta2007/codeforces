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
  constexpr int C = 3;
  int n, m; string s; cin >> n >> m >> s;
  vector<vector<int>> diff;
  REP(i, C) REP(j, C) {
    if (j == i) continue;
    const int k = i ^ j ^ C;
    vector<int> diff_i(n);
    REP(p, n) {
      if (p > 0) diff_i[p] = diff_i[p - 1];
      if (p % C == 0) {
        diff_i[p] += s[p] - 'a' != i;
      } else if (p % C == 1) {
        diff_i[p] += s[p] - 'a' != j;
      } else {
        diff_i[p] += s[p] - 'a' != k;
      }
    }
    diff.emplace_back(diff_i);
  }
  while (m--) {
    int l, r; cin >> l >> r; --l; --r;
    int ans = r - l + 1;
    for (const vector<int> &diff_i : diff) {
      chmin(ans, diff_i[r] - (l == 0 ? 0 : diff_i[l - 1]));
    }
    cout << ans << '\n';
  }
  return 0;
}