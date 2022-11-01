#include <bits/stdc++.h>

using namespace std;

int N, M, B, MOD;
int dp[2][502][502];
int A[501];

inline void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &B, &MOD);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    dp[0][0][0]=1%MOD;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=M; j++)
            for(int k=0; k<=B; k++)
                dp[(i&1)^1][j][k]=0;
        for(int j=0; j<=M; j++)
            for(int k=0; k<=B; k++) if(dp[i&1][j][k])
            {
                addmod(dp[(i&1)^1][j][k], dp[i&1][j][k]);
                if(j+1<=M && k+A[i]<=B)
                    addmod(dp[i&1][j+1][k+A[i]], dp[i&1][j][k]);
            }
    }
    int ans=0;
    for(int i=0; i<=B; i++)
        addmod(ans, dp[N&1][M][i]);
    printf("%d\n", ans);
    return 0;
}