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
constexpr int N=320;
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

int a[100010],F[2][32100010],*f=F[1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),mx=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        for(int j=min(i,N);--j;)
        {
            int x=a[i]-a[i-j];
            if(!(x%j))cmax(mx,++f[x/j]+1);
        }
        for(int j=min(i,N);--j;)
        {
            int x=a[i]-a[i-j];
            if(!(x%j))--f[x/j];
        }
    }
    for(int x=-N;x<=N;++x)
    {
        for(int i=1;i<=n;++i)cmax(mx,++f[a[i]+i*x]);
        for(int i=1;i<=n;++i)--f[a[i]+i*x];
    }
    cout<<n-mx<<'\n';
}