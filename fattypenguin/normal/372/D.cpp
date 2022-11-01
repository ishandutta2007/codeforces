#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cassert>
#include <queue>
#include <vector>
#define FILL(x, c) memset(x, c, sizeof(x))
#define PB push_back
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(it, n) for (__typeof(n.begin()) it = n.begin(); it != n.end(); ++it)

const int INF = 0x3F3F3F3F;

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;
typedef vector<int> VI;

const int N = 150007, M = 20;

int fa[N][M];
int depth[N];

VI adj[N];

int n, k, timeStamp = 0;
int colored[N];
int dfsOrder[N], atDfsOrder[N];

int lca(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  for (int i = M - 1; i >= 0; --i) {
    if (fa[x][i] != -1 && depth[fa[x][i]] >= depth[y]) {
      x = fa[x][i];
    }
  }
  if (x == y) return x;
  for (int i = M - 1; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}

int dis(int x, int y) {
  return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

set<int> orders;

void push(int x, int &cost) {
  if (!orders.size()) {
    orders.insert(dfsOrder[x]);
    return;
  }
  int node1, node2;
  set<int>::iterator si = orders.lower_bound(dfsOrder[x]);
  if (si == orders.end()) si = orders.begin();
  node1 = atDfsOrder[*si];
  si = orders.lower_bound(dfsOrder[x]);
  if (si == orders.begin()) {
    si = orders.end();
  }
  --si;
  node2 = atDfsOrder[*si];
  orders.insert(dfsOrder[x]);
  cost += dis(x, node1) + dis(x, node2) - dis(node1, node2);
  // cout << "x = " << x << " node1 = " << node1 << " node2 = " << node2 << " cost = " << dis(x, node1) + dis(x, node2) - dis(node1, node2) << endl;;
}

void pop(int x, int &cost) {
  orders.erase(orders.find(dfsOrder[x]));
  if (!orders.size()) return;
  int node1, node2;
  set<int>::iterator si = orders.lower_bound(dfsOrder[x]);
  if (si == orders.end()) si = orders.begin();
  node1 = atDfsOrder[*si];
  si = orders.lower_bound(dfsOrder[x]);
  if (si == orders.begin()) {
    si = orders.end();
  }
  --si;
  node2 = atDfsOrder[*si];
  cost -= dis(x, node1) + dis(x, node2) - dis(node1, node2);
}

int go() {
  int connected = 0;
  orders.clear();
  int left = 0, ans = 1;
  REP(i, n) {
    push(i, connected);
    while (left <= i && connected / 2 + 1 > k) pop(left++, connected);
    ans = max(ans, i - left + 1);
  }
  return ans;
}

void build(int x, int father) {
  // cout << "-1";
  dfsOrder[x] = timeStamp++;
  atDfsOrder[timeStamp - 1] = x;
  if (father == -1) {
    depth[x] = 0;
  } else {
    depth[x] = depth[father] + 1;
  }
  fa[x][0] = father;
  for (int i = 1; i < M; ++i) {
    fa[x][i] = -1;
    if (fa[x][i - 1] != -1) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
  }
  TR(it, adj[x]) {
    if (*it != father) {
      build(*it, x);
    }
  }
}

int main() {
  cin >> n >> k;
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  build(0, -1);
  cout << go() << endl;
  return 0;
}