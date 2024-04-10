#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1000005;
const int MAXM = 255;

int n, m;
int cnt[MAXN];
int x[MAXM];
int y[MAXM];


int main(void) 
{
  scanf("%d%d", &n, &m);
  REP(i, m) scanf("%d%d", x+i, y+i);

  FOR(i, 1, n + 1) cnt[i] = 1;
  REP(i, m) REP(j, m) {
    if (i == j) continue;
    if (y[i] == y[j]) continue;

    llint a = y[i] - y[j];
    llint b = x[j] - x[i];
    llint c = -(a * x[i] + b * y[i]);

    if (abs(c) % abs(a) != 0) continue;
    llint X = -c / a;

    if (X < 1 || X > n) continue;

    int ccnt = 0;
    REP(k, m) 
      if (a * x[k] + b * y[k] + c == 0) ++ccnt;

    cnt[X] = max(cnt[X], ccnt);
  }

  llint sol = 0;
  FOR(i, 1, n + 1) sol += cnt[i];

  printf("%lld\n", sol);

  return 0;
}