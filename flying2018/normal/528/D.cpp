#include<iostream>
#include<cstdio>
#include<cstring>
#define N 800010
#define mod 998244353
#define G 3
#define Gi ((mod+1)/G)
using namespace std;
int rev[N];
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
int get_rev(int n)
{
    int l=0,lim=1;
    while(lim<=n) lim<<=1,l++;
    for(int i=1;i<lim;i++)
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
                int x=f[i+j],y=1ll*f[i+j+mid]*o%mod;
                f[i+j]=(x+y)%mod;
                f[i+j+mid]=(x-y+mod)%mod;
            }
    }
    if(opt==-1)
    {
        int r=ksm(lim);
        for(int i=0;i<lim;i++) f[i]=1ll*f[i]*r%mod;
    }
}
char s[N],t[N];
int n,m;
int res[N],lim,f[N],g[N],k;
void work(char c)
{
    for(int i=0;i<lim;i++) f[i]=g[i]=0;
    int pre=-lim;
    for(int i=0;i<n;i++)
    {
        if(s[i]==c) pre=i;
        if(i-pre<=k) f[i]=1;
    }
    pre=lim;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==c) pre=i;
        if(pre-i<=k) f[i]=1;
    }
    for(int i=0;i<m;i++)
    if(t[i]==c) g[m-i-1]=1;
    ntt(f,lim,1),ntt(g,lim,1);
    for(int i=0;i<lim;i++) f[i]=1ll*f[i]*g[i]%mod;
    ntt(f,lim,-1);
    for(int i=0;i<n;i++) res[i]+=f[i];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",s,t);
    lim=get_rev(n+m);
    work('A'),work('C'),work('G'),work('T');
    int ans=0;
    for(int i=0;i<n;i++)
    if(res[i]==m) ans++;
    printf("%d\n",ans);
    return 0;
}