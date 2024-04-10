#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define mod 998244353
using namespace std;
char s[N];
int f[N];
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
int C(int a,int b){return a<b?0:1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;}
void init(int n=N-10)
{
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int calc(int a,int b){return C(a+b,a);}
int main()
{
    init();
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d%s",&n,s+1);
        int tt=0,res=0;
        for(int i=1;i<=n;)
        {
            while(i<=n && s[i]=='0') i++,tt++;
            int w=0;
            while(i<=n && s[i]=='1') i++,w++;
            res+=w/2;
        }
        printf("%d\n",calc(tt,res));
    }
    return 0;
}