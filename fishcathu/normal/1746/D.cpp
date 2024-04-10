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

int a[N];
ll f[N],g[N];
vector<int>to[N];
void dfs(int x,int s)
{
    f[x]=1LL*a[x]*s;
    if(to[x].empty())g[x]=f[x]+a[x];
    else
    {
        vector<ll>q;
        int u=s/to[x].size(),v=s%to[x].size();
        for(int t:to[x])
        {
            dfs(t,u);
            f[x]+=f[t];
            q.pb(g[t]-f[t]);
        }
        sort(q.begin(),q.end(),greater<ll>());
        for(int i=0;i<v;++i)f[x]+=q[i];
        g[x]=f[x]+a[x]+q[v];
    }
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=2;i<=n;++i)to[read()].pb(i);
    for(int i=1;i<=n;++i)cin>>a[i];
    dfs(1,m);
    cout<<f[1]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}