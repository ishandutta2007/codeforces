#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct solver_t {
  int n;
  vector<vector<int>> adj;
  vector<int> color;
  vector<int> dominant;
  solver_t(int _n): n(_n), adj(n), color(n), dominant(n) {}
  int dfs(int v, int p) {
    int result = color[v];
    for (int u : adj[v])
      if (u != p) {
        int res = dfs(u, v);
        if (res != result)
          result = -1;
      }
    return dominant[v] = result;
  }
  int get_cand(int v, int p) {
    static vector<int> diffs; diffs.clear();
    if (color[v] != color[0])
      return v;
    for (int u : adj[v])
      if (u != p && dominant[u] != color[0])
        diffs.push_back(u);
    if (diffs.size() == 1) return get_cand(diffs[0], v);
    else return v;
  }
  int solve() {
    dfs(0, -1);

    if (dominant[0] == color[0]) {
      return 0;
    } else {
      int cand = get_cand(0, -1);
      dfs(cand, -1);
      bool ok = true;
      for (int u : adj[cand])
        if (dominant[u] != color[u]) {
          ok = false;
          break;
        }
      if (!ok)
        return -1;

      return cand;
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  solver_t solver(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.adj[a].push_back(b);
    solver.adj[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", &solver.color[i]);
  int result = solver.solve();
  if (result == -1) printf("NO\n");
  else printf("YES\n%d\n", result + 1);
  return 0;
}