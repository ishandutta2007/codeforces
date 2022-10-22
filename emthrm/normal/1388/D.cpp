#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  vector<vector<int>> graph(n);
  REP(i, n) {
    cin >> b[i];
    if (b[i] != -1) {
      --b[i];
      if (b[i] == i) {
        b[i] = -1;
      } else {
        graph[b[i]].emplace_back(i);
      }
    }
  }
  vector<int> ope;
  vector<ll> dp(n);
  REP(i, n) dp[i] = a[i];
  REP(i, n) {
    if (b[i] != -1) continue;
    function<void(int)> dfs = [&](int ver) {
      for (int e : graph[ver]) {
        dfs(e);
        if (dp[e] >= 0) dp[ver] += dp[e];
      }
    };
    dfs(i);
    queue<int> que;
    que.emplace(i);
    while (!que.empty()) {
      int root = que.front(); que.pop();
      vector<int> ans{root};
      function<void(int)> dfs = [&](int ver) {
        for (int e : graph[ver]) {
          if (dp[e] >= 0) {
            ans.emplace_back(e);
            dfs(e);
          } else {
            que.emplace(e);
          }
        }
      };
      dfs(root);
      reverse(ALL(ans));
      for (int e : ans) ope.emplace_back(e);
    }
  }
  cout << accumulate(ALL(dp), 0LL) << '\n';
  REP(i, n) cout << ope[i] + 1 << " \n"[i + 1 == n];
  return 0;
}