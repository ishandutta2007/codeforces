#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }

int main() {
  int n; cin >> n;
  vector c(n, vector(n, 0)); REP(i, n) REP(j, n) cin >> c[i][j];
  vector<ll> sum(n);
  REP(i, n) sum[i] = accumulate(ALL(c[i]), 0LL);
  vector dp1(n, vector(n, LINF)), dp2(n, vector(n, 0LL));
  vector prev(n, vector(n, -1));
  REP(j, n) {
    dp1[j][j] = 0;
    dp2[j][j] = sum[j];
    prev[j][j] = j;
    for (int i = j - 1; i >= 0; --i) {
      dp2[i][j] = dp2[i + 1][j] + sum[i];
      FOR(k, i + 1, j + 1) dp2[i][j] -= c[i][k] * 2;
      FOR(k, i, j + 1) {
        if (chmin(dp1[i][j], (i == k ? 0 : dp1[i][k - 1] + dp2[i][k - 1]) +
                             (k == j ? 0 : dp1[k + 1][j] + dp2[k + 1][j]))) {
          prev[i][j] = k;
        }
      }
    }
  }
  vector<int> ans(n, -1);
  queue<pair<int, int>> que({{0, n - 1}});
  while (!que.empty()) {
    const auto [i, j] = que.front(); que.pop();
    if (i == j) continue;
    const int root = prev[i][j];
    if (i < root) {
      ans[prev[i][root - 1]] = root;
      que.emplace(i, root - 1);
    }
    if (root < j) {
      ans[prev[root + 1][j]] = root;
      que.emplace(root + 1, j);
    }
  }
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}