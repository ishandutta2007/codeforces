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

#define MAXN 2222
vector<int> graph[MAXN];
vector<pair<int, int> > v;
int N, M, cost[MAXN];
bool removed[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    scanf("%d", cost + i);
    v.push_back(make_pair(cost[i], i));
  }
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  sort(v.begin(), v.end());
  int ans = 0;
  FORD(i, N - 1, 0) {
    int x = v[i].second;
    REP(j, graph[x].size()) if (!removed[graph[x][j]]) ans += cost[graph[x][j]];
    removed[x] = true;
  }
  printf("%d\n", ans);

  return 0;
}