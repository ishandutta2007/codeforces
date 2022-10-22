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
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  int ans = 0;
  vector dp(n, vector(2, 0));
  function<void(int, int)> rec = [&](int par, int ver) {
    dp[ver][true] = 1;
    vector<int> fal, mx;
    for (int e : graph[ver]) {
      if (e == par) continue;
      rec(ver, e);
      fal.emplace_back(dp[e][false]);
      mx.emplace_back(*max_element(ALL(dp[e])));
    }
    sort(ALL(fal), greater<int>());
    if (!fal.empty()) dp[ver][true] += fal[0];
    sort(ALL(mx), greater<int>());
    if (!mx.empty()) dp[ver][false] = mx[0] + mx.size() - 1;
    if (fal.size() >= 2) chmax(ans, fal[0] + fal[1] + 1);
    if (mx.size() >= 2) chmax(ans, mx[0] + mx[1] + mx.size() - 2 + (par != -1));
  };
  rec(-1, 0);
  cout << max(ans, *max_element(ALL(dp[0]))) << '\n';
  return 0;
}