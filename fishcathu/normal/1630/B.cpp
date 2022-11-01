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
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],b[N];
void solve()
{
    int n=read(),m=read(),y=n+m+1>>1;
    for(int i=1;i<=n;++i)b[i]=0;
    for(int i=1;i<=n;++i)++b[a[i]=read()];
    int l=1,r=n;
    for(int i=1,j=0,s=0;;s-=b[i++])
    {
        while(s<y&&j<=n)s+=b[++j];
        if(j>n)break;
        if(j-i<r-l)l=i,r=j;
    }
    cout<<l<<' '<<r<<'\n';
    int u=1;
    for(int i=1;m--;)
    {
        cout<<i<<' ';
        for(int s=0;(s<1||!m)&&i<=n;++i)a[i]>=l&&a[i]<=r?++s:--s;
        cout<<i-1<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}