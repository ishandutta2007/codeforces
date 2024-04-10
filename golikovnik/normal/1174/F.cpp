#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::string;

int ask(string const& type, int u) {
  cout << type << " " << u + 1 << std::endl;
  int x;
  cin >> x;
  return x;
}

int const N = static_cast<int>(2e5) + 20;

vector<int> graph[N];
int d[N], sz[N], path_id[N];
vector<int> paths[N];
int ptr;

void dfs(int u, int p) {
  if (p >= 0) {
    d[u] = d[p] + 1;
  }
  sz[u] = 1;
  int big = -1;
  for (int v : graph[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    if (big < 0 || sz[v] > sz[big]) {
      big = v;
    }
    sz[u] += sz[v];
  }
  paths[path_id[u] = (big >= 0 ? path_id[big] : ptr++)].push_back(u);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(0, -1);
  int depth = ask("d", 0);
  int cur = 0;
  while (d[cur] != depth) {
    int head = paths[path_id[cur]][0];
    // depth + d[head] - 2 * d_lca = query
    // d_lca = (depth + d[head] - query) / 2
    int d_lca = (depth + d[head] - ask("d", head)) / 2;
    cur = paths[path_id[cur]][d[head] - d_lca];
    if (d[cur] == depth) {
      break;
    }
    cur = ask("s", cur) - 1;
  }
  cout << "! " << cur + 1 << std::endl;
  return 0;
}