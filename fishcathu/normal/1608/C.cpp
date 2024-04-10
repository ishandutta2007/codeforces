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
const int N=1E5+10;
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
int a[N],b[N],c[N];
bool vis[N];
void solve()
{
    int n=read();
    for(int i=0;i<n;++i)a[i]=read(),b[i]=i;
    sort(b,b+n,[](int l,int r){return a[l]>a[r];});
    for(int i=0;i<n;++i)a[i]=read(),c[i]=i;
    sort(c,c+n,[](int l,int r){return a[l]>a[r];});
    string ans(n,'0');
    for(int i=0,s=0;1;++i)
    {
        ans[b[i]]='1';
        (vis[b[i]]^=1)?++s:--s;
        (vis[c[i]]^=1)?++s:--s;
        if(!s)break;
    }
    cout<<ans<<'\n';
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}