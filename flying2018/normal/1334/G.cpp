#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 800010
#define mod 998244353
#define G 3
#define Gi ((mod+1)/G)
using namespace std;
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
int rev[N];
int get_rev(int n)
{
    int lim=1,l=0;
    while(lim<=n) lim<<=1,l++;
    for(int i=0;i<lim;i++)
    rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    return lim;
}
void ntt(int f[],int lim,int opt)
{
    for(int i=0;i<lim;i++)
    if(i<rev[i]) swap(f[i],f[rev[i]]);
    for(int mid=1;mid<lim;mid<<=1)
    {
        int r=ksm(opt==1?G:Gi,(mod-1)/(mid*2));
        for(int i=0;i<lim;i+=mid*2)
            for(int j=0,o=1;j<mid;j++,o=1ll*o*r%mod)
            {
                int a=f[i+j],b=1ll*f[i+j+mid]*o%mod;
                f[i+j]=(a+b)%mod;
                f[i+j+mid]=(a-b+mod)%mod;
            }
    }
    if(opt==-1)
    {
        int r=ksm(lim);
        for(int i=0;i<lim;i++) f[i]=1ll*f[i]*r%mod;
    }
}
int p[N],w[N];
char s[N],t[N];
int f[N],g[N],pre[N];
void mul(int *f,int *g,int n,int m)
{
    int lim=get_rev(n+m);
    ntt(f,lim,1),ntt(g,lim,1);
    for(int i=0;i<lim;i++) f[i]=1ll*f[i]*g[i]%mod;
    ntt(f,lim,-1);
}
int main()
{
    for(int i=1;i<=26;i++) scanf("%d",&p[i]);
    scanf("%s%s",s+1,t+1);
    int n=strlen(t+1),m=strlen(s+1);
    for(int i=1;i<=n;i++) t[i]-=96;
    for(int i=1;i<=m;i++) s[i]-=96;
    reverse(s+1,s+m+1);
    for(int i=1;i<=26;i++) w[i]=ksm(p[i],19260817);
    int res=0;
    for(int i=1;i<=n;i++) f[i]=w[t[i]],pre[i]=(pre[i-1]+1ll*f[i]*f[i])%mod;
    for(int i=1;i<=m;i++) g[i]=(w[s[i]]+w[p[s[i]]])%mod,res=(res+1ll*w[s[i]]*w[p[s[i]]])%mod;
    mul(f+1,g+1,n,m);
    for(int i=1;i<=n+m;i++) f[i]=mod-f[i];
    for(int i=m;i<=n;i++)
    {
        f[i]=((1ll*f[i]+pre[i]-pre[i-m]+mod)%mod+res)%mod;
        putchar('0'+!f[i]);
    }
    puts("");
    // for(int i=1;i<=n+m;i++) printf("%d ",f[i]);
    return 0;
}