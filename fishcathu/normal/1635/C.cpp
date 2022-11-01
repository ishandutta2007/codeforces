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
const int N=2E5+10;
const int inf=1<<30;
int a[N];
void solve()
{
    int n=read();
    bool b=1;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b&=a[i]>=a[i-1];
    }
    if(b)return cout<<"0\n",void();
    if(a[n]<a[n-1]||a[n]<0)return cout<<"-1\n",void();
    cout<<n-2<<'\n';
    for(int i=n-2;i>=1;--i)cout<<i<<' '<<n-1<<' '<<n<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    a[0]=-inf;
    for(int T=read();T--;solve());
}