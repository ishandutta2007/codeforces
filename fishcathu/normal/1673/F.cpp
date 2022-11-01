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
const int N=2E5+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<n;++j)cout<<(1<<__lg(j&-j)*2)<<' ';
        cout<<endl;
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=n;++j)cout<<(1<<__lg(i&-i)*2+1)<<' ';
        cout<<endl;
    }
    for(int u=0,v=0;m--;)
    {
        int x=read();
        for(int i=0;i<5;++i)
        {
            if(x>>i*2+1&1)u^=(1<<i+1)-1;
            if(x>>i*2&1)v^=(1<<i+1)-1;
        }
        cout<<u+1<<' '<<v+1<<endl;
    }
}