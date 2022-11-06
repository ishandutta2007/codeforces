#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define G 3
#define Gi ((mod+1)/G)
#define N 4000010
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
    while(lim<=n*2) lim<<=1,l++;
    for(int i=0;i<lim;i++)
    rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    return lim;
}
void ntt(int f[],int lim,int opt=1)
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
void mul(int f[],int g[],int n)
{
    int lim=get_rev(n);
    for(int i=n+1;i<=lim;i++) f[i]=g[i]=0;
    ntt(f,lim,1),ntt(g,lim,1);
    for(int i=0;i<lim;i++) f[i]=1ll*f[i]*g[i]%mod;
    ntt(f,lim,-1);
}
int f[N],g[N];
bool h[N],ans[N];
char s[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d%s",&n,s+1);
        for(int i=0;i<=n;i++) f[i]=g[i]=h[i]=0;
        for(int i=1;i<=n;++i)f[n-i+1]=(s[i]=='K'),g[i]=(s[i]=='V');
        mul(f,g,n);
        for(int i=1;i<n;++i) h[i]|=f[i+n+1];
        for(int i=1;i<=n;++i)f[n-i+1]=(s[i]=='V'),g[i]=(s[i]=='K');
        mul(f,g,n);
        for(int i=1;i<n;++i) h[i]|=f[i+n+1];
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            ans[i]=true;
            for(int j=i;j<=n && ans[i];j+=i) ans[i]&=!h[j];
            tot+=ans[i];
        }
        printf("%d\n",tot);
        for(int i=1;i<=n;i++)
        if(ans[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}