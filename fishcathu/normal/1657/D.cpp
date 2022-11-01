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
const int N=1E6+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

ll f[N];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    while(n--)
    {
        int x=read();
        cmax(f[x],read<ll>()*read<ll>());
    }
    for(int i=1;i<=m;++i)
    {
        cmax(f[i],f[i-1]);
        for(int j=m/i;j>1;--j)cmax(f[i*j],f[i]*j);
    }
    for(int T=read();T--;)
    {
        int x=upper_bound(f+1,f+1+m,read<ll>()*read<ll>())-f;
        cout<<(x>m?-1:x)<<' ';
    }
}