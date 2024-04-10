#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
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
const int N=100010;
int tin[N],tout[N],it,n,m,f[N][20],dem,tv,q[N],cac[N],id[N],mi[N][20];
piii e[N];
pii g[N];
vector<pii> ke[N];
bool dd[N];
void DFS(int u)
{
    dd[u]=1;
    tin[u]=++it;
    forinc(i,1,log2(n))
    {
        f[u][i]=f[f[u][i-1]][i-1];
        mi[u][i]=max(mi[u][i-1],mi[f[u][i-1]][i-1]);
    }
    forv(v,ke[u]) if(!dd[v.fi])
    {
        f[v.fi][0]=u;
        mi[v.fi][0]=v.se;
        DFS(v.fi);
    }
    tout[u]=++it;
}
int root(int x)
{
    return id[x]<0?x:id[x]=root(id[x]);
}
bool unions(int u,int v)
{
    if((u=root(u))==(v=root(v))) return 0;
    id[u]+=id[v];id[v]=u;return 1;
}
bool cheq(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int LCA(int u,int v)
{
    if(cheq(u,v)) return u;
    if(cheq(v,u)) return v;
    fordec(i,log2(n),0) if(!cheq(f[u][i],v)&&f[u][i]!=0) u=f[u][i];
    return f[u][0];
}
int get(int u,int v)
{
    int pa=LCA(u,v);
    int Mi=0;
    fordec(i,log2(n),0) if(!cheq(f[u][i],pa)&&f[u][i]!=0) {Mi=max(Mi,mi[u][i]);u=f[u][i];}
    if(u!=pa) Mi=max(Mi,mi[u][0]);
    fordec(i,log2(n),0) if(!cheq(f[v][i],pa)&&f[v][i]!=0) {Mi=max(Mi,mi[v][i]);v=f[v][i];}
    if(v!=pa) Mi=max(Mi,mi[v][0]);
    return Mi;
}
int main()
{
    //freopen("466E.inp","r",stdin);
    //freopen("466E.out","w",stdout);
    read2(n,m);reset(id,-1);
    forinc(i,1,m)
    {
        int t;read(t);
        if(t==1) {int x,y;read2(x,y);ke[y].pb({x,i});cac[x]=1;unions(x,y);}
        if(t==2) {int x;read(x);g[++dem]={x,i};}
        if(t==3) {int x,y;read2(x,y);e[++tv]=mp3(unions(x,g[y].fi),x,y);}
    }
    forinc(i,1,n) if(!dd[i]&&!cac[i]) DFS(i);
    forinc(i,1,tv)
    {
        if(e[i].fi==1) {cout<<"NO\n";continue;}
        int x=e[i].sf,y=g[e[i].ss].fi;
        if(cheq(x,y)&&get(x,y)<g[e[i].ss].se) cout<<"YES\n";
        else cout<<"NO\n";
    }
}