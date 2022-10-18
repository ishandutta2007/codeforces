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

const int MAX = 30005;
const int MAXS = 255;

int n, d;
int g[MAX];
int p[MAX];
int dp[2 * MAXS][MAX];

int calc(int l, int cur) {
  int ld = l - d + 250;

  int &ret = dp[ld][cur];
  if (ret >= 0) return ret;

  ret = g[cur];

  for (int i = -1; i <= +1; ++i) {
    if (l + i <= 0) continue;
    if (cur + l + i >= MAX) continue;
    ret = max(ret, calc(l + i, cur + l + i) + g[cur]);
  }

  return ret;
}

int main(void) 
{
  scanf("%d%d", &n, &d);
  REP(i, n) scanf("%d", p + i + 1);
  REP(i, n) g[p[i + 1]] += 1;

  memset(dp, -1, sizeof dp);

  printf("%d\n", calc(d, d));

  return 0;
}