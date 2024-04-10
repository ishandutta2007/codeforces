#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;
int n,q,fac[61],inv[61],p[61],cnt;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
inline int calc(int x)
{
    int res=1,sum=0,tmp=0;
    for(int i=1;i<=cnt;++i)
        if(x%p[i]==0)
        {
            tmp=0;
            while(x%p[i]==0)
            {
                ++tmp;
                ++sum;
                x/=p[i];
            }
            res=1ll*res*inv[tmp]%mod;
        }
    return 1ll*res*fac[sum]%mod;
}
signed main()
{
    cin>>n>>q;
    for(int i=2;i*i<=n;++i)
        if(n%i==0)
        {
            p[++cnt]=i;
            while(n%i==0)
                n/=i;
        }
    if(n^1)
        p[++cnt]=n;
    fac[0]=1;
    for(int i=1;i<=60;++i)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=pw(fac[i],mod-2);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<1ll*calc(x/gcd(x,y))*calc(y/gcd(x,y))%mod<<endl;
    }
    return 0;
}