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
constexpr int N=1E5+10;
constexpr int inf=1E9;
constexpr int p=1E9+7;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int fac[N],inv[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=min(read(),n);
    fac[0]=1;
    for(int i=1;i<=n;++i)fac[i]=1LL*fac[i-1]*i%p;
    inv[n]=qpow(fac[n]);
    for(int i=n;i>=1;--i)inv[i-1]=1LL*inv[i]*i%p;
    int ans=0;
    for(int i=0;i<=m;++i)ans=(ans+1LL*inv[i]*inv[n-i])%p;
    ans=1LL*ans*fac[n]%p;
    cout<<ans<<'\n';
}