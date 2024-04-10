#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long long ll;
typedef long double ld;

struct ed {
  ll u = 0, v = 0;
  ll w = 0, lr = 0;
  ed() {};
};

int n;
vector <ed> edges;
vector <vector <int>> g;

void dfs(int v, vector <bool> &used, vector <ll> &sz) {
  sz[v] = 1;
  used[v] = true;
  for (int id : g[v]) {
    int u = (edges[id].u ^ edges[id].v ^ v);
    if (!used[u]) {
      dfs(u, used, sz);
      sz[v] += sz[u];
      edges[id].lr = sz[u] * (n - sz[u]);
    }
  }
}


int main() {
  cin >> n;
  g.resize(n);
  edges.resize(n - 1);
  for (int i = 0; i + 1 < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(i);
    g[v].push_back(i);
    edges[i].u = u, edges[i].v = v, edges[i].w = w;
  }
  vector <bool> used(n);
  vector <ll> sz(n);
  dfs(0, used, sz);
  ll div = (ll)n * (n - 1) / 2;
  ll sum = 0;
  for (auto &now : edges)
    sum += now.lr * now.w;
  int q;
  cin >> q;
  while (q--) {
    int id, val;
    cin >> id >> val;
    id--;
    sum -= edges[id].lr * edges[id].w;
    edges[id].w = val;
    sum += edges[id].lr * edges[id].w;
    cout << fsp(10) << 3 * (ld)sum / div << '\n';
  }
  return 0;
}