#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,a[1005],b[1005];
long long ans,NowD;
vector<int> vec[1005];
bool Reach[1005],vis[1005];
long long dis[1005];
int From[1005];
bool check(long long x)
{
    queue<int> Q;
    for(int i=1;i<=n;i++)
    {
        if(Reach[i]) 
        {
            dis[i]=x;
            vis[i]=true;
            Q.push(i);
            From[i]=0;
        }
        else
        {
            dis[i]=0;
            From[i]=0;
            vis[i]=false;
        }
    }
    while(!Q.empty())
    {
        int Now=Q.front();
        Q.pop();
        if(!Reach[Now])
        {
            for(auto &p : vec[Now])
            {
                if(p==From[Now]) continue;
                if(vis[p]) return true;
                if(a[p]>=dis[Now]) continue;
                vis[p]=true;
                dis[p]=dis[Now]+b[p];
                Q.push(p);
                From[p]=Now;
            }
        }
        else
        {
            for(auto &p : vec[Now])
            {
                if(vis[p] || a[p]>=dis[Now]) continue;
                vis[p]=true;
                dis[p]=dis[Now]+b[p];
                Q.push(p);
                From[p]=Now;
            }
        }
    }
    return false;
}

void GetR(int x)
{
    while(From[x]!=0)
    {
        if(!Reach[x])
        {
            Reach[x]=true;
            NowD+=b[x];
        }
        x=From[x];
    }
}
void bfs(long long x)
{
    queue<int> Q;
    for(int i=1;i<=n;i++)
    {
        if(Reach[i]) 
        {
            dis[i]=x;
            vis[i]=true;
            From[i]=0;
            Q.push(i);
        }
        else
        {
            dis[i]=0;
            From[i]=0;
            vis[i]=false;
        }
    }
    while(!Q.empty())
    {
        int Now=Q.front();
        Q.pop();
        if(!Reach[Now])
        {
            for(auto &p : vec[Now])
            {
                if(p==From[Now]) continue;
                if(vis[p])
                {
                    GetR(Now);
                    if(!Reach[p]) GetR(p);
                    return;
                }
                if(a[p]>=dis[Now]) continue;
                vis[p]=true;
                dis[p]=dis[Now]+b[p];
                Q.push(p);
                From[p]=Now;
            }
        }
        else
        {
            for(auto &p : vec[Now])
            {
                if(vis[p] || a[p]>=dis[Now]) continue;
                vis[p]=true;
                dis[p]=dis[Now]+b[p];
                From[p]=Now;
                Q.push(p);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) vec[i].clear(),Reach[i]=false;
        NowD=0; ans=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        Reach[1]=true;
        while(1)
        {
            bool flag=false;
            for(int i=1;i<=n;i++)
            {
                if(!Reach[i]) flag=true;
            }
            if(!flag) break;
            long long L=1,R=1e9+1;
            while(L<R)
            {
                long long Mid=(L+R)/2;
                if(check(Mid)) R=Mid;
                else L=Mid+1;
            }
            ans=max(ans,L-NowD);
            bfs(L);
        }
        printf("%lld\n",ans);
    }
}