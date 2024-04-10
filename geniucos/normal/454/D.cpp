#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int MM,nr,i,n,j,k,ras,dp[109][(1<<16)+10],a[109],A[109],pr[109],how[109][(1<<16)+10],mp[109][(1<<16)+10],M[109],cod[109];
vector < int > v[100];
vector < int > :: iterator it;
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
nr=-1;
cod[1]=-1;
for(i=2;i<=58;i++)
{
    for(j=2;j<i;j++)
        if(i%j==0) break;
    if(j==i) pr[++nr]=i,cod[i]=nr;
    else cod[i]=-1;
}
nr++;
for(i=1;i<=58;i++)
{
    M[i]=0;
    for(j=1;j<=i;j++)
        if(cod[j]!=-1&&i%j==0) M[i]|=1<<cod[j];
    for(j=0;j<(1<<nr);j++)
        if((M[i]&j)==0) v[i].push_back(j);
}
for(j=1;j<=n;j++)
    for(i=0;i<(1<<nr);i++)
        dp[j][i]=10000000;
for(i=1;i<=58;i++)
    if(dp[1][M[i]]>mod(i-a[1])) dp[1][M[i]]=mod(i-a[1]),how[1][M[i]]=i;
for(i=2;i<=n;i++)
    for(j=1;j<=58;j++)
        for(it=v[j].begin();it!=v[j].end();it++)
        {
            if(dp[i-1][*it]+mod(j-a[i])<dp[i][M[j]|(*it)])
                dp[i][M[j]|(*it)]=dp[i-1][*it]+mod(j-a[i]),how[i][M[j]|(*it)]=j,mp[i][M[j]|(*it)]=*it;
        }
ras=10000000;
for(j=0;j<(1<<nr);j++)
    if(dp[n][j]<ras) ras=dp[n][j],MM=j;
i=n;
while(1)
{
    A[i]=how[i][MM];
    MM=mp[i][MM];
    i--;
    if(i==0) break;
}
for(i=1;i<=n;i++)
    printf("%d ",A[i]);
printf("\n");
return 0;
}