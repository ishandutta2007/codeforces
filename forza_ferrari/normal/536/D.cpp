#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
int n,m,s,t,w[2001],dis[2][2001],px[2001],py[2001],x,y,dp[2][2005][2005],sum[2001][2001],cnt[2001][2001];
bool vis[2001];
vector<pair<int,int> > v[2001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||x>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void dijkstra(int s,int dis[])
{
    for(int i=1;i<=n;++i)
    {
        vis[i]=0;
        dis[i]=1e18;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.emplace(0,s);
    dis[s]=0;
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        for(auto i:v[k.second])
            if(!vis[i.first]&&dis[i.first]>dis[k.second]+i.second)
            {
                dis[i.first]=dis[k.second]+i.second;
                q.emplace(dis[i.first],i.first);
            }
    }
}
signed main()
{
    n=read(),m=read(),s=read(),t=read();
    for(int i=1;i<=n;++i)
        w[i]=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    dijkstra(s,dis[0]);
    dijkstra(t,dis[1]);
    for(int i=1;i<=n;++i)
    {
        px[i]=dis[0][i];
        py[i]=dis[1][i];
    }
    sort(px+1,px+n+1);
    x=unique(px+1,px+n+1)-px-1;
    sort(py+1,py+n+1);
    y=unique(py+1,py+n+1)-py-1;
    for(int i=1;i<=n;++i)
    {
        dis[0][i]=lower_bound(px+1,px+x+1,dis[0][i])-px;
        dis[1][i]=lower_bound(py+1,py+y+1,dis[1][i])-py;
        ++cnt[dis[0][i]][dis[1][i]];
        sum[dis[0][i]][dis[1][i]]+=w[i];
    }
    for(int i=1;i<=x;++i)
        for(int j=1;j<=y;++j)
        {
            cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    for(int i=x;i>=1;--i)
        for(int j=y;j>=1;--j)
        {
            if(cnt[i][y]-cnt[i-1][y]-cnt[i][j-1]+cnt[i-1][j-1])
                dp[0][i][j]=max(dp[0][i+1][j],dp[1][i+1][j])+sum[i][y]-sum[i-1][y]-sum[i][j-1]+sum[i-1][j-1];
            else
                dp[0][i][j]=dp[0][i+1][j];
            if(cnt[x][j]-cnt[i-1][j]-cnt[x][j-1]+cnt[i-1][j-1])
                dp[1][i][j]=min(dp[0][i][j+1],dp[1][i][j+1])-sum[x][j]+sum[i-1][j]+sum[x][j-1]-sum[i-1][j-1];
            else
                dp[1][i][j]=dp[1][i][j+1];
        }
    cout<<(dp[0][1][1]>0? "Break a heart":dp[0][1][1]==0? "Flowers":"Cry")<<'\n';
    return 0;
}