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
  int n, k; string s; cin >> n >> k >> s;
  int lb = 0, ub = n / k + 1;
  while (ub - lb > 1) {
    int f = (lb + ub) / 2;
    vector<vector<int>> pos(k);
    vector<int> cnt(k, 0);
    REP(i, f - 1) {
      if (s[i] != '?') ++cnt[s[i] - 'a'];
    }
    FOR(i, f - 1, n) {
      if (s[i] != '?') ++cnt[s[i] - 'a'];
      int ac = accumulate(ALL(cnt), 0);
      if (ac == 0) {
        REP(c, k) pos[c].emplace_back(i - (f - 1));
      } else {
        int cand = max_element(ALL(cnt)) - cnt.begin();
        if (cnt[cand] == ac) pos[cand].emplace_back(i - (f - 1));
      }
      if (s[i - (f - 1)] != '?') --cnt[s[i - (f - 1)] - 'a'];
    }
    vector<int> dp(1 << k, n + 1);
    dp[0] = 0;
    REP(b, 1 << k) REP(i, k) {
      if (b >> i & 1) continue;
      auto it = lower_bound(ALL(pos[i]), dp[b]);
      if (it != pos[i].end()) chmin(dp[b | (1 << i)], *it + f);
    }
    (dp[(1 << k) - 1] <= n ? lb : ub) = f;
  }
  cout << lb << '\n';
  return 0;
}