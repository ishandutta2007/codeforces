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
constexpr int N=9E6+10;
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

int nex[N][2],f[N][2],cnt;
void solve()
{
    int n=read(),ans=0;
    for(int i=0;i<n;++i)
    {
        int x=read()^i,mx=0;
        for(int u=0,j=30;j--;)
        {
            int k=x>>j&1;
            cmax(mx,f[nex[u][k^1]][~i>>j&1^k]);
            if(!nex[u][k])nex[u][k]=++cnt;
            u=nex[u][k];
        }
        cmax(ans,++mx);
        for(int u=0,j=30;j--;cmax(f[u=nex[u][x>>j&1]][i>>j&1],mx));
    }
    cout<<ans<<'\n';
    for(int i=0;i<=cnt;++i)nex[i][0]=nex[i][1]=f[i][0]=f[i][1]=0;
    cnt=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}