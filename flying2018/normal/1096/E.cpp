#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10010
#define M 110
#define mod 998244353
using namespace std;
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
void init(int n=N-10)
{
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int x,int y){return x<y || y<0?0:1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int B(int x,int y){return y<0?0:C(x+y-1,x-1);}
int F(int n,int m,int r)
{
    if(!n && !m) return 1;
    int ans=0,f=(n&1)?mod-1:1;
    for(int i=0;i<=n;i++,f=mod-f) ans=(ans+1ll*f*C(n,i)%mod*B(n,m-(r+1)*(n-i))%mod+mod)%mod;
    return ans;
}
int main()
{
    int p,s,r;
    scanf("%d%d%d",&p,&s,&r);
    init();
    int ans=0;
    for(int i=r;i<=s;i++)
        for(int j=0;(j+1)*i<=s && j<p;j++)
            ans=(ans+F(p-j-1,s-(j+1)*i,i-1)*1ll*C(p-1,j)%mod*ksm(j+1)%mod)%mod;
    ans=1ll*ans*ksm(B(p,s-r))%mod;
    printf("%d\n",ans);
    return 0;
}