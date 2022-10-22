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

void solve() {
  int n, m; cin >> n >> m;
  vector<string> t(n); REP(i, n) cin >> t[i];
  string s; cin >> s;
  map<string, tuple<int, int, int>> seg2, seg3;
  REP(i, n) FOR(j, 1, m) seg2[t[i].substr(j - 1, 2)] = {j - 1, j, i};
  REP(i, n) FOR(j, 2, m) seg3[t[i].substr(j - 2, 3)] = {j - 2, j, i};
  vector<int> dp(m + 1, false), prev(m + 1, -1);
  dp[0] = true;
  REP(i, m) {
    if (!dp[i]) continue;
    if (i + 2 <= m && seg2.find(s.substr(i, 2)) != seg2.end()) {
      dp[i + 2] = true;
      prev[i + 2] = i;
    }
    if (i + 3 <= m && seg3.find(s.substr(i, 3)) != seg3.end()) {
      dp[i + 3] = true;
      prev[i + 3] = i;
    }
  }
  if (!dp[m]) {
    cout << "-1\n";
    return;
  }
  vector<tuple<int, int, int>> lri;
  for (int i = m; i > 0; i = prev[i]) {
    if (i - prev[i] == 2) {
      lri.emplace_back(seg2[s.substr(prev[i], 2)]);
    } else {
      lri.emplace_back(seg3[s.substr(prev[i], 3)]);
    }
  }
  reverse(ALL(lri));
  cout << lri.size() << '\n';
  for (const auto [l, r, i] : lri) {
    cout << l + 1 << ' ' << r + 1 << ' ' << i + 1 << '\n';
  }
}

void miss() {
  int n, m; cin >> n >> m;
  vector<string> t(n); REP(i, n) cin >> t[i];
  string s; cin >> s;
  map<int, int> dp;
  vector<vector<int>> ins(m + 1), era(m + 1);
  ins[0].emplace_back(0);
  era[0].emplace_back(0);
  vector<int> same(n, 0);
  REP(j, m) {
    for (int e : ins[j]) ++dp[e];
    REP(i, n) {
      if (same[i] < j) same[i] = j;
      while (same[i] < m && t[i][same[i]] == s[same[i]]) ++same[i];
    }
    if (!dp.empty()) {
      const int dp_j = dp.begin()->first;
      REP(i, n) {
        if (same[i] >= j + 2) {
          ins[j + 2].emplace_back(dp_j + 1);
          era[same[i]].emplace_back(dp_j + 1);
        }
      }
    }
    for (int e : era[j]) {
      if (--dp[e] == 0) dp.erase(e);
    }
  }
  for (int e : ins[m]) ++dp[e];
  cout << (dp.empty() ? -1 : dp.begin()->first) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}