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

const int MAXN = 3005;

int n, m;

int bio[MAXN];
int d[MAXN][MAXN];

vector< int > G[MAXN];

void bfs(int src) {
  REP(i, n) bio[i] = 0;
  bio[src] = 1;
  d[src][src] = 0;
  
  queue< int > q;
  q.push(src);

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nxt : G[cur]) {
      if (bio[nxt]) continue;
      d[src][nxt] = 1 + d[src][cur];
      bio[nxt] = 1;
      q.push(nxt);
    }
  }
}

int main(void) 
{
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int s1, t1, l1;
  scanf("%d%d%d", &s1, &t1, &l1); --s1; --t1;
  int s2, t2, l2;
  scanf("%d%d%d", &s2, &t2, &l2); --s2; --t2;

  REP(i, n) bfs(i);

  if (d[s1][t1] > l1 || d[s2][t2] > l2) {
    puts("-1");
    exit(0);
  }

  int sol = d[s1][t1] + d[s2][t2];

  REP(swp, 2) {
    REP(c1, n) REP(c2, n) {
      if (d[s1][c1] + d[c1][c2] + d[c2][t1] > l1) continue;
      if (d[s2][c1] + d[c1][c2] + d[c2][t2] > l2) continue;
      sol = min(sol, d[s1][c1] + d[s2][c1] + d[c2][t1] + d[c2][t2] + d[c1][c2]);
    }
    swap(s1, t1);
  }

  sol = m - sol;
  printf("%d\n", sol);

  return 0;
}