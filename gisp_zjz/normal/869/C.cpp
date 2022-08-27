#include<bits/stdc++.h>
#define maxn 5005
#define eps 1e-9
#define mod 998244353

using namespace std;
typedef long long ll;

ll n,a,b,c,ans,p[maxn],q[maxn],s,k;

ll pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tt=pow_(x,y/2);
    tt=tt*tt%mod;
    if (y%2) tt=tt*x%mod;
    return tt;
}

ll ck(ll x,ll y)
{
    k=min(x,y);
    ll tmp=0;
    for (int i=0;i<=k;i++)
    {
        s=p[x]*p[y]%mod;
        s=s*q[x-i]%mod;
        s=s*q[y-i]%mod;
        s=s*q[i]%mod;
        tmp=(tmp+s)%mod;
    }
    return tmp;
}

int main()
{
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    s=1;p[0]=1;
    for (int i=1;i<maxn;i++)
        p[i]=p[i-1]*i%mod;
    for (int i=0;i<maxn;i++)
        q[i]=pow_(p[i],mod-2);
    ans=ck(a,b);
    ans=ans*ck(a,c)%mod;
    ans=ans*ck(b,c)%mod;
    printf("%I64d\n",ans);
    return 0;
}