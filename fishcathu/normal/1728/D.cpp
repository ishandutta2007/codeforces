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
constexpr int N=2010;
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

char a[N];
int f[N][N];
int calc(int x,int y)
{
    if(x)return x;
    return y>0?1:y<0?-1:0;
}
void solve()
{
    int n=0;
    for(char x:read<string>())a[++n]=x;
    for(int j=1;j<=n;++j)
    {
        for(int i=j-1;i>0;i-=2)
        {
            f[i][j]=max(min(calc(f[i+1][j-1],a[j]-a[i]),calc(f[i+2][j],a[i+1]-a[i])),min(calc(f[i+1][j-1],a[i]-a[j]),calc(f[i][j-2],a[j-1]-a[j])));
        }
    }
    cout<<(f[1][n]>0?"Alice":f[1][n]<0?"Bob":"Draw")<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}