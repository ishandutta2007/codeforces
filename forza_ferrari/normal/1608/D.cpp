#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;//////
int n,fac[1000001],inv[1000001],a,b,c,k,ans;
string s[100001];
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
inline int C(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
    cin>>n;
    fac[0]=inv[0]=1;
    for(int i=1;i<=1000000;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[1000000]=pw(fac[1000000],mod-2);
    for(int i=999999;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        if(s[i]=="?W"||s[i]=="W?")
            ++a;
        if(s[i]=="?B"||s[i]=="B?")
            ++b;
        if(s[i]=="??")
            ++c;
        if(s[i]=="BB")
            ++k;
        if(s[i]=="WW")
            --k;
    }
    ans=C(a+b+c+c,k+b+c);
    int sum=1;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=="WW"||s[i]=="BB")
        {
            sum=0;
            break;
        }
        if(s[i]=="??")
            sum=2ll*sum%mod;
    }
    ans=(ans-sum+mod)%mod;
    sum=1;
    for(int i=1;i<=n;++i)
        if(s[i]=="WW"||s[i]=="BB"||s[i]=="W?"||s[i]=="?B"||s[i]=="WB")
        {
            sum=0;
            break;
        }
    ans=(ans+sum)%mod;
    sum=1;
    for(int i=1;i<=n;++i)
        if(s[i]=="WW"||s[i]=="BB"||s[i]=="?W"||s[i]=="B?"||s[i]=="BW")
        {
            sum=0;
            break;
        }
    ans=(ans+sum)%mod;
    cout<<ans<<endl;
    return 0;
}