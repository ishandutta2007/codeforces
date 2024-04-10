#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
int pa[100010],mm[100010],sz[100010];
int par(int x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
inline void uni(int x,int y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[x]=y;
    mm[y]=min(mm[y],mm[x]);
    sz[y]+=sz[x];
    return;
}
vector<int>adj[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    vector<int>V(n);
    for(i=0;i<n;i++)
        V[i]=i+1;
    sort(all(V),[=](int x,int y){return adj[x].size()<adj[y].size();});
    vector<bool>chk(n+1,0);
    for(i=0;i<n;i++)
        mm[i]=i,sz[i]=1,pa[i]=-1;
    int X=0,cc=0;
    for(i=n;i-->0;)
    {
        for(int x:adj[V[i]])
            chk[x]=1;
        for(int j=0;j<i;j++)
            if(!chk[V[j]])
                uni(i,j);
        if(X+sz[par(i)]==n)
            break;
        if(mm[par(i)]==i)
        {
            cc++;
            X+=sz[par(i)];
        }
        for(int x:adj[V[i]])
            chk[x]=0;
    }
    cout<<cc<<endl;
    return 0;
}