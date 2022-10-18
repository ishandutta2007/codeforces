#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=1000000007;
int t,n,fac[10001],inv[10001],ans,sum;
string s;
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
inline int c(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    cin>>t;
    fac[0]=inv[0]=1;
    for(int i=1;i<=10000;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[10000]=pw(fac[10000],mod-2);
    for(int i=9999;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    while(t--)
    {
        cin>>s;
        n=s.length();
        sum=0;
        ans=0;
        for(int i=0;i<n;++i)
            sum+=s[i]-'a'+1;
        for(int i=0;i<=n;++i)
            ans=(ans+1ll*(i&1? mod-1:1)*c(n,i)%mod*c(sum-26*i-1,n-1)%mod)%mod;
        cout<<(ans+mod-1)%mod<<'\n';
    }
    return 0;
}