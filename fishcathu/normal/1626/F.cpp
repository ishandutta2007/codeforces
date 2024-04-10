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
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
const int N=720720;
const int inf=1<<30;
const int p=998244353;
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
int a[N],n,m,ans;
void init()
{
    int x,b,c,y;
    cin>>n>>x>>b>>c>>m>>y;
    for(int i=1;i<=n;++i)
    {
        ++a[x%N];
        ans=(ans+x/N*N)%p;
        x=(1LL*b*x+c)%y;
    }
    ans=1LL*ans*qpow(n,m-1)*m%p;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    init();
    for(int j=1;j<=m;++j)
    {
        int s=0;
        for(int i=1;i<N;++i)
        {
            int x=a[i];
            if(!x)continue;
            a[i]=x*(n-1LL)%p;
            a[i/j*j]=(a[i/j*j]+x)%p;
            s=(s+1LL*i*x)%p;
        }
        ans=(ans+1LL*s*qpow(n,m-j))%p;
    }
    cout<<ans<<'\n';
}