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
constexpr int N=1010;
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

ll f[N][N];
void solve()
{
    int n=read(),m=read();
    memset(f,0,sizeof f);
    while(n--)
    {
        int a=read(),b=read();
        f[a][b]+=a*b;
    }
    for(int i=1;i<N;++i)for(int j=1;j<N;++j)f[i][j]+=f[i][j-1]+f[i-1][j]-f[i-1][j-1];
    while(m--)
    {
        int a=read(),b=read(),c=read()-1,d=read()-1;
        cout<<f[c][d]-f[c][b]-f[a][d]+f[a][b]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}