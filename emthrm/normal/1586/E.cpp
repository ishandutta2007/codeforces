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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct UnionFind {
  UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -data[root(ver)];
  }

private:
  std::vector<int> data;
};

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  UnionFind uf(n);
  while (m--) {
    int x, y; cin >> x >> y; --x; --y;
    if (uf.unite(x, y)) {
      graph[x].emplace_back(y);
      graph[y].emplace_back(x);
    }
  }
  vector<int> deg(n, 0);
  int q; cin >> q;
  vector<int> a(q), b(q), par(n, 0);
  REP(i, q) {
    cin >> a[i] >> b[i]; --a[i]; --b[i];
    par[a[i]] ^= 1;
    par[b[i]] ^= 1;
  }
  if (int one = count(ALL(par), 1); one == 0) {
    cout << "YES\n";
    REP(i, q) {
      vector<int> prev(n, -1);
      prev[b[i]] = -2;
      queue<int> que({b[i]});
      while (!que.empty()) {
        int ver = que.front(); que.pop();
        for (int e : graph[ver]) {
          if (prev[e] == -1) {
            prev[e] = ver;
            que.emplace(e);
          }
        }
      }
      vector<int> ans;
      for (int ver = a[i]; ver != b[i]; ver = prev[ver]) {
        ans.emplace_back(ver);
      }
      ans.emplace_back(b[i]);
      const int p = ans.size();
      cout << p << '\n';
      REP(i, p) cout << ans[i] + 1 << " \n"[i + 1 == p];
    }
  } else {
    cout << "NO\n" << one / 2 << '\n';
  }
  return 0;
}