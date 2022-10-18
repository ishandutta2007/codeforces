#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,x[51],y[51],mu[100001],f[100001],sum[100001],p[100001],cnt,ans;
bool prime[100001];
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
inline void init()
{
    mu[1]=prime[1]=1;
    for(register int i=2;i<=100000;++i)
    {
        if(!prime[i])
        {
            p[++cnt]=i;
            mu[i]=-1;
            f[i]=1;
        }
        for(register int j=1;j<=cnt,i*p[j]<=100000;++j)
        {
            int x=i*p[j];
            prime[x]=1;
            if(i%p[j]==0)
            {
                mu[x]=0;
                break;
            }
            else
                mu[x]=-mu[i];
        }
    }
}
signed main()
{
    init();
    n=read(),m=read();
    for(register int i=1;i<=n;++i)
        x[i]=read(),y[i]=read();
    for(register int d=1;d<=m;++d)
    {
        if(!mu[d])
            continue;
        for(register int i=0;i<=m/d;++i)
            sum[i]=1;
        for(register int i=1;i<=n;++i)
        {
            for(register int j=0;j<=m/d;++j)
                f[j]=0;
            int l=(x[i]+d-1)/d,r=y[i]/d;
            for(register int j=l;j<=m/d;++j)
                f[j]=(sum[j-l]-(j-r>0? sum[j-r-1]:0)+mod)%mod;
            sum[0]=0;
            for(register int j=1;j<=m/d;++j)
                sum[j]=(sum[j-1]+f[j])%mod;
        }
        ans=(ans+mu[d]*sum[m/d]%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}