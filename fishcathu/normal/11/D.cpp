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
constexpr int N=19;
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

ll f[1<<N][N];
vector<int>to[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read(),s=1<<n;
    for(int i=m;i--;)
    {
        int u=read()-1,v=read()-1;
        to[u].pb(v);
        to[v].pb(u);
    }
    for(int i=0;i<n;++i)f[1<<i][i]=1;
    ll ans=0;
    for(int k=1;k<s;++k)
    {
        int x=__builtin_ctz(k);
        for(int i=0;i<n;++i)if(f[k][i])
        {
            for(int j:to[i])
            {
                if(j==x)ans+=f[k][i];
                else if(j>x&&~k>>j&1)f[k|1<<j][j]+=f[k][i];
            }
        }
    }
    (ans-=m)>>=1;
    cout<<ans<<'\n';
}