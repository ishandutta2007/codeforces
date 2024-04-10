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
  int n; cin >> n;
  vector<int> h(n); REP(i, n) cin >> h[i];
  map<int, vector<int>> mp1, mp2;
  REP(i, n) {
    mp1[-h[i]].emplace_back(i);
    mp2[h[i]].emplace_back(i);
  }
  set<int> st;
  vector<vector<int>> graph(n);
  for (auto [_, v] : mp1) {
    for (int idx : v) st.emplace(idx);
    for (int idx : v) {
      auto it = st.lower_bound(idx);
      if (it != st.begin()) graph[idx].emplace_back(*prev(it));
      if (next(it) != st.end()) graph[*next(it)].emplace_back(idx);
    }
  }
  st.clear();
  for (auto [_, v] : mp2) {
    for (int idx : v) st.emplace(idx);
    for (int idx : v) {
      auto it = st.lower_bound(idx);
      if (it != st.begin()) graph[idx].emplace_back(*prev(it));
      if (next(it) != st.end()) graph[*next(it)].emplace_back(idx);
    }
  }
  vector<int> dp(n, INF);
  dp[0] = 0;
  FOR(i, 1, n) {
    dp[i] = dp[i - 1] + 1;
    for (int e : graph[i]) chmin(dp[i], dp[e] + 1);
  }
  cout << dp[n - 1] << '\n';
  return 0;
}