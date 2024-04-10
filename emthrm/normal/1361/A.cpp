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
  vector<vector<int>> graph(n);
  while (m--) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<int> t(n); REP(i, n) cin >> t[i];
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int a, int b) { return t[a] < t[b]; });
  REP(i, n) {
    int now = idx[i];
    vector<bool> exist(t[now], false);
    for (int e : graph[now]) {
      if (t[e] == t[now]) {
        cout << "-1\n";
        return 0;
      } else if (t[e] < t[now]) {
        exist[t[e]] = true;
      }
    }
    FOR(i, 1, t[now]) {
      if (!exist[i]) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  REP(i, n) cout << idx[i] + 1 << " \n"[i + 1 == n];
  return 0;
}