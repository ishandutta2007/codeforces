#include<bits/stdc++.h>
#define MN 2000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,d[MN+5],a[MN+5][MN+5],mn=1e9;bool b[MN+5];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) d[i]=2e9;
    for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j)
        mn=min(mn,a[i][j]=a[j][i]=read());
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i!=j)
        a[i][j]-=mn,d[i]=min(d[i],a[i][j]<<1);
    for(int i=1;i<=n;++i)
    {
        int m=2e9+1,from=0;
        for(int j=1;j<=n;++j) if(!b[j]&&d[j]<m) m=d[j],from=j;
        b[from]=1;
        for(int j=1;j<=n;++j) if(!b[j]) d[j]=min(d[j],d[from]+a[from][j]);
    }
    for(int i=1;i<=n;++i) printf("%I64d\n",d[i]+1LL*(n-1)*mn);
    return 0;
}