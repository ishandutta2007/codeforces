/* Written by Filip Hlasek 2015 */
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

#define MAXN 555222
vector<int> graph[MAXN], Index[MAXN];

void add_edge(int a, int b) {
  if (a == b) {
    int i = graph[a].size();
    Index[a].push_back(i + 1);
    Index[a].push_back(i);
    graph[a].push_back(a);
    graph[a].push_back(a);
  }
  else {
    Index[a].push_back(graph[b].size());
    graph[b].push_back(a);
    Index[b].push_back(graph[a].size());
    graph[a].push_back(b);
  }
}

int circuit[MAXN];
int circuitpos;

stack<int> s;

void euler_circuit(int pos) {
  s.push(pos);
  while (!s.empty()) {
    pos = s.top();
    s.pop();
    int l = graph[pos].size();
    if (!l) {
      circuit[circuitpos++] = pos + 1;
      continue;
    }
    s.push(pos);
    int n = graph[pos][l - 1];
    int rindex = Index[pos][l - 1];
    graph[pos].pop_back();
    Index[pos].pop_back();
    int m = graph[n].size();
    if (!m) return;
    if (rindex != m - 1) {
      Index[graph[n][m - 1]][Index[n][m - 1]] = rindex;
      Index[n][rindex] = Index[n][m - 1];
      graph[n][rindex] = graph[n][m - 1];
    }
    Index[n].pop_back();
    graph[n].pop_back();
    s.push(n);
  }
}

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    add_edge(a, b);
  }
  int last = -1;
  REP(i, N) if (graph[i].size() % 2) {
    if (last == -1) last = i;
    else { ++M; add_edge(last, i); last = -1; }
  }
  if (M % 2) { add_edge(0, 0); M++; }
  printf("%d\n", M);
  euler_circuit(0);
  REP(i, M) {
    if (i % 2) printf("%d %d\n", circuit[i], circuit[i + 1]);
    else       printf("%d %d\n", circuit[i + 1], circuit[i]);
  }
  return 0;
}