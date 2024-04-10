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
bool solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n>4)
    {
        sort(a+1,a+1+n);
        return !a[2]&&!a[n-1]&&(a[1]==-a[n]||!a[1]||!a[n]);
    }
    for(int i=3;i<=n;++i)for(int j=2;j<i;++j)for(int k=1;k<j;++k)
    {
        ll x=0LL+a[i]+a[j]+a[k];
        bool b=0;
        for(int u=1;u<=n;++u)b|=x==a[u];
        if(!b)return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;cout<<(solve()?"YES":"NO")<<'\n');
}