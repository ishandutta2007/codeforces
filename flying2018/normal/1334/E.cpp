#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define int long long
#define N 18
#define mod 998244353
using namespace std;
int pr[N],t;
int fac[110],inv[110];
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
int a[N],at;
int work(ll w)
{
    memset(a,0,sizeof(a));
    at=0;int r=0;
    for(int i=1;i<=t;i++)
    if(w%pr[i]==0)
    {
        at++;
        while(w%pr[i]==0) w/=pr[i],a[at]++,r++;
    }
    r=fac[r];
    for(int i=1;i<=at;i++) r=1ll*r*inv[a[i]]%mod;
    return r;
}
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
signed main()
{
    ll D;
    scanf("%lld",&D);
    fac[0]=1;
    for(int i=1;i<=100;i++) fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=0;i<=100;i++) inv[i]=ksm(fac[i]);
    for(int i=2;1ll*i*i<=D;i++)
    if(D%i==0)
    {
        while(D%i==0) D/=i;
        pr[++t]=i;
    }
    if(D!=1) pr[++t]=D;
    int q;
    scanf("%lld",&q);
    for(int i=1;i<=q;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        ll g=gcd(u,v);
        printf("%lld\n",1ll*work(u/g)*work(v/g)%mod);
    }
    return 0;
}