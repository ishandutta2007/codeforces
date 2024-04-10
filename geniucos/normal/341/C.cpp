#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int sol,mod,i,j,n,m,nr,st[2013],a[2013],app[2013],ap[2013],dr[2013],v[2013],c[2013][2013],fac[2013],dp[2013];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    if(a[i]!=-1) ap[a[i]]=1;
    else app[i]=1;
}
for(i=1;i<=n;i++)
    if(ap[i]==0&&app[i]==0) m++;
for(i=1;i<=n;i++)
    if(ap[i]==0&&app[i]==1) nr++;
mod=1000000007;
c[0][0]=c[1][0]=c[1][1]=1;
for(i=2;i<=n;i++)
{
    c[i][0]=1;
    for(j=1;j<=i;j++)
    {
        c[i][j]=c[i-1][j]+c[i-1][j-1];
        if(c[i][j]>=mod) c[i][j]-=mod;
    }
}
fac[0]=1;
for(i=1;i<=nr+m;i++)
    fac[i]=(1LL*fac[i-1]*i)%mod;
dp[0]=fac[m];
dp[1]=fac[m+1]-fac[m];
if(dp[1]<0) dp[1]+=mod;
dp[2]=((long long)fac[m+2]-1LL*fac[m+1]*2)%mod;
if(dp[2]<0) dp[2]+=mod;
dp[2]+=fac[m];
if(dp[2]>=mod) dp[2]-=mod;
for(i=3;i<=nr;i++)
{
    dp[i]=fac[i+m]-fac[m];
    if(dp[i]<0) dp[i]+=mod;
    for(j=1;j<i;j++)
    {
        dp[i]=dp[i]-(1LL*dp[i-j]*c[i][j])%mod;
        if(dp[i]<0) dp[i]+=mod;
    }
}
printf("%d\n",dp[nr]);
return 0;
}