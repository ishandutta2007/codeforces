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

const int MAX = 21;
const int inf = 1000000000;

int n, m;
char s[MAX][MAX];
int a[MAX][MAX];
int dp[2][MAX][1 << 20];
int cmask[MAX][26];
int largest[MAX][26];
int cost[MAX][26];

int main(void) 
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", s[i]);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);

  memset(dp, 0x3f, sizeof dp);
  dp[m % 2][0][(1 << n) - 1] = 0; 

  REP(j, m) REP(i, n) {
    int c = s[i][j] - 'a';
    cmask[j][c] |= (1 << i);
    largest[j][c] = max(largest[j][c], a[i][j]);
    cost[j][c] += a[i][j];
  }

  for (int j = m - 1; j >= 0; --j) {
    int J = j % 2;
    for (int mask = (1 << n) - 1; mask >= 0; --mask) {
      dp[J][n][mask] = dp[J ^ 1][0][mask];
      REP(i, n) {
	int c = s[i][j] - 'a';
	if (cmask[c]) 
	  dp[J][n][mask] = min(dp[J][n][mask], dp[J][n][mask | cmask[j][c]] + cost[j][c] - largest[j][c]);
      }
    }

    for (int i = n - 1; i >= 0; --i) 
      for (int mask = (1 << n) - 1; mask >= 0; --mask) 
	dp[J][i][mask] = min(dp[J][i + 1][mask], dp[J][i + 1][mask | (1 << i)] + a[i][j]);
  }

  printf("%d\n", dp[0][0][0]);
  
  return 0;
}