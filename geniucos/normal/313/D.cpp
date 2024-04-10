#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,kk,i,j,k,p,li,ri,co;
long long minc,dp[309][309],dr[309][309],mi[309][309];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&kk);
for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
        dr[i][j]=10000000001;
for(i=1;i<=m;i++)
{
    scanf("%d",&li);
    scanf("%d",&ri);
    scanf("%d",&co);
    if(co<dr[li][ri]) dr[li][ri]=co;
}
dp[0][0]=0;
for(i=1;i<=n;i++)
{
    dp[0][i]=1000000000000001;
    mi[0][i]=1000000000000001;
}
for(i=0;i<=n;i++)
    mi[i][0]=0;
for(i=1;i<=n;i++)
{
    for(j=i+1;j<=n;j++)
    {
        dp[i][j]=1000000000000001;
        mi[i][j]=mi[i-1][j];
    }
    for(j=1;j<=i;j++)
    {
        dp[i][j]=1000000000000001;
        for(p=i;p>=1;p--)
        if(dr[p][i]!=10000000001)
        {
            if(mi[p-1][j-(i-p+1)]+dr[p][i]<dp[i][j]) dp[i][j]=mi[p-1][j-(i-p+1)]+dr[p][i];
            for(k=p;k<=i;k++)
                if(dp[k][j-(i-k)]+dr[p][i]<dp[i][j]) dp[i][j]=dp[k][j-(i-k)]+dr[p][i];
        }
        mi[i][j]=mi[i-1][j];
        if(dp[i][j]<mi[i][j]) mi[i][j]=dp[i][j];
    }
}
minc=10000000000000001;
for(j=kk;j<=n;j++)
    if(mi[n][j]<minc) minc=mi[n][j];
if(minc>=1000000000000001)
{
    printf("-1\n");
    return 0;
}
printf("%I64d\n",minc);
return 0;
}