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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

constexpr int N = 3;

void solve() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];
  string s; cin >> s;
  vector<int> pos[2]{};
  REP(i, n) pos[s[i] - '0'].emplace_back(i);
  vector<int> ans(n);
  REP(i, 2) sort(ALL(pos[i]), [&](int a, int b) -> bool { return p[a] < p[b]; });
  REP(j, pos[0].size()) ans[pos[0][j]] = j;
  REP(j, pos[1].size()) ans[pos[1][j]] = pos[0].size() + j;
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}