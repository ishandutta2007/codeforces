#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define mod 998244353
using namespace std;
int val[N],n;
void add(int x,int v){for(;x;x-=(x&(-x))) val[x]+=v;}
int qry(int x){int ans=0;for(;x<=n;x+=(x&(-x))) ans+=val[x];return ans;}
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
int a[N];
int sum[N];
int main()
{
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<=n;i++) sum[i]=1;
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]!=-1) sum[a[i]]=0;}
    for(int i=n;i;i--) sum[i]+=sum[i+1];
    int p=sum[1];
    for(int i=1;i<=n;i++)
    if(a[i]!=-1) res=(res+qry(a[i]))%mod,add(a[i],1);
    int s=0,rp=ksm(p);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1) s++;
        else
        {
            int v1=sum[a[i]],v2=p-v1,s2=p-s;
            res=(res+1ll*v1*s%mod*rp%mod+1ll*v2*s2%mod*rp%mod)%mod;
        }
    }
    res=(res+1ll*p*(p-1)%mod*ksm(4)%mod)%mod;
    printf("%d\n",res);
    return 0;
}