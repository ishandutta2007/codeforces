#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,fac[1000001];
const int mod=1000000007;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
signed main()
{
    scanf("%lld",&n);
    fac[0]=1;
    for(register int i=1;i<=n;++i)
        fac[i]=fac[i-1]*i%mod;
    printf("%lld\n",(fac[n]-pw(2,n-1)+mod)%mod);
    return 0;
}