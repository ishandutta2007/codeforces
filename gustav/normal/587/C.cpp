#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;
const int MAXLG = 17;

int n, m, q;

vector< int > T[MAXN];
vector< int > res[MAXN];

int dep[MAXN];
int dad[MAXN];
int jmp[MAXN][MAXLG];
vector< int > mins[MAXN][MAXLG];

void dfs(int i, int d) {
  dep[i] = d;

  for (auto j : T[i]) {
    if (j == dad[i]) continue;
    dad[j] = i;
    dfs(j, d + 1);
  }
}

int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);

  for (int lg = MAXLG - 1; lg >= 0; --lg) 
    if (dep[jmp[a][lg]] >= dep[b])
      a = jmp[a][lg];

  if (a == b) return a;

  for (int lg = MAXLG - 1; lg >= 0; --lg) {
    if (jmp[a][lg] != jmp[b][lg]) {
      a = jmp[a][lg];
      b = jmp[b][lg];
    }
  }

  return dad[a];
}

void get_mins(int a, int pa, vector< int > &sol) {
  int delta = dep[a] - dep[pa] + 1;

  for (int lg = MAXLG - 1; lg >= 0; --lg) {
    if (((delta >> lg) & 1) == 1) {
      for (int x : mins[a][lg])
	sol.push_back(x);
      a = jmp[a][lg];
    }
  }
}

void query(int a, int b, vector< int > &sol) {
  int c = lca(a, b);

  get_mins(a, c, sol);
  get_mins(b, c, sol);

  sort(sol.begin(), sol.end());
  sol.resize(unique(sol.begin(), sol.end()) - sol.begin());
  while (sol.size() > 10) sol.pop_back();
}

int main(void) 
{
  scanf("%d%d%d", &n, &m, &q);

  REP(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    T[a].push_back(b);
    T[b].push_back(a);
  }

  REP(i, m) {
    int c;
    scanf("%d", &c);
    res[c].push_back(i);
  }

  FOR(i, 1, n + 1) {
    sort(res[i].begin(), res[i].end());
    while (res[i].size() > 10)
      res[i].pop_back();
  }

  T[0].push_back(1);
  dfs(0, 0);

  FOR(i, 0, n + 1) {
    jmp[i][0] = dad[i];
    mins[i][0] = res[i];
  }

  for (int lg = 1; lg < MAXLG; ++lg) {
    FOR(i, 0, n + 1) {
      int j = jmp[i][lg - 1];

      jmp[i][lg] = jmp[j][lg - 1];
      mins[i][lg] = mins[i][lg - 1];

      for (int x : mins[j][lg - 1])
	mins[i][lg].push_back(x);

      sort(mins[i][lg].begin(), mins[i][lg].end());

      while (mins[i][lg].size() > 10)
	mins[i][lg].pop_back();
    }
  }

  vector< int > ans;
  ans.reserve(10);

  REP(i, q) {
    int u, v, a;
    scanf("%d%d%d", &u, &v, &a);

    ans.clear();
    query(u, v, ans);

    while ((int)ans.size() > a) ans.pop_back();

    printf("%d ", (int)ans.size());

    REP(j, (int)ans.size()) 
      printf("%d%c", ans[j] + 1, " \n"[j + 1 == (int)ans.size()]);
    if (ans.empty())
      puts("");
  }

  return 0;
}