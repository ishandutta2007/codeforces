#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

int N, M;
int bio[MAXN];
vector< int > G[MAXN];

int uf[MAXN];
int find(int i) { return i == uf[i] ? i : uf[i] = find(uf[i]); }
void unite(int i, int j) { uf[find(i)] = find(j); }

enum { WHITE, GRAY, BLACK };

bool cycle(int i) {
  bio[i] = GRAY;

  bool ret = false;
  for (int j : G[i]) {
    if (bio[j] == GRAY)
      ret = true;
    if (bio[j] == WHITE && cycle(j))
      ret = true;
  }

  bio[i] = BLACK;

  return ret;
}

vector< int > nodes[MAXN];

int main(void) 
{
  scanf("%d%d", &N, &M);

  REP(i, N) uf[i] = i;

  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    unite(a, b);
    G[a].push_back(b);
  }

  int sol = 0;
  REP(i, N) nodes[find(i)].push_back(i);
  REP(i, N) {
    if (nodes[i].empty()) continue;

    bool c = false;
    for (int j : nodes[i]) 
      if (cycle(j)) c = true;

    sol += (int)nodes[i].size() - 1 + c;
  }

  printf("%d\n", sol);

  return 0;
}