#include<bits/stdc++.h>
#define mod 998244353
#define MN 1000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int p[MN+5],inv[MN+5],n,tot,PP[MN+5];
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
inline int S(int x){return (x&1)?mod-1:1;}
inline int pw(int x,int k)
{
    int res=1;
    for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) res=1LL*res*x%mod;
    return res;
}
int Solve1()
{
    int ans=0,pp=PP[n];
    for(int i=n,j=1;i;--i,j=1LL*j*pp%mod)
        ans=(ans+1LL*PP[i]*S(i+1)%mod*C(n,i)%mod*j)%mod;
    return ans;
}
int Solve3()
{
    int ans=0,pp=PP[n];
    for(int i=n,j=1;i;--i,j=1LL*j*pp%mod)
        ans=(ans+3LL*S(i+1)%mod*C(n,i)%mod*j)%mod;
    return ans;
}
int Solve4()
{
    int ans=0;
    for(int i=n;i;--i)
        ans=(ans+3LL*S(i+1)%mod*C(n,i)%mod*pw(PP[n-i]-1,n))%mod;
    return ans; 
}
int main()
{
    n=read();p[0]=p[1]=inv[0]=inv[1]=PP[0]=1;PP[1]=3;
    for(int i=2;i<=n;++i) p[i]=1LL*i*p[i-1]%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=n;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod,PP[i]=3LL*PP[i-1]%mod;
    int a=Solve1(),c=Solve3(),d=Solve4();
    printf("%d\n",(2LL*a-c+d+mod)%mod);
    return 0;
}