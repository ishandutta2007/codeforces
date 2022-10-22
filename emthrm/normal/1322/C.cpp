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
  vector<ll> c(n); REP(i, n) cin >> c[i];
  vector<vector<int> > graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
  }
  vector<set<int> > vers(1);
  REP(i, n) vers[0].emplace(i);
  vector<int> id(n, 0);
  int now = 1;
  REP(i, n) {
    if (graph[i].empty()) continue;
    vector<int> tar;
    for (int e : graph[i]) tar.emplace_back(id[e]);
    sort(ALL(tar));
    tar.erase(unique(ALL(tar)), tar.end());
    map<int, int> mp;
    REP(i, tar.size()) mp[tar[i]] = i;
    vers.resize(now + tar.size());
    for (int e : graph[i]) {
      vers[id[e]].erase(e);
      vers[now + mp[id[e]]].emplace(e);
      id[e] = now + mp[id[e]];
    }
    now += tar.size();
  }
  ll ans = 0;
  FOR(i, 1, vers.size()) {
    const set<int> &st = vers[i];
    if (st.empty()) continue;
    ll now = 0;
    for (int e : st) now += c[e];
    ans = ans == 0 ? now : __gcd(ans, now);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}