#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 55;

int N, C[100000];
string S[2][100000];
int64 dp[2][100000];
char buff[100005];

int main()
{
  fill_n(*dp, 2 * 100000, INF);

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d ", &C[i]);
  }
  for(int i = 0; i < N; i++) {
    scanf("%s", buff);
    S[0][i] = buff;
    S[1][i] = S[0][i];
    reverse(begin(S[1][i]), end(S[1][i]));
  }

  dp[0][0] = 0;
  dp[1][0] = C[0];

  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        if(S[j][i - 1] <= S[k][i]) {
          int64 cost = dp[j][i - 1];
          if(k == 1) cost += C[i];
          dp[k][i] = min(dp[k][i], cost);
        }
      }
    }
  }
  int64 val = min(dp[0][N - 1], dp[1][N - 1]);
  if(val >= INF) val = -1;
  printf("%I64d\n", val);
}