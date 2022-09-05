#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
long long i,j,d,sol,mod,n,m,s[10009],dp[10009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&m);
scanf("%d",&n);
scanf("%d",&d);
mod=1000000007;
dp[0]=1;
sol+=dp[m];
if(sol>=mod) sol-=mod;
for(i=1;i<=m;i++)
{
    s[0]=dp[0];
    for(j=1;j<=m;j++)
        {s[j]=s[j-1]+dp[j];if(s[j]>=mod) s[j]-=mod;}
    for(j=m;j>=1;j--)
    {
        dp[j]=s[j-1];
        if(dp[j]>=mod) dp[j]-=mod;
        ////dp[j-1]+..+dp[j-n]
        if(j>n)
        {
            dp[j]-=s[j-n-1];
            if(dp[j]<0) dp[j]+=mod;
        }
    }
    sol+=dp[m];
    if(sol>=mod) sol-=mod;
    dp[0]=0;
}
for(j=0;j<=m;j++)
    dp[j]=0;
dp[0]=1;
d--;
sol-=dp[m];
if(sol<0) sol+=mod;
for(i=1;i<=m;i++)
{
    s[0]=dp[0];
    for(j=1;j<=m;j++)
        {s[j]=s[j-1]+dp[j];if(s[j]>=mod) s[j]-=mod;}
    for(j=m;j>=1;j--)
    {
        dp[j]=s[j-1];
        if(dp[j]>=mod) dp[j]-=mod;
        ////dp[j-1]+..+dp[j-d]
        if(j>d)
        {
            dp[j]-=s[j-d-1];
            if(dp[j]<0) dp[j]+=mod;
        }
    }
    sol-=dp[m];
    if(sol<0) sol+=mod;
    dp[0]=0;
}
sol%=mod;
if(sol<0) sol+=mod;
printf("%d\n",sol);
return 0;
}