#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
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
const int N=3e5+10;
int n,a[N],dd[N],lt[N],kq,k,id,f[N],g[N],s,d[N];
pii e[N];
vector<int> ke[N],ad[N],sv,pre[N];
void dfs(int u)
{
    f[id]+=a[u];
    dd[u]=1;
    lt[u]=id;
    if(a[u]<=0) return;
    forv(v,ke[u]) if(a[v]>0&&!dd[v]) dfs(v);
}
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
void DFS(int u)
{
    dd[u]=1;
    g[u]=f[u];
    forv(v,ad[u]) if(!dd[v])
    {
        DFS(v);
        if(g[v]>0)
        {
            g[u]+=g[v];
            pre[u].pb(v);
        }
    }
    if(g[u]>kq)
    {
        kq=g[u];
        sv.clear();
        sv.pb(u);
    }
    else if(g[u]==kq) sv.pb(u);
}
void sub()
{
    sort(a+1,a+n+1,greater<int>());
    forinc(i,1,n) if(a[i]==a[1])
    {
        s+=a[i];k++;
    }
    cout<<s<<" "<<k;
}
bool BFS(int u)
{
    if(dd[u]) return 1;
    dd[u]=1;
    forv(v,pre[u]) if(dd[v]||BFS(v)) return 1;
    return 0;
}
main()
{
    //freopen("e.inp","r",stdin);
    //freopen("E.out","w",stdout);
    read(n);
    bool ok=0;
    forinc(i,1,n)
    {
        read(a[i]);
        if(a[i]>0) ok=1;
    }
    if(!ok) {sub();return 0;}
    forinc(i,1,n-1)
    {
        int u,v;
        read2(u,v);
        ke[u].pb(v);
        ke[v].pb(u);
        e[i]={u,v};
    }
    forinc(i,1,n) if(!dd[i]) {id++;dfs(i);}
    forinc(i,1,n-1)
    {
        int u=e[i].fi,v=e[i].se;
        if(lt[u]==lt[v]) continue;
        ad[lt[u]].pb(lt[v]);
        ad[lt[v]].pb(lt[u]);
    }
    reset(dd,0);
    DFS(1);
    reset(dd,0);
    forinc(i,0,sv.size()-1) if(!BFS(sv[i])) s+=kq,k++;
    cout<<s<<" "<<k;
}