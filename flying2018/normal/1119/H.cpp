#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define M 1<<17
#define mod 998244353
#define inv2 (mod+1)/2
using namespace std;
#define ll long long
int n,m;
void fwt(ll f[],int opt)
{
    for(int i=1;i<m;i<<=1)
        for(int j=0;j<m;j+=i<<1)
            for(int k=j;k<j+i;k++)
            {
                int x=f[k],y=f[i+k];
                f[k]=x+y;
                f[i+k]=x-y;
                if(opt==-1) f[k]=1ll*f[k]*inv2%mod,f[i+k]=1ll*f[i+k]*inv2%mod;
            }
}
ll f[M],f1[M],f2[M],f3[M];
ll ksm(ll a,ll b=mod-2)
{
    a=(a%mod+mod)%mod;
    ll r=1;
    for(;b;b>>=1)
    {
        if(b&1) r=1ll*r*a%mod;
        a=1ll*a*a%mod;
    }
    return r;
}
int main()
{
    ll x,y,z,all=0;
    scanf("%d%d%lld%lld%lld",&n,&m,&x,&y,&z);
    m=1<<m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        all^=a;
        f1[a^b]++; f2[a^c]++; f3[b^c]++;
    }
    fwt(f1,1),fwt(f2,1),fwt(f3,1);
    for(int i=0;i<m;i++)
    {
        ll c1=(n+f1[i]+f2[i]+f3[i])/4;
        ll c2=(n+f1[i])/2-c1,c3=(n+f2[i])/2-c1,c4=(n+f3[i])/2-c1;
        f[i]=1ll*ksm(x+y+z,c1)*ksm(x+y-z,c2)%mod*ksm(x-y+z,c3)%mod*ksm(x-y-z,c4)%mod;
    }
    fwt(f,-1);
    for(int i=0;i<m;i++)
    printf("%lld ",(f[i^all]%mod+mod)%mod);
    return 0;
}