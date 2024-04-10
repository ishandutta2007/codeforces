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

int fa[N];
bool b[N],flag;
vector<pii>f[N],g[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void dfs(int x,int fa,int y)
{
    flag|=x==y;
    for(auto [t,v]:f[x])if(t^fa)dfs(t,x,y);
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)fa[i]=i,f[i].clear(),g[i].clear();
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),x=find(u),y=find(v);
        if(x^y)f[u].pb({v,i}),f[v].pb({u,i}),fa[x]=y,b[i]=0;
        else g[u].pb({v,i}),g[v].pb({u,i}),b[i]=1;
    }
    int s=0,x,y,u;
    for(int i=1;i<=n;++i)if(!g[i].empty()&&!s++)x=i,y=g[i][0][0],u=g[i][0][1];
    if(m-n==2&&s==3)
    {
        for(auto [t,v]:f[x])
        {
            flag=0;
            dfs(t,x,y);
            if(flag)
            {
                swap(b[u],b[v]);
                break;
            }
        }
    }
    for(int i=1;i<=m;++i)cout<<b[i];
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}