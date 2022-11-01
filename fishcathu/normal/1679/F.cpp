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
constexpr int N=512;
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

int a[N],b[N],g[10],h[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        g[u]|=1<<v;
        h[v]|=1<<u;
    }
    a[0]=1;
    while(n--)
    {
        for(int i=0;i<N;++i)if(a[i])
        {
            for(int j=0;j<10;++j)if(~i>>j&1)
            {
                (b[i&g[j]|h[j]]+=a[i])%=p;
            }
        }
        memcpy(a,b,N<<2);
        memset(b,0,N<<2);
    }
    int ans=0;
    for(int i=0;i<N;++i)(ans+=a[i])%=p;
    cout<<ans<<'\n';
}