#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 55;

int n, q;
char a[MAX][3];
char b[MAX][2];

int dp[MAX][26];

llint calc(int n, char c) {
  if (n == 0) return 1;
  int &ret = dp[n][c - 'a'];
  if (ret >= 0) return ret;
  ret = 0;

  REP(i, q) 
    if (b[i][0] == c)
      ret += calc(n - 1, a[i][0]);

  return ret;
}

int main(void) 
{
  scanf("%d%d", &n, &q);

  REP(i, q)
    scanf("%s %s", a[i], b[i]);

  memset(dp, -1, sizeof dp);
  printf("%lld\n", calc(n - 1, 'a'));

  return 0;
}