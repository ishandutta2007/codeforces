#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
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
const ll mod=998244353;
inline ll pow(ll x,ll y)
{
    ll ans=1;
    while(y>0)
    {
        if(y&1)
            ans=ans*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
vector<int>adj[150010];
int sz[150010];
int in[150010],out[150010];
int nct;
vector<pi>adj2[150010];
void dfs(int x,int p)
{
    sz[x]=1;
    for(int&t:adj[x])
        adj[t].erase(find(all(adj[t]),x)),dfs(t,x),sz[x]+=sz[t];
    sort(all(adj[x]),[=](int&p,int&q){return sz[p]<sz[q];});
    return;
}
int ord[150010];
void dfs2(int x,int p)
{
    ord[in[x]=++nct]=x;
    for(int&t:adj[x])
        dfs2(t,x);
    out[x]=nct;
    if(adj[x].empty())
        return;
    adj2[x].eb(in[adj[x][0]],out[adj[x][0]]);
    int fs=sz[adj[x][0]];
    for(int i=1;i<adj[x].size();i++)
    {
        if(sz[adj[x][i]]==fs)
            adj2[x].back().se=out[adj[x][i]];
        else
            adj2[x].eb(in[adj[x][i]],out[adj[x][i]]),fs=sz[adj[x][i]];
    }
    return;
}
struct fenwick
{
    ll dat[150010];
    inline void fi(int x,ll d)
    {
        if(x<=0)
            return;
        for(;x<150010;x+=x&-x)
        {
            dat[x]+=d;
            if(dat[x]>=mod)
                dat[x]-=mod;
        }
        return;
    }
    inline void fi(int s,int e,ll d)
    {
        if(d==0)
            return;
        fi(s,d);
        fi(e+1,mod-d);
        return;
    }
    inline ll get(int x)
    {
        ll s=0;
        for(;x>0;x=x&x-1)
            s+=dat[x];
        return s%mod;
    }
}ft;
ll inv[150010];
int n,q,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(i=0;i++<n;)
        inv[i]=pow(i,mod-2);
    for(i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(1,0);
    dfs2(1,0);
    while(q-->0)
    {
        int t,x;
        ll y;
        cin>>t>>x;
        if(t==1)
            cin>>y;
        if(t==1)
        {
            if(y==0)
                continue;
            ll val=y*sz[x]%mod*inv[n]%mod;
            if(in[x]>1)
                ft.fi(1,in[x]-1,val);
            if(out[x]<n)
                ft.fi(out[x]+1,n,val);
            for(pi&t:adj2[x])
            {
                val=y*(n-sz[ord[t.fi]])%mod*inv[n]%mod;
                ft.fi(t.fi,t.se,val);
            }
            ft.fi(in[x],in[x],y);
        }
        else
            cout<<ft.get(in[x])<<'\n';
    }
    cout<<endl;
    return 0;
}