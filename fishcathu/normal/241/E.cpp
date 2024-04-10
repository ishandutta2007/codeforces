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
constexpr int N=1010;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<int>f[N],g[N];
vector<pii>to[N];
int col[N],dis[N],num[N],n;
void dfs1(vector<int>*to,int x,int k)
{
    col[x]|=k;
    for(int t:to[x])if(~col[t]&k)dfs1(to,t,k);
}
void dfs2(int x)
{
    for(auto [t,w]:to[x])if(cmax(dis[t],dis[x]+w))
    {
        if(++num[t]>=n)cout<<"No\n",exit(0);
        dfs2(t);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n;
    vector<pii>a(read());
    for(auto &[u,v]:a)
    {
        cin>>u>>v;
        f[u].pb(v);
        g[v].pb(u);
    }
    dfs1(f,1,1);
    dfs1(g,n,2);
    for(auto [u,v]:a)
    {
        if(col[u]<3||col[v]<3)continue;
        to[u].pb({v,1});
        to[v].pb({u,-2});
    }
    for(int i=1;i<=n;++i)if(col[i]==3)dfs2(i);
    cout<<"Yes\n";
    for(auto [u,v]:a)
    {
        if(col[u]<3||col[v]<3)cout<<"1\n";
        else cout<<dis[v]-dis[u]<<'\n';
    }
}