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
constexpr int N=2E5+10,M=21;
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
int fa[N],son[N],siz[N],dep[N],top[N],n;
int dfn[N],low[N],cnt;
int f[N][M],g[N][M];
void add(int x,int y,int k){for(;x<=n;x+=x&-x)f[x][y]+=k;}
int ask(int x,int y){int z=0;for(;x;x-=x&-x)z+=f[x][y];return z;}
void dfs(int x)
{
    dfn[x]=++cnt;
    siz[x]=1;
    for(int t:to[x])if(t^fa[x])
    {
        fa[t]=x;
        dep[t]=dep[x]+1;
        dfs(t);
        siz[x]+=siz[t];
        if(siz[t]>siz[son[x]])son[x]=t;
    }
    low[x]=cnt;
}
void dfs(int x,int o)
{
    top[x]=o;
    for(int t:to[x])if(t^fa[x])dfs(t,t^son[x]?t:o);
}
int lca(int l,int r)
{
    while(top[l]^top[r])dep[top[l]]>dep[top[r]]?l=fa[top[l]]:r=fa[top[r]];
    return dep[l]<dep[r]?l:r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1);
    dfs(1,1);
    for(int m=read();m--;)
    {
        if(read()&1)
        {
            int x=read(),ans=0;
            for(int i=0;i<M;++i,x=fa[x])
            {
                ans+=g[x][i];
                if(!x)break;
                ans+=ask(low[x],i)-ask(dfn[x]-1,i);
            }
            cout<<ans<<'\n';
        }
        else
        {
            int u=read(),v=read(),w=lca(u,v),k=read(),d=read();
            add(dfn[u],d,k);
            add(dfn[v],d,k);
            add(dfn[w],d,-k<<1);
            for(int i=d;i>=0;--i,w=fa[w])
            {
                g[w][i]+=k;
                if(w&&i)g[w][i-1]+=k;
            }
        }
    }
}