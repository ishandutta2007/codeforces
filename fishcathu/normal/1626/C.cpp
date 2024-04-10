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
const int N=1E4+10;
const int inf=1<<30;
int a[N],b[N],c[N],s;
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    s=0;
    for(int i=1;i<=n;++i)
    {
        int x=a[i]-read();
        while(b[s]>x)--s;
        if(x>=c[s])b[++s]=x;
        c[s]=a[i];
    }
    ll ans=0;
    for(int i=1;i<=s;++i)
    {
        int x=c[i]-b[i];
        ans+=x*(x+1LL)>>1;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}