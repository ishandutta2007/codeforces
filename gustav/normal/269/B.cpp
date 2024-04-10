#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 5005

int N, M;
int tp[MAX];
int dp[2][MAX];
double x;

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; ++i) 
    scanf("%d%lf", tp + i, &x);

  memset(dp, 0x3f, sizeof dp);

  dp[(M & 1)][N] = 0;

  for (int i = M - 1; i >= 0; --i) {
    int I = (i & 1);
    int r = 0;

    dp[I][N] = 0;
    
    for (int j = N - 1; j >= 0; --j) {
      r += (tp[j] - 1 == i);
      dp[I][j] = min((tp[j] - 1 > i) + dp[I][j + 1], r + dp[I ^ 1][j]);
    }
  }

  printf("%d\n", dp[0][0]);

  return 0;
}