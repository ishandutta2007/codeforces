#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 410
using namespace std;
int mod;
int fac[N],inv[N];
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
int _2[N];
int C(int a,int b){return a<b?0:1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;}
void init(int n=N-9)
{
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=_2[0]=1;i<=n;i++) _2[i]=2ll*_2[i-1]%mod;
}
int f[N][N];
int main()
{
    int n,ans=0;
    scanf("%d%d",&n,&mod);
    init();
    for(int i=1;i<=n;i++) f[i][1]=_2[i-1];
    for(int i=3;i<=n;i++)
        for(int j=2;j*2<=i+1;j++)
            for(int k=1;k<=i-2;k++) f[i][j]=(f[i][j]+1ll*f[k][j-1]*_2[i-k-2]%mod*C(i-j+1,i-k-1)%mod)%mod;
    for(int i=1;i*2<=n+1;i++) ans=(ans+f[n][i])%mod;
    printf("%d\n",ans);
    return 0;
}