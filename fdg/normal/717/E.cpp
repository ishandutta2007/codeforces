#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int color[200002];
vector<int> g[200002];

void dfs(int v, int par) {
  if (par != -1) {
    color[v] *= -1;
    cout << v << " ";
  }

  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);

    color[v] *= -1;
    cout << v << " ";
    
    if (color[u] == -1) {
      color[u] *= -1;
      cout << u << " ";
      color[v] *= -1;
      cout << v << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> color[i];
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cout << 1 << " ";
  dfs(1, -1);
  if (color[1] == -1) {
    int x = g[1][0];
    cout << x << " " << 1 << " " << x;
  }
  cout << endl;
  return 0;
}