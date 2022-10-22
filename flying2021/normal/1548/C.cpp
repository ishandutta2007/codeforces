#include<iostream>
#include<cstdio>
#include<cstring>
#define N 4000010
#define mod 1000000007
using namespace std;
int fac[N],inv[N],iv[N];
int ksm(int a,int b=mod-2)
{
    int r=1;
    for(;b;b>>=1)
    {
        if(b&1) r=1ll*r*a%mod;
        a=1ll*a*a%mod;
    }
    return r;
}
int C(int a,int b){return a<b?0:1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;}
void init(int n=N-10)
{
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    iv[1]=1;
    for(int i=2;i<=n;i++) iv[i]=1ll*(mod-mod/i)*iv[mod%i]%mod;
}
int n,f[N][3];
int calc(int x){return 1ll*fac[n*3+1]*inv[3*n-x]%mod*iv[x+1]%mod;}
int calc2(int x){return (2ll*x*f[x-1][0]%mod+1ll*x*f[x-1][1])%mod;}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<3;i++) f[1][i]=(1ll*(3*n-1)*n/2+1ll*i*n)%mod;
    for(int i=2;i<=3*n;i++)
    {
        f[i][0]=(calc(i)-calc2(i)+mod)%mod;
        f[i][0]=1ll*f[i][0]*iv[3]%mod;
        for(int j=1;j<3;j++) f[i][j]=(f[i][j-1]+1ll*i*f[i-1][j-1])%mod;
    }
    for(int i=1;i<=3*n;i++)
        for(int j=0;j<3;j++) f[i][j]=1ll*f[i][j]*inv[i]%mod;
    for(int i=1,x;i<=m;i++) scanf("%d",&x),printf("%d\n",f[x][2]);
    return 0;
}