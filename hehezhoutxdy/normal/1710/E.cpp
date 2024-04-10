// Problem: E. Two Arrays
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int n=read(),m=read();
int a[200003],b[200003];
int pa[200003],pb[200003],pre[200003];
int tx,ty;
int sum(int x,int y,bool cut)
{
    if(pa[x]<y)
     return 1ll*pb[y]*y+pre[x]-pre[pb[y]]+1ll*(n-x)*(m-y)-
    (cut&&((tx>x&&ty>y)||(tx<=x&&ty<=y&&ty<=pa[tx])));
    return 1ll*x*y+(1ll*(pb[y]-x)*m-pre[pb[y]]+pre[x])
    +1ll*(n-pb[y])*(m-y)-
    (cut&&((tx<=x&&ty<=y)||(tx>x&&ty>y&&ty>pa[tx])));
}
bool check(int x)
{
    for(int i=1; i<=n; ++i)
    {
    	pa[i]=pa[i-1];
        while(pa[i]&&a[i]+b[pa[i]]>x) --pa[i];
        pre[i]=pre[i-1]+pa[i];
    }
    for(int i=1; i<=m; ++i)
    {
    	pb[i]=pb[i-1];
        while(pb[i]&&a[pb[i]]+b[i]>x) --pb[i];
    }
    int a0=max(pre[n],1ll*n*m-pre[n]);
    int a1=max(pre[n]-(ty<=pa[tx]),1ll*n*m-pre[n]-(ty>pa[tx]));
    for(int i=1,pos=1; i<=n; ++i)
    {
        while(pos<m&&sum(i,pos,0)<=sum(i,pos+1,0)) ++pos;
        a0=max(a0,sum(i,pos,0));
    }
    for(int i=1,pos=1; i<=n; ++i)
    {
        while(pos<m&&sum(i,pos,1)<=sum(i,pos+1,1)) ++pos;
        a1=max(a1,sum(i,pos,1));
    }
    return a0!=a1+1;
}
signed main()
{
    for(int i=1; i<=n; ++i) a[i]=read();
    for(int i=1; i<=m; ++i) b[i]=read();
    int A=a[1],B=b[1];
    sort(a+1,a+n+1),sort(b+1,b+m+1),pa[0]=m,pb[0]=n;
    tx=lower_bound(a+1,a+n+1,A)-a,ty=lower_bound(b+1,b+m+1,B)-b;
    int l=a[1]+b[1],r=a[tx]+b[ty]-1,res=a[tx]+b[ty];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%lld\n",res);
    return 0;
}