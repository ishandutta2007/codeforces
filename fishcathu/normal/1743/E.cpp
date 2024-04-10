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
constexpr int N=5010;
constexpr ll inf=1LL<<60;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int x,y,z,n;
ll f[N],u,v;
void calc(ll x,ll y)
{
    for(int i=1;i<=n;++i)
    {
        cmin(f[i],f[max(i-x,0)]+y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>x>>u>>y>>v>>n>>z;
    for(int i=1;i<=n;++i)f[i]=inf;
    calc(x-z,u);
    calc(y-z,v);
    for(int i=1;i<=n;++i)
    {
        ll t=u*i/v;
        if(t)calc((i-1)*(x-z)+(t-1)*(y-z)+x+y-z,u*i);
        t=v*i/u;
        if(t)calc((i-1)*(y-z)+(t-1)*(x-z)+x+y-z,v*i);
    }
    cout<<f[n]<<'\n';
}