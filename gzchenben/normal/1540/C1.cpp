#include<cstdio>
#include<algorithm>
#define mod (1000000007)
using namespace std;
int n,k,x,b[105],c[105],dp[105][10005],sum;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        sum+=c[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%d%d",&k,&x);
    int PF1=0,PF2=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=max(0,PF2+i*x);j<=sum;j++)
        {
            for(int k=0;k<=c[i];k++)
            {
                if(k<=j) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
        PF1+=b[i];
        PF2+=PF1;
    }
    int ans=0;
    for(int i=0;i<=sum;i++)
    {
        ans=(ans+dp[n][i])%mod;
    }
    printf("%d\n",ans);
}