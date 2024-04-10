#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[300005];
bool used[300005];

pair<int, int> dfs(int v, int par) {
  pair<int, int> ret(0, v);
  used[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    if (u == par) continue;
    pair<int, int> p = dfs(u, v);
    p.first++;
    ret = max(ret, p);
  }
  return ret;
}

int color[300005], len[300005];

int repr(int x) {
  if (color[x] != x)
    color[x] = repr(color[x]);
  return color[x];
}

void join(int a, int b) {
  a = repr(a); b = repr(b);
  if (a != b) {
    // cout << "C: " << a << "  " << color[a] << endl;
    color[a] = color[b];

    len[b] = max((len[b] + 1) / 2 + (len[a] + 1) / 2 + 1, max(len[a], len[b]));
  }
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  
  for (int i = 0; i < n; ++i)
    color[i] = i;

  int a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    join(a, b);
  }

  for (int i = 0; i < n; ++i)
    len[i] = -1;

  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      pair<int, int> ret = dfs(i, -1);
      ret = dfs(ret.second, -1);
      len[repr(i)] = ret.first;
      // cout << repr(i) << "  " << ret.first << endl;
    }
  }

  // for (int i = 0; i < n; ++i)
  //   if (len[repr(i)] == -1)
  //     puts("fuck");

  int t;
  while (q--) {
    scanf("%d%d", &t, &a); --a;
    if (t == 1) {
      printf("%d\n", len[repr(a)]);
    } else {
      scanf("%d", &b); --b;
      join(a, b);
    }
  }
  return 0;
}