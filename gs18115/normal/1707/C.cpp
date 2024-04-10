#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
struct unifi
{
    int pa[100010];
    int par(int x)
    {
        if(pa[x]==0)
            return x;
        return pa[x]=par(pa[x]);
    }
    bool uni(int x,int y)
    {
        x=par(x);
        y=par(y);
        if(x==y)
            return 0;
        pa[x]=y;
        return 1;
    }
}uf;
int spa[100010][20];
int pa[100010],dep[100010];
int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=0;i<18;i++)
        if(dep[x]-dep[y]>>i&1)
            x=spa[x][i];
    if(x==y)
        return x;
    for(int i=18;i-->0;)
        if(spa[x][i]!=spa[y][i])
            x=spa[x][i],y=spa[y][i];
    return pa[x];
}
int kpa(int x,int k)
{
    for(int i=0;i<18;i++)
        if(k>>i&1)
            x=spa[x][i];
    return x;
}
vector<pi>adj[100010];
void dfs(int x)
{
    spa[x][0]=pa[x];
    for(int i=0;i<17;i++)
        spa[x][i+1]=spa[spa[x][i]][i];
    for(pi&t:adj[x])
        if(pa[x]!=t.fi&&t.se==1)
            dep[t.fi]=dep[pa[t.fi]=x]+1,dfs(t.fi);
    return;
}
int udp[100010],ldp[100010];
void dfs2(int x)
{
    for(pi&t:adj[x])
        if(pa[x]!=t.fi&&t.se==1)
            ldp[t.fi]+=ldp[x],dfs2(t.fi),udp[x]+=udp[t.fi];
    return;
}
bool flag;
bool vis[100010];
void dfs3(int x)
{
    vis[x]=1;
    for(pi&t:adj[x])
    {
        if(vis[t.fi])
            if(t.se==1)
                flag=1;
        else if(t.se==0)
            flag=1;
        else
            dfs3(t.fi);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(uf.uni(u,v))
            adj[u].eb(v,1),adj[v].eb(u,1);
        else
            adj[u].eb(v,0),adj[v].eb(u,0);
    }
    dfs(1);
    for(int i=0;i++<n;)
    {
        for(pi&t:adj[i])
        {
            if(t.se==0&&i<t.fi)
            {
                int l=lca(i,t.fi);
                if(l==i)
                    ldp[t.fi]--,ldp[kpa(t.fi,dep[t.fi]-dep[i]-1)]++;
                else if(l==t.fi)
                    ldp[i]--,ldp[kpa(i,dep[i]-dep[t.fi]-1)]++;
                else
                    ldp[i]--,ldp[t.fi]--,ldp[1]++;
            }
        }
    }
    dfs2(1);
    vector<int>vv;
    for(int i=0;i++<n;)
        if(ldp[i]+udp[i]==0)
            vv.eb(i);
    if(vv.empty())
        for(int i=0;i<n;i++)
            cout<<'0';
    else
    {
        dfs3(vv[0]);
        if(flag)
            for(int i=0;i<n;i++)
                cout<<'0';
        else
        {
            vector<int>ans(n,0);
            for(int&t:vv)
                ans[t-1]=1;
            for(int&t:ans)
                cout<<t;
        }
    }
    cout<<endl;
    return 0;
}