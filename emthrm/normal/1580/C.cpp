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
  constexpr int B = 448;
  int n, m; cin >> n >> m;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  vector<int> op(m), k(m); REP(i, m) cin >> op[i] >> k[i], --k[i];
  vector<vector<int>> train(n);
  REP(i, m) train[k[i]].emplace_back(i);
  vector<int> ans(m + 1, 0);
  REP(i, n) {
    const int l = x[i] + y[i];
    if (l >= B) {
      if (train[i].size() % 2 == 1) train[i].emplace_back(m);
      for (int j = 1; j < train[i].size(); j += 2) {
        for (int k = train[i][j - 1]; ; k += l) {
          if (k + x[i] >= train[i][j]) break;
          ++ans[k + x[i]];
          if (k + l >= train[i][j]) {
            --ans[train[i][j]];
            break;
          }
          --ans[k + l];
        }
      }
    }
  }
  REP(i, m) ans[i + 1] += ans[i];
  vector<vector<int>> md(B);
  REP(i, B) md[i].assign(i, 0);
  vector<int> s(n, -1);
  REP(i, m) {
    const int l = x[k[i]] + y[k[i]];
    if (x[k[i]] + y[k[i]] < B) {
      if (op[i] == 1) {
        s[k[i]] = i;
        for (int j = (i + x[k[i]]) % l, d = 0; d < y[k[i]]; ++d) {
          ++md[l][j];
          if (++j == l) j = 0;
        }
      } else if (op[i] == 2) {
        for (int j = (s[k[i]] + x[k[i]]) % l, d = 0; d < y[k[i]]; ++d) {
          --md[l][j];
          if (++j == l) j = 0;
        }
      }
    }
    FOR(j, 2, B) ans[i] += md[j][i % j];
    cout << ans[i] << '\n';
  }
  return 0;
}