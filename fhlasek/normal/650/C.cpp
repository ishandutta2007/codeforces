/* Written by Filip Hlasek 2016 */
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

#define MAXN 1111111
int *A[MAXN], *vertex[MAXN];
int N, M;

int V = 0;
vector< pair<int, int> > vertex_cells[MAXN];
vector<int> graph[MAXN];
int indegree[MAXN], val[MAXN];

void join_vertices(int a, int b) {
  if (a == b) return;
  if (vertex_cells[a].size() > vertex_cells[b].size()) swap(a, b);
  REP(i, vertex_cells[a].size()) {
    vertex[vertex_cells[a][i].first][vertex_cells[a][i].second] = b;
    vertex_cells[b].push_back(vertex_cells[a][i]);
  }
  vertex_cells[a].clear();
}

vector<pair<int, int> > v;
queue<int> q;

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    A[i] = (int *) malloc(sizeof(int) * (M + 1));
    vertex[i] = (int *) malloc(sizeof(int) * (M + 1));
    REP(j, M) {
      scanf("%d", &(A[i][j]));
      vertex_cells[V].push_back(make_pair(i, j));
      vertex[i][j] = V++;
    }
  }
  REP(i, N) {
    v.clear();
    REP(j, M) v.push_back(make_pair(A[i][j], j));
    sort(v.begin(), v.end());
    REP(j, M) {
      while (j + 1 < M && v[j].first == v[j + 1].first) {
        join_vertices(vertex[i][v[j].second], vertex[i][v[j + 1].second]);
        j++;
      }
    }
  }
  REP(j, M) {
    v.clear();
    REP(i, N) v.push_back(make_pair(A[i][j], i));
    sort(v.begin(), v.end());
    REP(i, N) {
      while (i + 1 < N && v[i].first == v[i + 1].first) {
        join_vertices(vertex[v[i].second][j], vertex[v[i + 1].second][j]);
        i++;
      }
    }
  }

  REP(i, N) {
    v.clear();
    REP(j, M) v.push_back(make_pair(A[i][j], j));
    sort(v.begin(), v.end());
    REP(j, M) {
      while (j + 1 < M && v[j].first == v[j + 1].first) j++;
      if (j + 1 < M) graph[vertex[i][v[j].second]].push_back(vertex[i][v[j + 1].second]);
    }
  }
  REP(j, M) {
    v.clear();
    REP(i, N) v.push_back(make_pair(A[i][j], i));
    sort(v.begin(), v.end());
    REP(i, N) {
      while (i + 1 < N && v[i].first == v[i + 1].first) i++;
      if (i + 1 < N) graph[vertex[v[i].second][j]].push_back(vertex[v[i + 1].second][j]);
    }
  }

  REP(i, V) REP(j, graph[i].size()) indegree[graph[i][j]]++;

  REP(i, V) if (!indegree[i]) {
    val[i] = 1;
    q.push(i);
  }

  while (!q.empty()) {
    int v = q.front(); q.pop();
    REP(i, graph[v].size()) {
      int n = graph[v][i];
      indegree[n]--;
      val[n] = max(val[n], val[v] + 1);
      if (!indegree[n]) q.push(n);
    }
  }

  REP(i, N) {
    REP(j, M) {
      if (j) printf(" ");
      printf("%d", val[vertex[i][j]]);
    }
    printf("\n");
  }

  /*
  REP(i, N) {
    REP(j, M) printf(" %d", vertex[i][j]);
    printf("\n");
  }
  */

  return 0;
}