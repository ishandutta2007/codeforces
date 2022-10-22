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
  constexpr int M = 10;
  int n, d; cin >> n >> d;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(M, -1.L));
  vector prev(n + 1, vector(M, make_pair(-1, false)));
  dp[0][1] = 0;
  REP(i, n) {
    REP(j, M) {
      if (dp[i][j] < 0) continue;
      int md = j * a[i] % M;
      if (dp[i][j] + log10(a[i]) > dp[i + 1][md]) {
        dp[i + 1][md] = dp[i][j] + log10(a[i]);
        prev[i + 1][md] = {j, true};
      }
    }
    REP(j, M) {
      if (dp[i][j] < 0) continue;
      if (dp[i][j] > dp[i + 1][j]) {
        dp[i + 1][j] = dp[i][j];
        prev[i + 1][j] = {j, false};
      }
    }
  }
  if (dp[n][d] < 0) {
    cout << "-1\n";
    return 0;
  }
  vector<int> card;
  int j = d;
  for (int i = n; i > 0; --i) {
    if (prev[i][j].second) card.emplace_back(a[i - 1]);
    j = prev[i][j].first;
  }
  if (card.empty()) {
    cout << "-1\n";
  } else {
    int k = card.size();
    cout << k << '\n';
    REP(i, k) cout << card[i] << " \n"[i + 1 == k];
  }
  return 0;
}