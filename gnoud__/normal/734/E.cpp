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
const int N=200010;
int a[N],n,lt[N],dd[N],id,o,tg;
vector<int> ke[N],ad[N];
pii e[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void DFS(int u)
{
    dd[u]=1;lt[u]=id;
    forv(v,ke[u]) if(!dd[v]&&a[u]==a[v]) DFS(v);
}
void Dfs(int u,int c)
{
    dd[u]=1;
    if(c>tg) tg=c,o=u;
    forv(v,ad[u]) if(!dd[v]) Dfs(v,c+1);
}
int main()
{
    //freopen("734E.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(a[i]);
    forinc(i,1,n-1)
    {
        int u,v;
        read(u);read(v);
        ke[u].pb(v);ke[v].pb(u);
        e[i]={u,v};
    }
    forinc(i,1,n) if(!dd[i]) {id++;DFS(i);}
    forinc(i,1,n-1)
    {
        int u=e[i].fi,v=e[i].se;
        if(lt[u]==lt[v]) continue;
        ad[lt[u]].pb(lt[v]);
        ad[lt[v]].pb(lt[u]);
    }
    forinc(i,1,id)
    {
        sort(ad[i].begin(),ad[i].end());
        ad[i].erase(unique(all(ad[i])),ad[i].end());
    }
    reset(dd,0);
    Dfs(1,0);
    reset(dd,0);
    Dfs(o,0);
    cout<<(tg+1)/2;
}