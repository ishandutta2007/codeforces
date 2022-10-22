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
  int n, m; cin >> n >> m;
  vector<int> w(n); REP(i, n) cin >> w[i];
  vector<int> x(m), y(m);
  vector<set<int>> g(n);
  REP(i, m) {
    cin >> x[i] >> y[i], --x[i], --y[i];
    --w[x[i]];
    --w[y[i]];
    g[x[i]].emplace(i);
    g[y[i]].emplace(i);
  }
  set<pair<int, int>> que;
  REP(i, n) que.emplace(w[i], i);
  vector<int> ans;
  while (!que.empty()) {
    auto [wei, idx] = *que.rbegin();
    que.erase(make_pair(wei, idx));
    if (wei < 0) {
      cout << "DEAD\n";
      return 0;
    }
    for (int e : g[idx]) {
      ans.emplace_back(e);
      int oth = x[e] == idx ? y[e] : x[e];
      g[oth].erase(e);
      que.erase(make_pair(w[oth], oth));
      ++w[oth];
      que.emplace(w[oth], oth);
    }
  }
  cout << "ALIVE\n";
  reverse(ALL(ans));
  REP(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
  return 0;
}