#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define int long long
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
const int N=110000;
vector<pii> ke[N];
int dd[N],tin[N],tout[N],f[N][20],n,m,c[N],fre[N],id;
ll dis[N],d[50][N];
pii e[N];
vector<int> t;
priority_queue<pii,vector<pii>,greater<pii> > heap;
void DIJ(int s)
{
    reset(dd,0);
    forinc(i,1,n) d[s][i]=1e17;
    d[s][t[s]]=0;
    heap.push({0,t[s]});
    while(!heap.empty())
    {
        pii u=heap.top();heap.pop();
        if(dd[u.se]) continue;
        dd[u.se]=1;
        forv(v,ke[u.se]) if(d[s][v.fi]>u.fi+c[v.se])
        {
            d[s][v.fi]=u.fi+c[v.se];
            heap.push({d[s][v.fi],v.fi});
        }
    }
}
void DFS(int u)
{
    dd[u]=1;tin[u]=++id;
    forinc(i,1,log2(n)) f[u][i]=f[f[u][i-1]][i-1];
    forv(v,ke[u]) if(!dd[v.fi])
    {
        fre[v.se]=1;f[v.fi][0]=u;
        dis[v.fi]=dis[u]+c[v.se];DFS(v.fi);
    }
    tout[u]=++id;
}
bool cheq(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int LCA(int u,int v)
{
    if(cheq(u,v)) return u;
    if(cheq(v,u)) return v;
    fordec(i,log2(n),0) if(!cheq(f[u][i],v)&&f[u][i]) u=f[u][i];
    return f[u][0];
}
ll leng(int u,int v) {return dis[u]+dis[v]-2*dis[LCA(u,v)];}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
main()
{
    //freopen("1051F.inp","r",stdin);
    read2(n,m);
    forinc(i,1,m)
    {
        int u,v,C;
        read3(u,v,C);
        c[i]=C;e[i]={u,v};
        ke[u].pb({v,i});
        ke[v].pb({u,i});
    }
    DFS(1);
    forinc(i,1,m) if(!fre[i]) t.pb(e[i].fi),t.pb(e[i].se);
    sort(all(t));
    t.erase(unique(all(t)),t.end());
    if(!t.empty()) forinc(i,0,t.size()-1) DIJ(i);
    int q;read(q);
    while(q--)
    {
        int u,v;
        read2(u,v);
        if(u==v) {cout<<"0\n";continue;}
        ll res=leng(u,v);
        if(!t.empty()) forinc(i,0,t.size()-1) res=min(res,d[i][u]+d[i][v]);
        cout<<res<<"\n";
    }
}