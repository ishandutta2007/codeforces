#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1000001],sum[1000005<<1],maxn,minn;
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
int main()
{
    n=read(),m=read();
    minn=1e6+7;
    for(register int i=1;i<=n;++i)
    {
        a[i]=read();
        ++sum[a[i]];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    for(register int i=1;i<=maxn+m+1;++i)
        sum[i]+=sum[i-1];
    for(register int i=minn;i>m;--i)
    {
        int ans=0;
        for(register int j=i;j<=maxn;j+=i)
            ans+=sum[j+m]-sum[j-1];
        if(ans==n)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",min(m,minn));
    return 0;
}