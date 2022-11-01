#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define pp pop_back()
#define mp3(a,b,c) mp(a,mp(b,c))
#define mp4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,d),min(b,c))
#define pii pair<int,int>
#define piii pair<int,pii >
#define pi4 pair<pair<int,int>,pair<int,int>>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define two(n) (1<<n)
#define bit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define read4(a,b,c,d) read(a),read(b),read(c),read(d)
#define gcd(a,b) abs(__gcd(a,b))
#define lim 2139062143
using namespace std;
const int N=100010,mod=1e9+7;
int n,q,id,tin[N],tout[N],dd[N],ans[N],d[N],a[4*N],b[4*N],mem[4*N],c[N];
vector<pii> ke[N],ad[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void dfs(int u)
{
    dd[u]=1;
    tin[u]=++id;
    c[tin[u]]=d[u];
    forv(v,ke[u]) if(!dd[v.fi])
    {
        d[v.fi]=(d[u]+v.se)%mod;
        dfs(v.fi);
    }
    tout[u]=id;
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        a[s]=c[l];
        b[s]=(c[l]*c[l])%mod;
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    a[s]=(a[2*s]+a[2*s+1])%mod;
    b[s]=(b[2*s]+b[2*s+1])%mod;
}
void tran(int s,int l,int r)
{
    if(!mem[s]) return;
    int mid=(l+r)/2;
    b[2*s]=(b[2*s]+mem[s]*mem[s]%mod*(mid-l+1)+2ll*mem[s]*a[2*s])%mod;
    b[2*s+1]=(b[2*s+1]+mem[s]*mem[s]%mod*(r-mid)+2ll*mem[s]*a[2*s+1])%mod;
    a[2*s]=(a[2*s]+mem[s]*(mid-l+1))%mod;
    mem[2*s]=(mem[2*s]+mem[s])%mod;
    a[2*s+1]=(a[2*s+1]+mem[s]*(r-mid))%mod;
    mem[2*s+1]=(mem[2*s+1]+mem[s])%mod;
    mem[s]=0;
}
void update(int s,int l,int r,int u,int v,int x)
{
    int mid=(l+r)/2;
    if(v<l||r<u) return;
    if(u<=l&&r<=v)
    {
        b[s]=(b[s]+x*x%mod*(r-l+1)+2ll*x*a[s])%mod;
        a[s]=(a[s]+x*(r-l+1))%mod;
        mem[s]=(mem[s]+x)%mod;
        return;
    }
    tran(s,l,r);
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    a[s]=(a[2*s]+a[2*s+1])%mod;
    b[s]=(b[2*s]+b[2*s+1])%mod;
}
int get(int s,int l,int r,int u,int v)
{
    if(u>v) return 0;
    if(v<l||r<u) return 0;
    if(u<=l&&r<=v) return b[s];
    tran(s,l,r);int mid=(l+r)/2;
    return (get(2*s,l,mid,u,v)+get(2*s+1,mid+1,r,u,v))%mod;
}
int query(int u)
{
    return (2ll*get(1,1,n,tin[u],tout[u])-b[1])%mod;
}
void DFS(int u)
{
    dd[u]=1;
    forv(v,ad[u]) ans[v.se]=query(v.fi);
    forv(v,ke[u]) if(!dd[v.fi])
    {
        update(1,1,n,tin[v.fi],tout[v.fi],-v.se);
        update(1,1,n,1,tin[v.fi]-1,v.se);
        update(1,1,n,tout[v.fi]+1,n,v.se);
        DFS(v.fi);
        update(1,1,n,tin[v.fi],tout[v.fi],v.se);
        update(1,1,n,1,tin[v.fi]-1,-v.se);
        update(1,1,n,tout[v.fi]+1,n,-v.se);
    }
}
main()
{
    //freopen("494D.inp","r",stdin);
    read(n);
    forinc(i,1,n-1)
    {
        int u,v,c;
        read3(u,v,c);
        ke[u].pb({v,c});
        ke[v].pb({u,c});
    }
    dfs(1);
    read(q);
    forinc(i,1,q)
    {
        int u,v;
        read2(u,v);
        ad[u].pb({v,i});
    }
    build(1,1,n);
    reset(dd,0);
    DFS(1);
    forinc(i,1,q) cout<<(ans[i]+mod)%mod<<"\n";
}