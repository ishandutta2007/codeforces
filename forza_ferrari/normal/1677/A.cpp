#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[5001],sum[2][5001];
long long ans;
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int tag)
{
    for(;x<=n;x+=lowbit(x))
        ++sum[tag][x];
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[tag][x];
    return res;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        for(int i=1;i<=n;++i)
            sum[0][i]=0;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                sum[1][j]=0;
            for(int j=n;j>i;--j)
            {
                ans+=1ll*query(a[j]-1,0)*query(a[i]-1,1);
                update(a[j],1);
            }
            update(a[i],0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}