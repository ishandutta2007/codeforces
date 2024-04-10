#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 305;

int a[MAXN * MAXN];
int cnt[MAXN];
int dpf[MAXN * MAXN][MAXN];
int dpg[MAXN * MAXN][MAXN];

int N;
int f(int i, int upper_limit) {
  if (i < 0) return 0;
  int &ret = dpf[i][upper_limit];
  if (ret >= 0) return ret;

  ret = f(i - 1, upper_limit);
  if (a[i] == upper_limit)
    ret = f(i - 1, upper_limit) + 1;
  if (upper_limit)
    ret = max(ret, f(i, upper_limit - 1));

  return ret;
}

int g(int i, int lower_limit) {
  if (i >= N) return 0;
  int &ret = dpg[i][lower_limit];
  if (ret >= 0) return ret;

  ret = g(i + 1, lower_limit);
  if (a[i] == lower_limit)
    ret = g(i + 1, lower_limit) + 1;
  if (lower_limit + 1 < MAXN)
    ret = max(ret, g(i, lower_limit + 1));

  return ret;
}

void clear_dps() {
  memset(dpf, -1, sizeof dpf);
  memset(dpg, -1, sizeof dpg);
}

int main(void) 
{
  int n, T;
  scanf("%d%d", &n, &T);
  REP(i, n) scanf("%d", a + i);

  FOR(i, 1, 2 * n) REP(j, n)
    a[i * n + j] = a[j];

  if (T <= 2 * n) {
    N = T * n;
    clear_dps();
    printf("%d\n", f(N - 1, MAXN - 1));
    exit(0);
  }

  REP(i, n) ++cnt[a[i]];

  N = n * n;
  clear_dps();

  int sol = 0;
  REP(j, MAXN) 
    sol = max(sol, f(N - 1, j) + cnt[j] * (T - 2 * n) + g(0, j));

  printf("%d\n", sol);

  return 0;
}