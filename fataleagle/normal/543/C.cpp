#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[20][21];
int A[20][20];
int dp[2][26][1<<20];
int mask[20][26];
int sum[20][26];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", S[i]);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", A[i]+j);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            mask[j][S[i][j]-'a']|=1<<i;
            sum[j][S[i][j]-'a']+=A[i][j];
        }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0]=0;
    for(int i=0; i<M; i++)
    {
        memset(dp[(i&1)^1], 0x3f, sizeof dp[(i&1)^1]);
        for(int j=0; j<N; j++)
            for(int k=0; k<(1<<N); k++)
            {
                int ni=(j+1<N)?(i&1):((i&1)^1);
                int nj=(j+1<N)?(j+1):0;
                int l=S[j][i]-'a';
                dp[ni][nj][k]=min(dp[ni][nj][k], dp[i&1][j][k]);
                dp[ni][nj][k|(1<<j)]=min(dp[ni][nj][k|(1<<j)], dp[i&1][j][k]+A[j][i]);
                dp[ni][nj][k|mask[i][l]]=min(dp[ni][nj][k|mask[i][l]], dp[i&1][j][k]+sum[i][l]-A[j][i]);
            }
    }
    printf("%d\n", dp[M&1][0][(1<<N)-1]);
    return 0;
}