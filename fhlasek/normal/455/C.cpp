/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 333333
int father[MAXN], rank[MAXN], done[MAXN], D = 1;

int l1[MAXN], l2[MAXN];

int root(int x) { return father[x] == -1 ? x : (father[x] = root(father[x])); }

void DFU(int a, int b) {
  int ca = root(a), cb = root(b);
  if (ca == cb) return;
  if(rank[ca] < rank[cb])      father[ca] = cb;
  else if(rank[cb] < rank[ca]) father[cb] = ca;
  else {
    rank[ca]++;
    father[cb]=ca;
  }
}

int N;
vector<int> graph[MAXN];

int dist[MAXN], from[MAXN];
queue<int> q;

void add(int v, int d, int f) {
  if (done[v] == D) return;
  done[v] = D;
  from[v] = f;
  dist[v] = d;
  q.push(v);
}

int longest_path(int v) {
  int last;
  D++;
  add(v, 0, -1);
  while (!q.empty()) {
    int n = q.front(); q.pop();
    last = n;
    REP(i, graph[n].size()) add(graph[n][i], dist[n] + 1, n);
  }
  return last;
}

void init_center(int v) {
  int last = longest_path(longest_path(v));
  l1[v] = (dist[last] + 1) / 2;
  l2[v] = dist[last] / 2;
}

int main(int argc, char *argv[]) {
  int Q, M;
  scanf("%d%d%d", &N, &M, &Q);
  REP(i, N) { father[i] = -1; rank[i] = 0;  }
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    DFU(a, b);
  }
  REP(i, N) if (i == root(i)) init_center(i);
  while (Q--) {
    int type, x;
    scanf("%d%d", &type, &x); x--;
    if (type == 1) {
      int r = root(x);
      printf("%d\n", l1[r] + l2[r]);
    }
    else {
      int y;
      scanf("%d", &y); y--;
      int rx = root(x), ry = root(y);
      if (rx == ry) continue;

      int L1, L2, c;
      if (l1[rx] > l1[ry]) {
        L1 = l1[rx];
        L2 = max(l2[rx], l1[ry] + 1);
      }
      else if (l1[ry] > l1[rx]) {
        L1 = l1[ry];
        L2 = max(l2[ry], l1[rx] + 1);
      }
      else {
        L1 = l1[rx] + 1;
        L2 = l1[rx];
      }
      l1[rx] = l1[ry] = L1;
      l2[rx] = l2[ry] = L2;

      DFU(x, y);
    }
  }
  return 0;
}