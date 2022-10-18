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

#define MAXN 3333
int N, M;
vector<int> graph[MAXN], rgraph[MAXN];
int Dist[MAXN];
queue<int> q;
stack<int> s;
vector< pair<int, int> > furthest[MAXN], rfurthest[MAXN];

void add(int v, int d) {
  if (Dist[v] <= d) return;
  Dist[v] = d;
  if (d) s.push(v);
  q.push(v);
}

void bfs() {
  REP(i, N) {
    while(!s.empty()) s.pop();
    REP(j, N) Dist[j] = MAXN;
    add(i, 0);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      REP(j, graph[v].size()) add(graph[v][j], Dist[v] + 1);
    }
    REP(j, 4) if (!s.empty()) {
      furthest[i].push_back(make_pair(s.top(), Dist[s.top()]));
      s.pop();
    }
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    rgraph[a].push_back(b);
    graph[b].push_back(a);
  }

  bfs();

  REP(i, N) swap(graph[i], rgraph[i]);
  REP(i, N) swap(rfurthest[i], furthest[i]);

  bfs();

  int best = 0;
  int A, B, C, D;

  REP(i, N) if (rfurthest[i].size()) {
    while(!s.empty()) s.pop();
    REP(j, N) Dist[j] = MAXN;
    add(i, 0);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      REP(j, graph[v].size()) add(graph[v][j], Dist[v] + 1);
    }
    REP(j, N) if (j != i && Dist[j] != MAXN && furthest[j].size()) {
      REP(_a, rfurthest[i].size()) REP(_b, furthest[j].size()) {
        int a = rfurthest[i][_a].first, da = rfurthest[i][_a].second;
        int b = furthest[j][_b].first, db = furthest[j][_b].second;
        if (a != j && a != b && b != i && best < Dist[j] + da + db) {
          best = Dist[j] + da + db;
          A = a; B = i; C = j; D = b;
        }
      }
    }
  }

  printf("%d %d %d %d\n", A + 1, B + 1, C + 1, D + 1);
  return 0;
}