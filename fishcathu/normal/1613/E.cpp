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
int n,m;
char a[N];
void dfs(int i,int j,int k)
{
    int u,v,w,s=0;
    if(i>0&&a[k-m]=='.')u=i-1,v=j,w=k-m,++s;
    if(i<n-1&&a[k+m]=='.')u=i+1,v=j,w=k+m,++s;
    if(j>0&&a[k-1]=='.')u=i,v=j-1,w=k-1,++s;
    if(j<m-1&&a[k+1]=='.')u=i,v=j+1,w=k+1,++s;
    if(s>1)return;
    a[k]='+';
    if(s)dfs(u,v,w);
}
void solve()
{
    n=read(),m=read();
    int u,v,w;
    for(int i=0,k=0;i<n;++i)
    {
        for(int j=0;j<m;++j,++k)
        {
            a[k]=getchar();
            if(a[k]=='L')u=i,v=j,w=k;
        }
        getchar();
    }
    if(u>0&&a[w-m]=='.')dfs(u-1,v,w-m);
    if(u<n-1&&a[w+m]=='.')dfs(u+1,v,w+m);
    if(v>0&&a[w-1]=='.')dfs(u,v-1,w-1);
    if(v<m-1&&a[w+1]=='.')dfs(u,v+1,w+1);
    for(int i=0,k=0;i<n;++i)
    {
        for(int j=0;j<m;++j,++k)putchar(a[k]);
        putchar('\n');
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}