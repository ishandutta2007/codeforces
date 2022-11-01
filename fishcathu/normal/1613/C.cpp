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
const int N=110;
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
int a[N],n;
ll s;
bool check(ll x)
{
    ll ans=x;
    for(int i=1;i<n;++i)ans+=min(a[i+1]-a[i],x);
    return ans>=s;
}
void solve()
{
    n=read();
    s=read<ll>();
    for(int i=1;i<=n;++i)a[i]=read();
    ll l=1,r=s;
    while(l^r)
    {
        ll m=l+r>>1;
        check(m)?r=m:l=m+1;
    }
    cout<<l<<endl;
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}