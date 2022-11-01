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
const int N=1e5+10;
int n,m,k,dd[N],x[N],o[N],ans[N],id[N],p[N],ma;
int root(int x) {return id[x]<0?x:id[x]=root(id[x]);}
piii e[N];
vector<pii> ke[N];
vector<int> sv;
void DFS(int u)
{
    if(o[u]) {sv.pb(u);p[u]=1;}
    dd[u]=1;
    forv(v,ke[u]) if(!dd[v.fi])
    {
        DFS(v.fi);
        if(p[v.fi])
        {
            p[u]=1;
            ma=max(ma,v.se);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("a.inp","r",stdin);
    cin>>n>>m>>k;
    forinc(i,1,k) {cin>>x[i];o[x[i]]=1;}
    forinc(i,1,m)
    {
        int u,v,c;
        cin>>u>>v>>c;
        e[i]=mp3(c,u,v);
    }
    sort(e+1,e+m+1);
    reset(id,-1);
    forinc(i,1,m)
    {
        int u=e[i].sf,v=e[i].ss;
        int U=root(u),V=root(v);
        if(U==V) continue;
        id[U]+=id[V];
        id[V]=U;
        ke[u].pb({v,e[i].fi});
        ke[v].pb({u,e[i].fi});
    }
    forinc(i,1,k) if(!dd[x[i]])
    {
        sv.clear();ma=0;
        DFS(x[i]);
        forv(u,sv) ans[u]=ma;
    }
    forinc(i,1,k) cout<<ans[x[i]]<<" ";
}