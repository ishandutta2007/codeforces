#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[100005];
int deg[100005];
int cd[100005];

vector<int> ans;
bool used[100005];

int st = 0;

void go(int v) {
  cd[v] ^= 1;
  ans.push_back(v);
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      // cout << u << "  " << v << endl;
      go(u);
      cd[v] ^= 1;
      ans.push_back(v);
      if (cd[u] != deg[u]) {
        cd[u] ^= 1;
        cd[v] ^= 1;
        ans.push_back(u);
        ans.push_back(v);
      }
    }
  }
  if (v == st && deg[v] != cd[v]) {
    ans.pop_back();
    cd[v] ^= 1;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    // cout << a << "  " << b << endl;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &deg[i]);
    if (deg[i] & 1) st = i;
  }

  go(st);
  for (int i = 0; i < n; ++i)
    if (cd[i] != deg[i]) {
      puts("-1");
      return 0;
    }
  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  if (ans.size())
    printf("\n");
  return 0;
}