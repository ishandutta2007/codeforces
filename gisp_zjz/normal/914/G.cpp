#include<bits/stdc++.h>
#define maxn 203040
#define mod 1000000007
#define rev 500000004

using namespace std;
typedef long long ll;

ll a[maxn],b[maxn],c[maxn],f[maxn],p[maxn],n,ans;

int lowbit(int x)
{
    return x&(-x);
}

void fwt(ll *a)
{
    for (int d=1;d<n;d<<=1)
        for (int m=d<<1,i=0;i<n;i+=m)
            for (int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod;
            }
}

void ifwt(ll *a)
{
    for (int d=1;d<n;d<<=1)
        for (int m=d<<1,i=0;i<n;i+=m)
            for (int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=(x-y+mod)%mod;
            }
}

int main()
{
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    for (int i=0;i<n;i++){int u;scanf("%d",&u);c[u]++;}
    n=1<<17;
    f[0]=0;f[1]=1;
    for (int i=2;i<n;i++) f[i]=(f[i-1]+f[i-2])%mod;
    for (int i=0;i<n;i++) a[i]=c[i],b[i]=c[i];
    for (int d=1;d<n;d<<=1)
        for (int m=d<<1,i=0;i<n;i+=m)
            for (int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
            }
    for (int i=0;i<n;i++) a[i]=a[i]*a[i]%mod;
    for (int d=1;d<n;d<<=1)
        for (int m=d<<1,i=0;i<n;i+=m)
            for (int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=1ll*(x+y)*rev%mod,a[i+j+d]=(1ll*(x-y)*rev%mod+mod)%mod;
            }
    memset(b,0,sizeof(b));
    for (int i=0;i<n;i++)
    {
        for (int j=i;j>=0;j=(j-1)&i)
        {
            b[i]+=c[j]*c[i-j];
            if (j==0) break;
        }
        b[i]%=mod;
    }
    for (int i=0;i<n;i++) a[i]=a[i]*f[i]%mod,b[i]=b[i]*f[i]%mod,c[i]=c[i]*f[i]%mod;
    fwt(a);fwt(b);fwt(c);
    for (int i=0;i<n;i++) a[i]=a[i]*b[i]%mod,a[i]=a[i]*c[i]%mod;
    ifwt(a);
    ans=0;
    for (int i=0;i<17;i++) ans=(ans+a[1<<i])%mod;
    printf("%d\n",ans);
    return 0;
}