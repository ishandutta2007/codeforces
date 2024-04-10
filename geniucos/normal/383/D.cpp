#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int mod,i,j,s,sol,n,dp[2][20009],a[10009];
int modul(int a)
{
    if(a<0) return -a;
    return a;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
mod=1000000007;
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    s+=a[i];
}
dp[1][s+a[1]]=1;
dp[1][s-a[1]]=1;
for(i=2;i<=n;i++)
{
    for(j=2*s;j>=0;j--)
    {
        dp[i&1][j]=0;
        if(j>=a[i])
        {
            dp[i&1][j]+=dp[(i&1)^1][j-a[i]];
            if(dp[i&1][j]>=mod) dp[i&1][j]-=mod;
        }
        if(j+a[i]<=2*s)
        {
            dp[i&1][j]+=dp[(i&1)^1][j+a[i]];
            if(dp[i&1][j]>=mod) dp[i&1][j]-=mod;
        }
        if(j==s+a[i])
        {
            dp[i&1][j]++;
            if(dp[i&1][j]==mod) dp[i&1][j]=0;
        }
        if(j==s-a[i])
        {
            dp[i&1][j]++;
            if(dp[i&1][j]==mod) dp[i&1][j]=0;
        }
    }
    sol+=dp[i&1][s];
    if(sol>=mod) sol-=mod;
}
printf("%d\n",sol);
return 0;
}