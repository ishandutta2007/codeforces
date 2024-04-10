#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<vector<int> > g;
int arr[200002], L[200002], R[200002], LEV[200002];
vector<int> q;

void dfs(int v, int par = -1, int lev = 0) {
  L[v] = q.size(); LEV[v] = lev;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v, lev ^ 1);
  }
  q.push_back(v);
  R[v] = q.size() - 1;
}

int fen[2][200002];

void add(int f[], int x, int val) {
  for (; x < 200002; x |= (x + 1)) {
    f[x] += val;
  }
}

int find(int f[], int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    ret += f[x];
  }
  return ret;
}

void add(int f[], int l, int r, int x) {
  add(f, l, x);
  add(f, r + 1, -x);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  
  dfs(0);
  // for (int i = 0; i < n; ++i) {
  //   add(fen[LEV[i]], R[i], R[i] + 1, arr[i]);
  // }
  // for (int i = 0; i < q.size(); ++i)
  //   cout << L[i] << " " << R[i] << endl;

  for (int i = 0; i < m; ++i) {
    int t, x, val;
    scanf("%d%d", &t, &x); --x;
    if (t == 1) {
      scanf("%d", &val);
      add(fen[LEV[x]], L[x], R[x], val);
      add(fen[LEV[x] ^ 1], L[x], R[x], -val);
    } else {
      printf("%d\n", arr[x] + find(fen[LEV[x]], R[x]));
    }
  }
  return 0;
}