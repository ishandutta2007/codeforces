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
const int N=260;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

const int p=998244353;
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
int c[N][N],f[N][N];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read()-1,m=read();
    for(int i=0;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    }
    f[0][0]=1;
    for(int i=1;i<=m;++i)for(int j=0;j<=n;++j)for(int k=0;k<=j;++k)
    {
        f[i][j]=(f[i][j]+1LL*f[i-1][k]*c[n-k][j-k]%p*qpow(m+1-i,(j-k)*(j+k-1)/2))%p;
    }
    cout<<f[m][n]<<'\n';
}