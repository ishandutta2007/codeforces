#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1005;

int d[MAXN];
int color[MAXN];
vector< int > G[MAXN];

void dfs(int i, int c) {
  if (color[i] >= 0) return;
  color[i] = c;
  for (auto j : G[i])
    dfs(j, c);
}

int best[MAXN];

int main(void) 
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector< pair< int, int > > E;
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
    E.push_back({a, b});
  }

  memset(best, -1, sizeof best);
  memset(color, -1, sizeof color);
  REP(i, n) dfs(i, i);

  REP(i, n) {
    memset(d, 0, sizeof d);
    queue< int > q;
    q.push(i); d[i] = 1;

    int maxd = 0;
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      maxd = max(maxd, d[cur]);
      for (auto nxt : G[cur]) {
	if (d[nxt]) continue;
	d[nxt] = d[cur] + 1;
	q.push(nxt);
      }
    }

    bool ok = true;
    for (auto &e : E) 
      if (d[e.first] && d[e.first] == d[e.second]) 
	ok = false;

    if (ok)
      best[color[i]] = max(best[color[i]], maxd - 1);
  }

  int sol = 0;
  REP(i, n) {
    if (color[i] != i) continue;
    if (best[i] == -1) {
      puts("-1");
      exit(0);
    }
    sol += best[i];
  }

  printf("%d\n", sol);

  return 0;
}