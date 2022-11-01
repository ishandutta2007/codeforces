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
constexpr int N=410;
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

int a[N][N],f[N];
void solve()
{
    int n=read(),m=read(),ans=inf;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=a[i][j-1]+read<char>()-48;
    for(int k=4;k<=m;++k)for(int j=k-3;j>=1;--j)for(int i=1,s=0;i<=n;++i)
    {
        int x=k-j-1-a[i][k-1]+a[i][j];
        if(i>4)cmin(ans,x+s+f[i-4]);
        s+=a[i][k-1]-a[i][j]+(a[i][j]==a[i][j-1])+(a[i][k]==a[i][k-1]);
        f[i]=min(f[i-1],x-s);
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    f[0]=inf;
    for(int T=read();T--;solve());
}