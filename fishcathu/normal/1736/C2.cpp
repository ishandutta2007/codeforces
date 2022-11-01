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

int a[N],f[N],g[N];
ll u[N],v[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read()-i;
        if(a[i]<f[i-1])g[i]=f[i-1],f[i]=a[i];
        else g[i]=min(g[i-1],a[i]),f[i]=f[i-1];
        u[i]=u[i-1]+f[i];
        v[i]=v[i-1]+g[i];
    }
    ll res=u[n]+n*(n+1LL)/2;
    for(int m=read();m--;)
    {
        ll ans=res;
        int i=read(),x=read()-i;
        if(x<a[i])
        {
            int j=upper_bound(f+i,f+1+n,x,greater<int>())-f-1;
            ans-=u[j]-u[i-1]-x*(j-i+1LL);
        }
        else
        {
            int j=upper_bound(f+i,f+1+n,a[i],greater<int>())-f-1;
            int k=upper_bound(g+i,g+1+j,x,greater<int>())-g-1;
            ans+=v[j]-v[k]-u[j]+u[i-1]+x*(k-i+1LL);
        }
        cout<<ans<<'\n';
    }
}