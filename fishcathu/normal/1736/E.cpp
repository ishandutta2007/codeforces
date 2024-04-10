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
constexpr int N=510;
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

int a[N],f[N][N],g[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n+1;++i)
    {
        for(int k=0;k<=i;++k)
        {
            for(int j=max(i-k-1,0);j<i;++j)cmax(f[i][k],f[j][min(k-i+j+1,j)]+a[j]*(i-j));
            for(int j=i+i-k+1>>1;j<i;++j)cmax(f[i][k],g[j][min(k-i-i+j+j,j)]+a[i]*(i-j));
            for(int j=i+i-k>>1;j<i;++j)cmax(g[i][k],g[j][min(k-i-i+j+j+1,j)]+a[i]*(i-j));
            cmax(g[i][k],f[i][k]);
        }
    }
    cout<<f[n+1][n]<<'\n';
}