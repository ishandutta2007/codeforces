#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, K;
int A[202];
int dp[201][201][1001];

void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    sort(A+1, A+1+N);
    A[N+1]=1001;
    dp[0][0][0]=1;
    for(int i=0; i<N; i++)
    {
        int x=A[i+2]-A[i+1];
        for(int j=0; j<=i; j++)
        {
            for(int k=0; k<=K; k++)
            {
                // close
                if(j>0 && k+x*(j-1)<=K)
                    addmod(dp[i+1][j-1][k+x*(j-1)], 1LL*dp[i][j][k]*j%MOD);
                // nothing
                if(k+x*j<=K)
                    addmod(dp[i+1][j][k+x*j], 1LL*dp[i][j][k]*(j+1)%MOD);
                // open
                if(k+x*(j+1)<=K)
                    addmod(dp[i+1][j+1][k+x*(j+1)], dp[i][j][k]);
            }
        }
    }
    int ans=0;
    for(int i=0; i<=K; i++)
        addmod(ans, dp[N][0][i]);
    printf("%d\n", ans);
    return 0;
}