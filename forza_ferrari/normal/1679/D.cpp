#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
int n,m,p,a[200001],cnt,node[200001],d[200001],dp[200001];
bool vis[200001],inq[200001];
vector<pair<int,int> > v[200001];
vector<int> g[200001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline bool dfs(int k)
{
    if(inq[k])
        return 1;
    if(vis[k])
        return 0;
    inq[k]=vis[k]=1;
    for(int i:g[k])
        if(dfs(i))
            return 1;
    inq[k]=0;
    return 0;
}
inline bool topo()
{
    queue<int> q;
    for(int i=1;i<=n;++i)
        if(!d[i])
        {
            q.emplace(i);
            dp[i]=1;
        }
    int maxn=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        maxn=max(maxn,dp[k]);
        for(int i:g[k])
        {
            dp[i]=max(dp[i],dp[k]+1);
            if(!--d[i])
                q.emplace(i);
        }
    }
    return maxn>=p;
}
inline bool check(int mid)
{
    for(int i=1;i<=n;++i)
    {
        g[i].clear();
        d[i]=dp[i]=vis[i]=inq[i]=0;
    }
    for(int i=1;i<=mid;++i)
        for(auto j:v[i])
        {
            g[j.first].emplace_back(j.second);
            ++d[j.second];
        }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            if(dfs(i))
                return 1;
    return topo();
}
signed main()
{
    n=read(),m=read(),p=read();
    for(int i=1;i<=n;++i)
        node[i]=a[i]=read();
    sort(node+1,node+n+1);
    cnt=unique(node+1,node+n+1)-node-1;
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[max(a[x],a[y])].emplace_back(x,y);
    }
    int l=1,r=cnt,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=node[mid];
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}