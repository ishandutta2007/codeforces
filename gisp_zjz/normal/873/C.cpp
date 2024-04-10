#include<bits/stdc++.h>
#define maxn 105
#define eps 1e-6

using namespace std;

int n,k,ans,m,d,t,a[maxn][maxn],sum[maxn],s;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    s=0;ans=0;t=0;
    for (int i=1;i<=m;i++)
    {
        sum[0]=0;
        for (int j=1;j<=n;j++) sum[j]=sum[j-1]+a[j][i];
        t=0;
        for (int j=1;j+k-1<=n;j++)
            if (sum[j+k-1]-sum[j-1]>t) t=sum[j+k-1]-sum[j-1],d=j;
        s+=sum[d-1];ans+=t;
    }
    printf("%d %d\n",ans,s);
    return 0;
}