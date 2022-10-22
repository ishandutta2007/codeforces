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
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> graph(n);
  vector<vector<pair<int, int>>> rev(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    graph[u].emplace_back(w);
    rev[v].emplace_back(u, w);
  }
  REP(i, n) sort(ALL(graph[i]));
  vector<vector<ll>> ng(k);
  vector<vector<int>> has(k), idx(k);
  REP(i, k) ng[i].resize(i + 1, 0);
  REP(i, k) has[i].resize(i + 1, 0);
  REP(i, k) idx[i].resize(i + 1, 0);
  int tmp = 0;
  REP(i, k) REP(j, i + 1) idx[i][j] = tmp++;
  REP(i, n) {
    if (rev[i].empty()) {
      cout << 0 << '\n';
      return 0;
    }
    vector<pair<int, int>> es;
    for (auto [e, w] : rev[i]) {
      int nth = lower_bound(ALL(graph[e]), w) - graph[e].begin();
      es.emplace_back(graph[e].size() - 1, nth);
    }
    sort(ALL(es));
    es.erase(unique(ALL(es)), es.end());
    reverse(ALL(es));
    ll b = 0;
    for (auto [deg, nth] : es) {
      ng[deg][nth] |= b;
      ++has[deg][nth];
      b |= 1LL << idx[deg][nth];
    }
  }
  // REP(i, k) REP(j, i + 1) cout << bitset<6>(ng[i][j]) << " \n"[j == i];
  // REP(i, k) REP(j, i + 1) cout << has[i][j] << " \n"[j == i];
  int ans = 0;
  function<void(int, ll, int)> dfs = [&](int c, ll ban, int have) {
    if (c == k) {
      ans += have == n;
      return;
    }
    REP(i, c + 1) {
      if (ban >> idx[c][i] & 1) continue;
      dfs(c + 1, ban | ng[c][i], have + has[c][i]);
    }
  };
  dfs(0, 0, 0);
  cout << ans << '\n';
  return 0;
}