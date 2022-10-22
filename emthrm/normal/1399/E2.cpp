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

void solve() {
  int n; ll s; cin >> n >> s;
  vector<int> u(n - 1), v(n - 1), w(n - 1), c(n - 1);
  vector<vector<int>> graph(n);
  REP(i, n - 1) {
    cin >> u[i] >> v[i] >> w[i] >> c[i]; --u[i]; --v[i];
    graph[u[i]].emplace_back(i);
    graph[v[i]].emplace_back(i);
  }
  vector<ll> c1, c2;
  ll cost = 0;
  function<int(int, int)> dfs = [&](int par, int ver) {
    int res = graph[ver].size() == 1 && ver != 0;
    for (int idx : graph[ver]) {
      int dst = u[idx] == ver ? v[idx] : u[idx];
      if (dst == par) continue;
      int d = dfs(ver, dst);
      res += d;
      ll co = 1LL * w[idx] * d;
      cost += co;
      while (co > 0) {
        (c[idx] == 1 ? c1 : c2).emplace_back(co - 1LL * (w[idx] / 2) * d);
        w[idx] /= 2;
        co = 1LL * w[idx] * d;
      }
    }
    return res;
  };
  dfs(-1, 0);
  int ans = INF;
  sort(ALL(c1), greater<ll>());
  sort(ALL(c2), greater<ll>());
  ll need = cost - s, sum = 0, idx1 = 0;
  for (; idx1 < c1.size(); ++idx1) {
    if (sum >= need) break;
    sum += c1[idx1];
  }
  if (sum >= need) ans = idx1;
  REP(idx2, c2.size()) {
    sum += c2[idx2];
    while (idx1 > 0 && sum - c1[idx1 - 1] >= need) sum -= c1[--idx1];
    if (sum >= need) chmin(ans, idx1 + (idx2 + 1) * 2);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}