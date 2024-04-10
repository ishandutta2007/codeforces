#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
template <typename T, typename U>
inline void chmax(T &a, U b) { if (a < b) a = b; }
template <typename T, typename U>
inline void chmin(T &a, U b) { if (a > b) a = b; }

struct UnionFind {
  vector<int> data;

  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  int size(int ver) { return -data[root(ver)]; }
};

void solve() {
  int n, m, k; cin >> n >> m >> k;
  UnionFind uf(n);
  vector<int> x, y, s;
  int low_max = -INF;
  REP(i, m) {
    int xi, yi, si; cin >> xi >> yi >> si; --xi; --yi;
    if (si < k) {
      uf.unite(xi, yi);
      chmax(low_max, si);
    } else {
      x.emplace_back(xi);
      y.emplace_back(yi);
      s.emplace_back(si - k);
    }
  }
  ll ans = LINF;
  if (uf.size(0) == n) {
    chmin(ans, k - low_max);
    if (!s.empty()) chmin(ans, *min_element(ALL(s)));
  } else {
    vector<int> idx(s.size());
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](int a, int b) { return s[a] < s[b]; });
    ll cost = 0;
    REP(i, s.size()) {
      int cur = idx[i];
      if (uf.unite(x[cur], y[cur])) cost += s[cur];
    }
    chmin(ans, cost);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}