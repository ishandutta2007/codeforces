#include<cstdio>
using namespace std;
int n;
long long M,dp[405][405],C[405][405],ways[405],ans;
int main()
{
    scanf("%d%lld",&n,&M);
    n++;
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ways[i]=(ways[i]+C[i-1][j-1])%M;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)//iji
        {
            for(int k=1;k<=j;k++)
            {
                dp[i][j]=(dp[i][j]+dp[i-k-1][j-k]*ways[k]%M*C[j][k])%M;
            }
//            printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[n][i-1])%M;
    }
    printf("%lld\n",ans);
}