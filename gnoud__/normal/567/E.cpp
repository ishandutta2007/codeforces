#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define read3(a,b,c) read(a),read(b),read(c)
using namespace std;
const int N=100010;
int dd[N],num[N],low[N],n,m,s,t,d[N],_d[N],ans[N],id,trc[N];
vector<pii> ke[N],ad[N],_ke[N];
struct oo {int u,v,c;};
oo e[N];
map<int,int> fre[N];
void DTJ(int u)
{
    dd[u]=true;
    num[u]=low[u]=++id;
    forv(v,_ke[u])
    if(v.fi!=trc[u]) if(!dd[v.fi]) {
        trc[v.fi]=u;DTJ(v.fi);
        low[u]=min(low[u],low[v.fi]);
    }
    else low[u]=min(low[u],num[v.fi]);
}
bool cau(int u,int v)
{
    return ((trc[v]==u&&low[v]>num[u])||(trc[u]==v&&low[u]>num[v]));
}
priority_queue<pii,vector<pii>,greater<pii> > heap;
void BFS()
{
    memset(dd,0,sizeof(dd));
    forinc(i,1,n) d[i]=1e17;
    d[s]=0;
    heap.push({0,s});
    while(!heap.empty())
    {
        pii u=heap.top();heap.pop();
        if(dd[u.se]) continue;
        dd[u.se]=1;
        forv(v,ke[u.se]) if(u.fi+v.se<d[v.fi])
        {
            d[v.fi]=u.fi+v.se;
            heap.push({d[v.fi],v.fi});
        }
    }
}
void DFS()
{
    memset(dd,0,sizeof(dd));
    forinc(i,1,n) _d[i]=1e17;
    _d[t]=0;
    heap.push({0,t});
    while(!heap.empty())
    {
        pii u=heap.top();heap.pop();
        if(dd[u.se]) continue;
        dd[u.se]=1;
        forv(v,ad[u.se]) if(u.fi+v.se<_d[v.fi])
        {
            _d[v.fi]=u.fi+v.se;
            heap.push({_d[v.fi],v.fi});
        }
    }
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
main()
{
    //freopen("567E.inp","r",stdin);
    //freopen("567E.out","w",stdout);
    read3(n,m,s);read(t);
    forinc(i,1,m)
    {
        int u,v,c;
        read3(u,v,c);
        e[i]={u,v,c};
        ke[u].pb({v,c});
        ad[v].pb({u,c});
    }
    BFS();DFS();
    forinc(i,1,m)
    {
        int u=e[i].u,v=e[i].v,c=e[i].c;
        if(d[u]+_d[v]+c==d[t])
        {
            if(!fre[u][v])
            _ke[u].pb({v,i}),
            _ke[v].pb({u,i}),
            fre[u][v]=fre[v][u]=1;
            else fre[u][v]=fre[v][u]=2;
        }
    }
    memset(dd,0,sizeof(dd));
    forinc(i,1,n) if(!dd[i]) DTJ(i);
    forinc(u,1,n) forv(v,_ke[u]) if(cau(u,v.fi)&&fre[u][v.fi]<2ll) ans[v.se]=1;
    forinc(i,1,m)
    {
        if(ans[i]) {cout<<"YES"<<"\n";continue;}
        int u=e[i].u,v=e[i].v,c=e[i].c;
        int C=(d[u]+_d[v]+c)-d[t]+1;
        if(C<c) cout<<"CAN"<<" "<<C<<"\n";
        else cout<<"NO"<<"\n";
    }
}