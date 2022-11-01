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
const int N=3010;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],num[N];
ll pre[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),y=read();
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        num[i]=num[i-1]+!a[i];
        pre[i]=pre[i-1]+a[i];
    }
    if(abs(pre[n])>1LL*num[n]*y)return cout<<"-1\n",0;
    ll ans=0;
    for(int j=1;j<=n;++j)for(int i=0;i<j;++i)
    {
        int x=num[j]-num[i];
        cmax(ans,pre[j]-pre[i]+min(1LL*x*y,1LL*(num[n]-x)*y-pre[n]));
        cmax(ans,pre[i]-pre[j]+min(1LL*x*y,1LL*(num[n]-x)*y+pre[n]));
    }
    cout<<ans+1<<'\n';
}