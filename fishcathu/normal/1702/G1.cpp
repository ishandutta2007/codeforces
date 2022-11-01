#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
constexpr int N=2E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<int>to[N];
int fa[N],son[N],dep[N],siz[N],top[N],a[N],dfn[N],cnt;
void dfs1(int x)
{
    dfn[x]=++cnt;
    for(int t:to[x])if(t^fa[x])
    {
        fa[t]=x;
        dep[t]=dep[x]+1;
        dfs1(t);
        siz[x]+=siz[t];
        if(siz[t]>siz[son[x]])son[x]=t;
    }
    ++siz[x];
}
void dfs2(int x,int o)
{
    top[x]=o;
    for(int t:to[x])if(t^fa[x])dfs2(t,t^son[x]?t:o);
}
int lca(int l,int r)
{
    while(top[l]^top[r])dep[top[l]]>dep[top[r]]?l=fa[top[l]]:r=fa[top[r]];
    return dep[l]<dep[r]?l:r;
}
bool solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n,[](int x,int y){return dfn[x]<dfn[y];});
    int x=0;
    for(int i=2;i<=n;++i)if(dfn[a[i]]>=dfn[a[i-1]]+siz[a[i-1]])
    {
        if(x)return 0;
        x=i;
    }
    return x<3||dep[lca(a[x],a[2])]<=dep[a[1]];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    for(int m=read();m--;cout<<(solve()?"YES":"NO")<<'\n');
}