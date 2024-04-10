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

int a[N],f[9],g[9];
void solve()
{
    int n=0;
    for(char x:read<string>())a[++n]=x^48,a[n]+=a[n-1];
    for(int i=0;i<9;++i)f[i]=g[i]=0;
    for(int x=read()-1,i=n-x;i>=1;--i)
    {
        int j=(a[i+x]-a[i-1])%9;
        g[j]=f[j];
        f[j]=i;
    }
    for(int m=read();m--;)
    {
        int l=read(),r=read(),k=read(),x=9-(a[r]-a[l-1])%9,u=inf,v;
        for(int i=0;i<9;++i)if(f[i])
        {
            int j=(i*x+k)%9,t=j^i?f[j]:g[j];
            if(t&&(f[i]<u||f[i]==u&&t<v))u=f[i],v=t;
        }
        if(u^inf)cout<<u<<' '<<v<<'\n';
        else cout<<"-1 -1\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}