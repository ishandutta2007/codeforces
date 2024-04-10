#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001],b[100001];
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
inline bool check(int mid)
{
    int l=-1e9,r=1e9;
    for(int i=1;i<=n;++i)
    {
        if(b[i]>mid)
            return 0;
        l=max(l,a[i]-(mid-b[i]));
        r=min(r,a[i]+(mid-b[i]));
    }
    return l<=r;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read()<<1;
        for(int i=1;i<=n;++i)
            b[i]=read()<<1;
        int l=0,r=1e9,mid,ans=1e9;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        l=-1e9,r=1e9;
        for(int i=1;i<=n;++i)
        {
            l=max(l,a[i]-(ans-b[i]));
            r=min(r,a[i]+(ans-b[i]));
        }
        printf("%.10lf\n",l/2.0);
    }
    return 0;
}