#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 200005;
const int MAXLG = 20;

int N, Q;
int x[MAXN];
int l[MAXN];

int f[MAXN];

void update(int i, int v) {
  for (i += 2; i < MAXN; i += i & -i)
    f[i] = max(f[i], v);
}

int query(int i) {
  int ret = 0;
  for (i += 2; i; i -= i & -i)
    ret = max(ret, f[i]);
  return ret;
}

int reach[MAXN];
int nxt[MAXN];
int jmp[MAXLG][MAXN];
llint cost[MAXLG][MAXN];

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", x + i, l + i);

  for (int i = N - 1; i >= 0; --i) {
    int to = upper_bound(x, x + N, x[i] + l[i]) - x;
    reach[i] = max(x[i] + l[i], query(to - 1));
    update(i, reach[i]);

    nxt[i] = upper_bound(x, x + N, reach[i]) - x;
    if (nxt[i] == N) nxt[i] = i;
  }

  REP(i, N) {
    jmp[0][i] = nxt[i];
    cost[0][i] = max(0, x[nxt[i]] - x[i] - (reach[i] - x[i]));
  }

  FOR(j, 1, MAXLG) REP(i, N) {
    jmp[j][i] = jmp[j - 1][jmp[j - 1][i]];
    cost[j][i] = cost[j - 1][i] + cost[j - 1][jmp[j - 1][i]];
  }

  scanf("%d", &Q);

  REP(i, Q) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;

    if (x[b] <= reach[a]) {
      puts("0");
      continue;
    }
    
    llint sol = 0;
    for (int j = MAXLG - 1; j >= 0; --j) {
      if (reach[jmp[j][a]] >= x[b]) continue;
      sol += cost[j][a];
      a = jmp[j][a];
    }

    sol += cost[0][a];

    cout << sol << endl;
  }

  return 0;
}