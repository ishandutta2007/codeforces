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

const int MAX = 100005;

int N, M;
int color[MAX];
vector< int > G[MAX];

bool dfs(int i, int c) {
  color[i] = c;

  for (int j : G[i]) {
    if (color[j] == -1 && !dfs(j, !c))
      return false;
    else if (color[j] != !c) return false;
  }

  return true;
}

int main(void) 
{
  scanf("%d%d", &N, &M);

  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  memset(color, -1, sizeof color);

  bool sol = true;

  FOR(i, 1, N + 1) 
    if (color[i] == -1 && !G[i].empty())
      sol = sol && dfs(i, 0);

  if (!sol) puts("-1");
  else {
    int cnt[2] = {0, 0};
    FOR(i, 1, N + 1) if (color[i] >= 0) ++cnt[color[i]];
    REP(c, 2) {
      printf("%d\n", cnt[c]);
      FOR(i, 1, N + 1) if (color[i] == c) printf("%d ", i);
      puts("");
    }
  }

  return 0;
}