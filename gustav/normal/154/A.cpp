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

const int MAXN = 100005;

int n, k;
char s[MAXN];
char buf[3];
int p[26];
int dp[MAXN][27];

int solve(int i, int last) {
  if (i == n) return 0;
  int &ret = dp[i][last + 1];
  if (ret >= 0) return ret;


  ret = solve(i + 1, last);
  if (last == -1 || last != p[s[i] - 'a'])
    ret = max(ret, 1 + solve(i + 1, s[i] - 'a'));

  return ret;
}



int main(void) 
{
  scanf("%s", s); n = strlen(s);
  scanf("%d", &k);

  memset(p, -1, sizeof p);
  REP(i, k) {
    scanf("%s", buf);
    p[buf[0] - 'a'] = buf[1] - 'a';
    p[buf[1] - 'a'] = buf[0] - 'a';
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", n - solve(0, -1));

  return 0;
}