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
int sol,mod,i,j,n,p[10009],dp[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
mod=1000000007;
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
dp[1]=2;
for(i=2;i<=n;i++)
{
    if(p[i]==i) dp[i]=2;
    else
    {
        for(j=p[i];j<i;j++)
        {
            dp[i]+=dp[j];
            if(dp[i]>=mod) dp[i]-=mod;
        }
        dp[i]+=2;
        if(dp[i]>=mod) dp[i]-=mod;
    }
}
sol=0;
for(i=1;i<=n;i++)
{
    sol+=dp[i];
    if(sol>=mod) sol-=mod;
}
printf("%d\n",sol);
return 0;
}