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

const int MAXN = 105;

int T;
int N, K;
char m[3][5 * MAXN];
int dp[3][5 * MAXN];

bool go(int i, int j) {
  if (j >= 3 * N - 1)
    return true;

  int &ret = dp[i][j];
  if (ret >= 0) return ret;

  ret = false;

  if (m[i][j] != '.')
    return ret;

  if (i <= 1 && m[i][j + 1] == '.' && m[i + 1][j + 1] == '.' && m[i + 1][j + 2] == '.' && go(i + 1, j + 3))
    ret = true;

  if (m[i][j + 1] == '.' && m[i][j + 1] == '.' && m[i][j + 2] == '.' && go(i, j + 3))
    ret = true;

  if (i >= 1 && m[i][j + 1] == '.' &&  m[i - 1][j + 1] == '.' && m[i - 1][j + 2] == '.' && go(i - 1, j + 3))
    ret = true;

  return ret;
}

void solve() {
  scanf("%d%d", &N, &K);
  REP(i, 3) scanf("%s", m[i]);
  REP(i, 3) FOR(j, N, 5 * N) m[i][j] = '.';

  memset(dp, -1, sizeof dp);

  int x, y;
  REP(i, 3) REP(j, N) if (m[i][j] == 's') x = i, y = j;
  m[x][y] = '.';

  if (go(x, y))
    puts("YES");
  else
    puts("NO");
}

int main(void) 
{
  scanf("%d", &T);
  while (T--) solve();

  return 0;
}