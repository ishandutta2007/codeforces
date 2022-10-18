#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
const int mod=1000000007;
int n,ans,sum[100001],p[100001];
string s;
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
    cin>>s;
    n=s.length();
    s=" "+s;
    for(register int i=1;i<=n;++i)
        sum[i]=(sum[i-1]*10+s[i]-'0')%mod;
    int cnt=0;
    for(register int i=n;i>=1;--i)
    {
        ans=(ans+sum[i]*cnt%mod)%mod;
        cnt=(cnt*10+1)%mod;
    }
    for(register int i=1;i<=n;++i)
        ans=(ans+(i*(i-1)/2+1)%mod*(s[i]-'0')%mod*pw(10,n-i)%mod)%mod;
    printf("%lld\n",(ans-sum[n]+mod)%mod);
    return 0;
}