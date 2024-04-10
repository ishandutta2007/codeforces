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
constexpr int N=1E4+10,M=64;
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

using node=bitset<M>;
constexpr node o={1};
node init(int x)
{
    node y;
    y[0]=y[1<<x]=1;
    return y;
}
void operator*=(node &x,node y)
{
    node z=x|y;
    for(int i=0;i<M;++i)for(int j=i;--j&=i;z[i]=z[i]|x[j]&y[i^j]);
    x=z;
}
vector<int>to[N];
int dis[N],a[N],q[N];
node f[N];
bool b[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)to[i].clear(),dis[i]=inf,f[i]=o;
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    int s=0;
    dis[1]=0;
    q[++s]=1;
    for(int i=1;i<=s;++i)
    {
        int x=q[i];
        for(int t:to[x])if(cmin(dis[t],dis[x]+1))q[++s]=t;
    }
    int m=read();
    for(int i=1;i<=m;++i)cin>>a[i],b[i]=1;
    int z=read();
    for(int i=0;i<z;++i)
    {
        int x=read();
        f[a[x]]*=init(i);
        b[x]=0;
    }
    for(int i=1;i<=n;++i)
    {
        int x=q[i];
        node y=o;
        for(int t:to[x])if(dis[t]<dis[x])y|=f[t];
        f[x]*=y;
    }
    node y=o;
    for(int i=1;i<=m;++i)if(b[i])y*=f[a[i]];
    int mx=0;
    for(int i=0;i<M;++i)if(y[i])cmax(mx,__builtin_popcount(i));
    cout<<z-mx<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}