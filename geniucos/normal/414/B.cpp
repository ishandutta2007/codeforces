#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int sol,i,j,k,n,m,mod,dp[2009][2009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
mod=1000000007;
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    dp[1][i]=1;
for(i=1;i<m;i++)
    for(j=1;j<=n;j++)
        for(k=j;k<=n;k+=j)
        {
            dp[i+1][k]+=dp[i][j];
            if(dp[i+1][k]>=mod) dp[i+1][k]-=mod;
        }
sol=0;
for(i=1;i<=n;i++)
{
    sol+=dp[m][i];
    if(sol>=mod) sol-=mod;
}
printf("%d\n",sol);
return 0;
}