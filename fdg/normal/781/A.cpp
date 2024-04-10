#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[200005];

int ans = 0, color[200005];

void go(int v, int p1, int p2) {
  int cur = 0;
  for (int u : g[v]) {
    if (color[u] == 0) {
      ++cur;
      while (cur == p1 || cur == p2) ++cur;
      color[u] = cur;
      go(u, cur, p1);

      ans = max(ans, cur);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  color[0] = 1;
  go(0, 1, -1);
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    cout << color[i] << " ";
  }
  cout << endl;

  return 0;
}