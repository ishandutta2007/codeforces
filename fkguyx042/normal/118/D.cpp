#include<stdio.h>
#define mod 100000000
#define LL long long
LL dp[2][202][102];
int main(void)
{
    int n1,n2,k1,k2;
    int i,j,t;
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    dp[0][0][0]=dp[1][0][0]=1;
    for(i=1;i<=n1+n2;i++)
    {
        for(j=n1>i?i:n1;j>=1;j--)
          for(t=1;t<=j&&t<=k1;t++)
           if(n2>=i-j)
             dp[0][i][j]=(dp[0][i][j]+dp[1][i-t][i-j])%mod;
        for(j=n2>i?i:n2;j>=1;j--)
          for(t=1;t<=j&&t<=k2;t++)
            if(n1>=i-j)
              dp[1][i][j]=(dp[1][i][j]+dp[0][i-t][i-j])%mod;
    }
    printf("%I64d\n",(dp[0][n1+n2][n1]+dp[1][n1+n2][n2])%mod);
    return 0;
}