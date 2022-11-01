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

vector<int>pri,q[N];
int inv[N],f[N],ans,res;
vector<array<int,3>>to[N];
void dfs(int x,int fa)
{
    for(auto [t,u,v]:to[x])if(t^fa)
    {
        res=1LL*res*inv[u]%p*v%p;
        (ans+=res)%=p;
        for(int a:q[v])++f[a];
        for(int a:q[u])
        {
            if(f[a])--f[a];
            else ans=1LL*ans*a%p,res=1LL*res*a%p;
        }
        dfs(t,x);
        res=1LL*res*u%p*inv[v]%p;
        for(int a:q[u])++f[a];
        for(int a:q[v])--f[a];
    }
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=n;--i;)
    {
        int u=read(),v=read(),x=read(),y=read(),t=__gcd(x,y);
        x/=t;
        y/=t;
        to[u].pb({v,x,y});
        to[v].pb({u,y,x});
    }
    ans=res=1;
    for(int i=2;i<=n;++i)f[i]=0;
    dfs(1,0);
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    inv[1]=1;
    for(int i=2;i<N;++i)
    {
        inv[i]=1LL*(p-p/i)*inv[p%i]%p;
        if(q[i].empty())q[i].pb(i),pri.pb(i);
        for(int j:pri)
        {
            int x=i*j;
            if(x>=N)break;
            q[x]=q[i];
            q[x].pb(j);
            if(!(i%j))break;
        }
    }
    for(int T=read();T--;solve());
}