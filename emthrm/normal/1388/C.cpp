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
  int n, m; cin >> n >> m;
  vector<int> p(n), h(n);
  REP(i, n) cin >> p[i];
  REP(i, n) cin >> h[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1){
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  bool ans = true;
  function<pair<ll, ll>(int, int)> dfs = [&](int par, int ver) -> pair<ll, ll> {
    ll unh = p[ver], hap = 0;
    for (int e : graph[ver]) {
      if (e != par) {
        auto [ue, he] = dfs(ver, e);
        unh += ue;
        hap += he;
      }
    }
    ans &= h[ver] >= hap - unh && h[ver] <= unh + hap && abs(h[ver]) % 2 == abs(hap - unh) % 2;
    ll make = (h[ver] - (hap - unh)) / 2;
    unh -= make;
    hap += make;
    ans &= unh >= 0 && hap >= 0;
    // cout << ver << ": " << unh << ' ' << hap << '\n';
    return {unh, hap};
  };
  dfs(-1, 0);
  cout << (ans ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}