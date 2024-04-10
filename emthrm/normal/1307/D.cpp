#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(k); REP(i, k) cin >> a[i], --a[i];
  vector<vector<int> > graph(n);
  while (m--) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  vector<int> dist_1(n, INF), dist_n(n, INF);
  dist_1[0] = dist_n[n - 1] = 0;
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (dist_1[e] == INF) {
        dist_1[e] = dist_1[ver] + 1;
        que.emplace(e);
      }
    }
  }
  que.emplace(n - 1);
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (dist_n[e] == INF) {
        dist_n[e] = dist_n[ver] + 1;
        que.emplace(e);
      }
    }
  }
  sort(ALL(a), [&](int l, int r) { return dist_1[l] - dist_n[l] < dist_1[r] - dist_n[r]; });
  int ans = 0, mx = -INF;
  REP(i, k) {
    chmax(ans, mx + dist_n[a[i]] + 1);
    chmax(mx, dist_1[a[i]]);
  }
  cout << min(ans, dist_1[n - 1]) << '\n';
  return 0;
}