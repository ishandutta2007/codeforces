#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
const int N=500010;
int n,q,t[4*N],mem[4*N],in[N],out[N],ans[N],id,d[N];
vector<pii> ke[N];
struct oo {int l,r,id;};
vector<oo> sv[N];
void DFSs(int u)
{
    in[u]=++id;
    forv(v,ke[u])
    {
        d[v.fi]=d[u]+v.se;
        DFSs(v.fi);
    }
    out[u]=id;
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        t[s]=(ke[l].empty())?d[l]:1e18;
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=min(t[2*s],t[2*s+1]);
}
void tran(int s)
{
    if(!mem[s]) return;
    int m=mem[s];
    mem[2*s]+=m;
    mem[2*s+1]+=m;
    t[2*s]+=m;
    t[2*s+1]+=m;
    mem[s]=0;
}
void update(int s,int l,int r,int u,int v,int x)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]+=x;
        mem[s]+=x;
        return;
    }
    tran(s);
    int mid=(l+r)/2;
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    t[s]=min(t[2*s],t[2*s+1]);
}
int get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return 1e18;
    if(l>=u&&r<=v) return t[s];
    tran(s);
    int mid=(l+r)/2;
    return min(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v));
}
void DFS(int u)
{
    forv(x,sv[u]) ans[x.id]=get(1,1,n,x.l,x.r);
    forv(v,ke[u])
    {
        t[1]+=v.se;mem[1]+=v.se;
        update(1,1,n,in[v.fi],out[v.fi],-v.se*2);
        DFS(v.fi);
        t[1]-=v.se;mem[1]-=v.se;
        update(1,1,n,in[v.fi],out[v.fi],v.se*2);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("1110F.inp","r",stdin);
    cin>>n>>q;
    forinc(i,2,n)
    {
        int p,w;
        cin>>p>>w;
        ke[p].pb({i,w});
    }
    DFSs(1);
    //return 0;
    build(1,1,n);
    forinc(i,1,q)
    {
        int u,l,r;
        cin>>u>>l>>r;
        sv[u].pb({l,r,i});
    }
    DFS(1);
    forinc(i,1,q) cout<<ans[i]<<"\n";
}