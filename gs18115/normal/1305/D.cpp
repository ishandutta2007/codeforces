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
const ll INF=1e18+7;
int lca(int u,int v)
{
    cout<<"? "<<u<<' '<<v<<endl;
    int w;
    cin>>w;
    return w;
}
vector<int>adj[1010];
int sz[1010];
void dfs(int x,int p)
{
    sz[x]=1;
    for(int&t:adj[x])
        if(t!=p)
            dfs(t,x),sz[x]+=sz[t];
    return;
}
pi gt;
void get(int x,int p,int z)
{
    if(sz[x]>1&&z-sz[x]>1)
        gt=pi(x,p);
    for(int&t:adj[x])
        if(t!=p)
            get(t,x,z);
    return;
}
vector<int>V,V2;
void get2(int x,int p)
{
    if(adj[x].size()==1)
        V.eb(x);
    else
        V2.eb(x);
    for(int&t:adj[x])
        if(t!=p)
            get2(t,x);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    vector<int>lf;
    int cr=1;
    while(true)
    {
        dfs(cr,0);
        gt=pi(-1,-1);
        get(cr,0,sz[cr]);
        if(gt.fi==-1)
            break;
        int p=gt.fi;
        int q=gt.se;
        int l=lca(p,q);
        if(l==q)
            swap(p,q);
        adj[p].erase(find(all(adj[p]),q));
        cr=p;
    }
    if(adj[cr].empty())
        return cout<<"! "<<cr<<endl,0;
    get2(cr,0);
    if(V2.empty())
    {
        int l=lca(V[0],V[1]);
        return cout<<"! "<<l<<endl,0;
    }
    V.eb(V2[0]);
    for(int i=0;i*2+1<V.size();i++)
    {
        int p=V[i*2];
        int q=V[i*2+1];
        int l=lca(p,q);
        if(p==l)
            return cout<<"! "<<p<<endl,0;
        if(q==l)
            return cout<<"! "<<q<<endl,0;
    }
    cout<<"! "<<V2[0]<<endl;
    return 0;
}