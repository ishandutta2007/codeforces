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
const int N=300010;
int id[N],n,m,q,ma[N],fre[N],f[N],dd[N];
int root(int x)
{
    return id[x]<0?x:id[x]=root(id[x]);
}
vector<int> ke[N],luu;
void unions(int u,int v)
{
    int U=root(u),V=root(v);
    if(U==V) return;
    ma[U]=max3(ma[U],ma[V],(ma[U]+1)/2+(ma[V]+1)/2+1);
    id[U]+=id[V];
    id[V]=U;
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int tg,o;
void DFS(int u)
{
    luu.pb(u);
    dd[u]=true;
    forv(v,ke[u]) if(!dd[v])
    {
        f[v]=f[u]+1;
        if(f[v]>tg) {tg=f[v],o=v;}
        DFS(v);
    }
}
void Memset()
{
    forv(v,luu) dd[v]=f[v]=0;
    luu.clear();tg=0;
}
int main()
{
    //freopen("455C.inp","r",stdin);
    //freopen("ASTRAY.out","w",stdout);
    read3(n,m,q);reset(id,-1);
    forinc(i,1,m)
    {
        int u,v;
        read2(u,v);
        ke[u].pb(v);ke[v].pb(u);
        if((u=root(u))==(v=root(v))) continue;
        id[u]+=id[v];id[v]=u;
    }
    forinc(i,1,n) if(!fre[root(i)])
    {
        Memset();o=i;
        fre[root(i)]=1;
        DFS(i);Memset();DFS(o);ma[root(i)]=tg;
    }
    forinc(i,1,q)
    {
        int tv;
        read(tv);
        if(tv==2)
        {
            int u,v;
            read2(u,v);
            unions(u,v);
        }
        else {int x;read(x);cout<<ma[root(x)]<<"\n";}
    }
}