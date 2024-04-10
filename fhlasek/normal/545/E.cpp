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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 333333
vector<int> graph[MAXN], len[MAXN], Index[MAXN];
int L[MAXN];
int N, M;

#define INF 1000000000000000000LL
pair<long long, int> Dist[MAXN];
int Ans[MAXN];
priority_queue< pair<pair<long long, int>, int> > pq;
void add(int v, pair<long long, int> d, int ind) {
  if (Dist[v] <= d) return;
  Dist[v] = d;
  Ans[v] = ind + 1;
  d.first *= -1;
  pq.push(make_pair(d, v));
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);

  REP(i, M) {
    int x, y;
    scanf("%d%d%d", &x, &y, L + i); x--; y--;
    graph[x].push_back(y); len[x].push_back(L[i]); Index[x].push_back(i);
    graph[y].push_back(x); len[y].push_back(L[i]); Index[y].push_back(i);
  }

  int u;
  scanf("%d", &u); u--;

  REP(i, N) Dist[i] = make_pair(INF, INF);

  add(u, make_pair(0, 0), -1);
  while (!pq.empty()) {
    int v = pq.top().second;
    pair<long long, int> d = pq.top().first;
    d.first *= -1;
    pq.pop();
    if (Dist[v] != d) continue;
    REP(i, graph[v].size()) add(graph[v][i], make_pair(d.first + len[v][i], len[v][i]), Index[v][i]);
  }
  long long ans = 0;
  REP(i, N) ans += L[Ans[i] - 1];
  cout << ans << endl;
  bool printed = false;
  REP(i, N) if (i != u) {
    if (printed) printf(" ");
    printed = true;
    printf("%d", Ans[i]);
  }
  printf("\n");
  return 0;
}