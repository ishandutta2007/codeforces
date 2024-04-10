#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = (1 << 16) + 5;

int deg[MAXN];
int sum[MAXN];
int stk[MAXN], top;

int main(void) 
{
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", &deg[i], &sum[i]);
  REP(i, N) if (deg[i] == 1) stk[top++] = i;

  vector< pair< int, int >> sol;

  while (top) {
    int cur = stk[--top];
    if (deg[cur] == 0) continue;
    int adj = sum[cur];
    
    sol.push_back({cur, adj});
    
    sum[adj] ^= cur;

    if (--deg[adj] == 1)
      stk[top++] = adj;
  }

  printf("%d\n", (int)sol.size());
  for (auto it : sol)
    printf("%d %d\n", it.first, it.second);

  return 0;
}