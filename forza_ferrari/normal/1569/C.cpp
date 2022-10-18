#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int t,n,a[200001],node[200001],p[200001],cnt,fac[200001],inv[200001],ans;
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    if(x<y)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    t=read();
    fac[0]=inv[0]=1;
    for(register int i=1;i<=200000;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[200000]=pw(fac[200000],mod-2);
    for(register int i=199999;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    while(t--)
    {
        n=read();
        for(register int i=1;i<=n;++i)
            node[i]=a[i]=read(),p[i]=0;
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(register int i=1;i<=n;++i)
            ++p[a[i]=lower_bound(node+1,node+cnt+1,a[i])-node];
        if(p[cnt]>1)
        {
            printf("%d\n",fac[n]);
            continue;
        }
        if(node[cnt]-node[cnt-1]>1)
        {
            puts("0");
            continue;
        }
        ans=fac[n];
        for(register int i=1;i<=n;++i)
            ans=(ans-1ll*c(i-1,p[cnt-1])*fac[n-1-p[cnt-1]]%mod*fac[p[cnt-1]]%mod+mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}