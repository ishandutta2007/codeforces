#include <cstdio>
#include <cassert>
#include <map>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAGIC = 320;
const int MAXN = 100005;

int N, M, Q;

int u[MAXN];
int v[MAXN];
int sol[MAXN];

map< pair< int, int >, int > id;

struct Edge {
  int a, b;
};

vector< Edge > E[MAXN];

int uf[MAXN];
int rnk[MAXN];
int find(int i) { return i == uf[i] ? i : uf[i] = find(uf[i]); }

void unite(int i, int j) { 
  int fi = find(i);
  int fj = find(j);
  uf[fi] = fj;
}

void solve_big(int c) {
  REP(i, N) uf[i] = i;
  for (Edge e : E[c]) unite(e.a, e.b);
  REP(i, Q) if (find(u[i]) == find(v[i])) ++sol[i];
}

bool got[MAXN];

void solve_small(int c) {
  vector< int > nodes;

  for (Edge e : E[c]) {
    if (!got[e.a]) got[e.a] = true, nodes.push_back(e.a);
    if (!got[e.b]) got[e.b] = true, nodes.push_back(e.b);
  }

  for (int i : nodes) uf[i] = i;
  for (Edge e : E[c]) unite(e.a, e.b);

  for (int i : nodes) {
    for (int j : nodes) {
      if (i >= j) continue;
      if (find(i) != find(j)) continue;
      if (!id.count({i, j})) continue;
      int x = id[{i, j}];
      ++sol[x];
    }
  }
      
  for (int i : nodes) got[i] = false;
}

int main(void) 
{
  scanf("%d%d", &N, &M);

  REP(i, M) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b; --c;
    E[c].push_back({a, b});
  }

  scanf("%d", &Q);

  REP(i, Q) {
    scanf("%d%d", &u[i], &v[i]); --u[i]; --v[i];
    if (!id.count({u[i], v[i]}))
      id[{u[i], v[i]}] = id[{v[i], u[i]}] = i;
  }

  REP(i, M) {
    if (E[i].size() < MAGIC)
      solve_small(i);
    else
      solve_big(i);
  }

  REP(i, Q)
    printf("%d\n", sol[id[{u[i], v[i]}]]);

  return 0;
}