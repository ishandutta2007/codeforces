#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int t,n,a[3001],sum[3001][3001],ans;
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
signed main()
{
    t=read();
    while(t--)
    {
        memset(sum,0,sizeof sum);
        ans=0;
        n=read();
        for(register int i=1;i<=n;++i)
            a[i]=read();
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                sum[i][j]+=(a[i]==a[j]);
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        for(register int i=1;i<n;++i)
            for(register int j=i+1;j<=n;++j)
                if(a[i]==a[j])
                    ans+=sum[j-1][n]-sum[i][n]-sum[j-1][j]+sum[i][j];
        printf("%lld\n",ans);
    }
    return 0;
}