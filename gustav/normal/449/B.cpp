#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 100005

int N, M, K;
int u, v, x;
int s, y;

struct edge {
  int b, w;
  int type;
  edge() {}
  edge(int b, int w, int type) : b(b), w(w), type(type) {}
};

vector< edge > G[MAXN];
llint d[MAXN];

struct cmp {
  bool operator()(int a, int b) {
    if (d[a] == d[b]) return a < b;
    return d[a] < d[b];
  }
};

set< int, cmp > pq;

void dijkstra() {
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  pq.insert(1);

  while (!pq.empty()) {
    int n = *pq.begin();
    pq.erase(pq.begin());

    for (int i = 0; i < G[n].size(); ++i) {
      edge &E = G[n][i];
      if (d[E.b] > d[n] + E.w) {
        pq.erase(E.b);
        d[E.b] = d[n] + E.w;
        pq.insert(E.b);
      }
    }
  }
}

int in_deg[MAXN];

int main(void)
{
  scanf("%d%d%d", &N, &M, &K);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", &u, &v, &x);
    G[u].push_back(edge(v, x, 0));
    G[v].push_back(edge(u, x, 0));
  }

  for (int i = 0; i < K; ++i) {
    scanf("%d%d", &s, &y);
    G[1].push_back(edge(s, y, 1));
    G[s].push_back(edge(1, y, 1));
  }

  dijkstra();

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < G[i].size(); ++j) {
      edge &E = G[i][j];
      if (d[E.b] == d[i] + E.w && E.type == 0) {
        ++in_deg[E.b];
      }
    }
  }

  int must = -1;
  for (int i = 1; i <= N; ++i)
    must += (in_deg[i] == 0);

  printf("%d\n", K - must);

  return 0;
}