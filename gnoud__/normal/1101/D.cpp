#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=200010;
int n,dd[N],dis[N],g[N],a[N],cnt,c[N],f[N],p[N],kq;
vector<int> ke[N];
vector<int> sv,rs;
void snt()
{
    forinc(i,2,N-10) if(!p[i])
    for(int j=i;j<=N-10;j+=i) p[j]=i;
}
void update(int x,int s)
{
    while(x!=1)
    {
        rs.pb(p[x]);
        f[p[x]]=max(f[p[x]],s);
        x/=p[x];
    }
}
int get(int x,int s)
{
    while(x!=1)
    {
        kq=max(kq,f[p[x]]+s+1);
        x/=p[x];
    }
}
void BFS(int u,int p,int goc)
{
    if(u!=goc) sv.pb(u);
    forv(v,ke[u]) if(!dd[v]&&v!=p)
    {
        dis[v]=dis[u]+1;
        g[v]=__gcd(g[u],a[v]);
        BFS(v,u,goc);
        if(u==goc)
        {
            forv(x,sv) get(g[x],dis[x]);
            forv(x,sv) update(g[x],dis[x]);
            sv.clear();
        }
    }
}
void DFS(int u,int p)
{
    c[u]=1;cnt++;
    forv(v,ke[u]) if(v!=p && !dd[v]) DFS(v,u),c[u]+=c[v];
}
int Find(int u,int p)
{
    forv(v,ke[u]) if(v!=p && !dd[v] && c[v]>cnt/2) return Find(v,u);
    return u;
}
void CTR(int u,int p)
{
    cnt=0;
    DFS(u,u);
    int z=Find(u,u);
    dd[z]=true;
    forv(v,rs) f[v]=0;rs.clear();
    if(a[z]>1)
    {
        g[z]=a[z];
        dis[z]=0;
        update(a[z],0);
        BFS(z,p,z);
    }
    forv(v,ke[z]) if(!dd[v]) CTR(v,z);
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("1101D.inp","r",stdin);
    read(n);
    snt();
    forinc(i,1,n)
    {
        read(a[i]);
        if(a[i]>1) kq=1;
    }
    forinc(i,1,n-1)
    {
        int u,v;
        read2(u,v);
        ke[u].pb(v);
        ke[v].pb(u);
    }
    CTR(1,0);
    cout<<kq;
}