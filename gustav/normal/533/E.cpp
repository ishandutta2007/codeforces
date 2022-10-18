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

int n;
char s[MAXN];
char t[MAXN];

int dp[MAXN][2][2];

int solve(int i, int ps, int pt, int as, int at) {
  if (abs(ps - pt) > 1) return 0;
  if (i == n + 1) 
    return ps == n && pt == n;

  int &ret = dp[i][as][at];
  if (ret >= 0) return ret;
  ret = 0;

  for (char c = 'a'; c <= 'z'; ++c) {
    if (as && c != s[ps]) continue;
    if (at && c != t[pt]) continue;
    ret += solve(i + 1, 
		 ps + (c == s[ps]),
		 pt + (c == t[pt]),
		 as || c != s[ps],
		 at || c != t[pt]);
  }

  return ret;
}

int main(void) 
{
  scanf("%d", &n);
  scanf("%s", s); s[n] = '$';
  scanf("%s", t); t[n] = '#';

  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0, 0, 0, 0));
    
  return 0;
}