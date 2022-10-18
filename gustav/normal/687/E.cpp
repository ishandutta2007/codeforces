#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 5005;

int n, m;
vector< int > G[MAX];
vector< int > R[MAX];
int bio[MAX];
int com[MAX];
int bad[MAX];
vector< int > l;

void order(int i) {
  bio[i] = 1;

  for (int j : G[i])
    if (!bio[j])
      order(j);

  l.push_back(i);
}

void get_com(int i, int c) {
  bio[i] = 1;
  com[i] = c;

  for (int j : R[i])
    if (!bio[j])
      get_com(j, c);
}

int dist[MAX][MAX];
vector< int > coms[MAX];

int q[MAX], qh, qt;

void bfs(int i) {
  int *d = dist[i];
  qt = -1;
  qh = 0;

  d[i] = 1;
  q[++qt] = i;

  while (qh <= qt) {
    int j = q[qh++];
    for (int k : G[j]) {
      if (d[k]) continue;
      d[k] = d[j] + 1;
      q[++qt] = k;
    }
  }
}

int min_cycle(int c) {
  for (int i : coms[c]) 
    bfs(i);

  int sol = 1e9;

  for (int i : coms[c])
    for (int j : coms[c])
      if (i < j)
	sol = min(sol, dist[i][j] + dist[j][i] - 2);

  return sol;
}

int main(void) 
{
  scanf("%d%d", &n, &m);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    R[b].push_back(a);
  }

  FOR(i, 1, n + 1) 
    if (!bio[i])
      order(i);

  reverse(l.begin(), l.end());
  memset(bio, 0, sizeof bio);

  int ccom = 0;
  for (int i : l) 
    if (!bio[i]) 
      get_com(i, ccom++);

  FOR(i, 1, n + 1) {
    coms[com[i]].push_back(i);
    for (int j : G[i])
      if (com[j] != com[i])
	bad[com[i]] = true;
  }

  int sol = 0;
  int tot_cycles = 0;

  REP(i, ccom) {
    if (bad[i] || coms[i].size() == 1) continue;
    int c = min_cycle(i);
    sol += c * 999 + 1;
    tot_cycles += c;
  }

  sol += n - tot_cycles;

  printf("%d\n", sol);

  return 0;
}