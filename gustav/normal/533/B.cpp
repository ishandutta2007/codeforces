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

const int MAXN = 200005;
const llint inf = 1000000000000000000LL;

int n;
int p[MAXN];
int a[MAXN];
vector< int > T[MAXN];
llint dpc[MAXN][2];
llint dp[MAXN][2];

int main(void) 
{
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d%d", p + i, a + i);
    --p[i];
  }

  for (int i = n - 1; i >= 0; --i) {
    if (p[i] != -1) T[p[i]].push_back(i);

    int m = T[i].size();

    dpc[m][0] = 0;
    dpc[m][1] = -inf;

    for (int c = m - 1; c >= 0; --c) {
      REP(parity, 2) {
	dpc[c][parity] = -inf;
	dpc[c][parity] = max(dpc[c][parity], dp[T[i][c]][0] + dpc[c + 1][parity]);
	dpc[c][parity] = max(dpc[c][parity], dp[T[i][c]][1] + dpc[c + 1][parity ^ 1]);
      }
    }

    dp[i][0] = dpc[0][0];
    dp[i][1] = max(dpc[0][1], a[i] + dpc[0][0]);
  }

  printf("%lld\n", max(dp[0][1], dp[0][0]));

  return 0;
}