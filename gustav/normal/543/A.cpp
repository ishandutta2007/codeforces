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

const int MAX = 505;
int mod;

int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int a[MAX];
int dp[2][MAX][MAX];

int main(void) 
{
  int N, M, B;
  scanf("%d%d%d%d", &N, &M, &B, &mod);
  REP(i, N) scanf("%d", a + i);

  REP(b, B + 1) dp[N % 2][0][b] = 1;
  for (int i = N - 1; i >= 0; --i) {
    int I = i % 2;
    REP(m, M + 1) REP(b, B + 1) {
      int &now = dp[I][m][b];
      now = dp[I ^ 1][m][b];
      if (m && b + a[i] <= B)
	now = add(now, dp[I][m - 1][b + a[i]]);
    }
  }

  printf("%d\n", dp[0][M][0]);

  return 0;
}