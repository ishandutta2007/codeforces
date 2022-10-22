#include<cstdio>
#include<vector>
#define mod (1000000007)
using namespace std;
long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int n;
long long F[205][205],dis[205][205],dis2[205][205],fa[205];
vector<int> vec[205];
void dfs(int x,int now,int pre)
{
    dis[x][now]=dis[x][pre]+1;
    for(int i=0;i<vec[now].size();i++)
    {
        if(vec[now][i]!=pre) dfs(x,vec[now][i],now);
    }
}
void dfs2(int x,int f)
{
    fa[x]=f;
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i]!=f) dfs2(vec[x][i],x);
    }
}
int Find_dis2(int p,int x,int y)
{
    if(x==y) return dis2[x][y]=0;
    if(dis2[x][y]) return dis2[x][y];
    if(dis[p][x]>dis[p][y]) return dis2[x][y]=Find_dis2(p,fa[x],y)+1;
    if(dis[p][x]<dis[p][y]) return dis2[x][y]=Find_dis2(p,x,fa[y]);
    return dis2[x][y]=Find_dis2(p,fa[x],fa[y])+1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) F[i][0]=1,F[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            F[i][j]=(F[i][j-1]+F[i-1][j])*qpow(2,mod-2)%mod;
            // printf("F[%d][%d]=%lld\n",i,j,F[i][j]);
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][0]=-1;
        dfs(i,i,0);
    }
    long long ans=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis2[i][j]=0;
        dfs2(k,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                Find_dis2(k,i,j);
                Find_dis2(k,j,i);
                // printf("dis2[%d][%d][%d]=%d,dis2[%d][%d][%d]=%d\n",k,i,j,dis2[i][j],k,j,i,dis2[j][i]);
                ans=(ans+F[dis2[i][j]][dis2[j][i]])%mod;
                // printf("ans+=F[%lld][%lld]\n",dis2[k][i],dis2[k][j]);
            }
        }
    }
    printf("%lld\n",ans*qpow(n,mod-2)%mod);
}