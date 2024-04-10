#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 2020
#define inf 1000000020

using namespace std;

struct point{
    int t,v,d,num;
};

bool cmp(point x,point y)
{
    return x.d<y.d;
}

int dp[maxn][maxn],pre[maxn][maxn],n,m,k,ans[maxn],p,q;
point a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].v);
    for (int i=1;i<=n;i++) a[i].num=i;
    sort(a+1,a+n+1,cmp);
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    for (int i=1;i<=n;i++)
        for (int j=1;j<maxn;j++)
        {
            dp[i][j]=dp[i-1][j];pre[i][j]=pre[i-1][j];
            if (j>=a[i].t&&j<a[i].d&&dp[i-1][j-a[i].t]+a[i].v>dp[i][j]){
                dp[i][j]=dp[i-1][j-a[i].t]+a[i].v;
                pre[i][j]=i;
            }
        }
    p=0;m=0;
    for (int i=1;i<maxn;i++) if (dp[n][i]>dp[n][p]) p=i;
    q=dp[n][p];k=pre[n][p];
    while (k){
        ans[++m]=k;
        p-=a[k].t;
        k=pre[k-1][p];
    }
    printf("%d\n%d\n",q,m);
    for (int i=m;i>=1;i--) printf("%d ",a[ans[i]].num); printf("\n");
    return 0;
}