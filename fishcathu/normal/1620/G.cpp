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
constexpr int N=1<<23;
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

int a[N][26],f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),s=1<<n;
    for(int i=1;i<s;++i)
    {
        int j=i&-i,k=i^j;
        if(k)for(int u=26;u--;a[i][u]=min(a[j][u],a[k][u]));
        else for(char x:read<string>())++a[i][x-97];
        f[i]=p-1;
        for(int u=26;u--;f[i]=f[i]*(a[i][u]+1LL)%p);
    }
    for(int k=1;k<s;k<<=1)for(int i=0;i<s;)
    {
        if(i&k)f[i]=(f[i^k]-f[i]+p)%p,++i;
        else i+=k;
    }
    ll ans=0;
    for(int i=1;i<s;++i)
    {
        int x=0,y=0;
        for(int k=0;k<n;++k)if(i>>k&1)x+=k+1,++y;
        ans^=1LL*f[i]*x*y;
    }
    cout<<ans<<'\n';
}