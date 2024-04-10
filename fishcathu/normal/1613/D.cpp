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
const int N=5E5+10;
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
const int p=998244353;
int f[N]={1},g[N];
void solve()
{
    int n=read()+1;
    for(int i=n;--i;)
    {
        int x=read()+1;
        f[x]=(f[x]*2%p+f[x-1])%p;
        g[x]=(g[x]*2%p+f[x-2])%p;
        g[x+2]=g[x+2]*2%p;
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans=((ans+f[i])%p+g[i])%p,f[i]=g[i]=0;
    cout<<ans<<'\n';
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}