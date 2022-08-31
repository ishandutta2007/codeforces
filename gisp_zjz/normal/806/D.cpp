#include<bits/stdc++.h>
#define maxn 2050
#define inf 1000000007

using namespace std;
typedef long long ll;
ll a[maxn][maxn],d,ans[maxn],n,k,dis[maxn];
bool vis[maxn];
int main()
{
    scanf("%d",&n); d=inf;
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            scanf("%lld",&k);
            a[i][j]=a[j][i]=k;
            d=min(d,k);
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) a[i][j]-=d;
    dis[0]=inf;
    for (int i=1;i<=n;i++)
    {
        dis[i]=inf;
        for (int j=1;j<=n;j++)
            if (i!=j) dis[i]=min(dis[i],a[i][j]*2);
    }
    for (int i=1;i<=n;i++)
    {
        k=0;
        for (int j=1;j<=n;j++) if (dis[j]<dis[k]&&!vis[j]) k=j;
        vis[k]=true;
        for (int j=1;j<=n;j++) dis[j]=min(dis[j],dis[k]+a[k][j]);
    }
    for (int i=1;i<=n;i++) cout << dis[i]+(n-1)*d << endl;
    return 0;
}