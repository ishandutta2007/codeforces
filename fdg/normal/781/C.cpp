#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[200005], out[200005];
bool used[200005];

int MAX, id;

void push(int v) {
  if (out[id].size() == MAX) {
    ++id;
  }
  out[id].push_back(v + 1);
}

void dfs(int v) {
  push(v);

  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
      push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  MAX = (2 * n + k - 1) / k;

  dfs(0);

  for (int i = 0; i < k; ++i) {
    if (out[i].size() == 0) cout << "1 1" << endl;
    else {
      cout << out[i].size();
      for (int x : out[i])
        cout << " " << x;
      cout << endl;
    }
  }

  return 0;
}