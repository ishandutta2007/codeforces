#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1<<20|1],b[1<<20|1],node[1<<20|1],qwq;
long long ans[21][2],cnt[1<<20|1][2];
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
inline void qsort(int l,int r,int dep)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    qsort(l,mid,dep-1);
    qsort(mid+1,r,dep-1);
    int i=l,j=mid+1,p=l-1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
        {
            ++cnt[a[i]][0];
            ans[dep][0]+=r-j+1;
            b[++p]=a[i++];
        }
        else
        {
            ++cnt[a[j]][1];
            ans[dep][1]+=mid-i+1;
            b[++p]=a[j++];
        }
    }
    while(i<=mid)
    {
        ++cnt[a[i]][0];
        b[++p]=a[i++];
    }
    while(j<=r)
    {
        ++cnt[a[j]][1];
        b[++p]=a[j++];
    }
    for(int i=l;i<=r;++i)
    {
        a[i]=b[i];
        ans[dep][1]-=1ll*cnt[a[i]][0]*cnt[a[i]][1];
        cnt[a[i]][0]=cnt[a[i]][1]=0;
    }
}
int main()
{
    n=read();
    for(int i=1;i<=1<<n;++i)
        node[i]=a[i]=read();
    sort(node+1,node+(1<<n)+1);
    qwq=unique(node+1,node+(1<<n)+1)-node-1;
    for(int i=1;i<=1<<n;++i)
        a[i]=lower_bound(node+1,node+qwq+1,a[i])-node;
    qsort(1,1<<n,n);
    m=read();;
    while(m--)
    {
        int x=read();
        long long res=0;
        for(int i=1;i<=x;++i)
        {
            ans[i][0]^=ans[i][1]^=ans[i][0]^=ans[i][1];
            res+=ans[i][1];
        }
        for(int i=x+1;i<=n;++i)
            res+=ans[i][1];
        cout<<res<<'\n';
    }
    return 0;
}