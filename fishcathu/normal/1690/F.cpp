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
constexpr int N=210;
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

char a[N],q[N];
int nex[N],s;
bool vis[N];
bool check(int x)
{
    for(int i=0;i<s;++i)if(q[i]^q[(i+x)%s])return 0;
    return 1;
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i],vis[i]=0;
    for(int i=1;i<=n;++i)cin>>nex[i];
    ll ans=1;
    for(int i=1;i<=n;++i)if(!vis[i])
    {
        s=0;
        for(int j=i;!vis[j];j=nex[j])q[s++]=a[j],vis[j]=1;
        int j=1;
        while(!check(j))++j;
        ans=ans*j/__gcd(ans,ll(j));
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}