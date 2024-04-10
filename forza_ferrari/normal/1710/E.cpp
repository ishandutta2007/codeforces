#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[200001],b[200001],nodex[200001],nodey[200001],sumx[200001],sumy[200001],cntx,cnty;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int sum(int x,int y,bool cut)
{
    int res=0;
    if(nodex[x]<y)
    {
        if(cut)
        {
            if(cntx>x&&cnty>y)
                res=1;
            if(cntx<=x&&cnty<=y&&cnty<=nodex[cntx])
                res=1;
        }
        return nodey[y]*y+sumx[x]-sumx[nodey[y]]+(n-x)*(m-y)-res;
    }
    if(cut)
    {
        if(cntx<=x&&cnty<=y)
            res=1;
        if(cntx>x&&cnty>y&&cnty>nodex[cntx])
            res=1;
    }
    return x*y+((nodey[y]-x)*m-sumx[nodey[y]]+sumx[x])+(n-nodey[y])*(m-y)-res;
}
inline bool check(int x)
{
    nodex[0]=m;
    for(int i=1;i<=n;++i)
        for(nodex[i]=nodex[i-1];nodex[i]&&a[i]+b[nodex[i]]>x;--nodex[i]);
    for(int i=1;i<=n;i++)
        sumx[i]=sumx[i-1]+nodex[i];
    nodey[0]=n;
    for(int i=1;i<=m;++i)
        for(nodey[i]=nodey[i-1];nodey[i]&&a[nodey[i]]+b[i]>x;--nodey[i]);
    int l=max(sumx[n],n*m-sumx[n]),r=max(sumx[n]-(cnty<=nodex[cntx]),n*m-sumx[n]-(cnty>nodex[cntx])),p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m&&sum(i,p,0)<=sum(i,p+1,0))
            ++p;
        l=max(l,sum(i,p,0));
    }
    p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m&&sum(i,p,1)<=sum(i,p+1,1))
            ++p;
        r=max(r,sum(i,p,1));
    }
    return l!=r+1;
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<=m;++i)
        b[i]=read();
    cntx=a[1];
    cnty=b[1];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    cntx=lower_bound(a+1,a+n+1,cntx)-a;
    cnty=lower_bound(b+1,b+m+1,cnty)-b;
    int l=a[1]+b[1],r=a[cntx]+b[cnty],ans=a[cntx]+b[cnty];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}