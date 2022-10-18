#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int base=1145141,mod=998244353;
int n,p[5001],inv[5001],pre[5005],suf[5005];
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
int main()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    bool flag=1;
    for(int i=1;i<=n;++i)
        if((s[1]^s[i])&&(n%2==0||i!=(n+1)/2))
        {
            flag=0;
            break;
        }
    if(flag)
    {
        puts("Impossible");
        return 0;
    }
    p[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
        p[i]=1ll*p[i-1]*base%mod;
    inv[n]=pw(p[n],mod-2);
    for(int i=n-1;i;--i)
        inv[i]=1ll*inv[i+1]*base%mod;
    for(int i=1;i<=n;++i)
    {
        pre[i]=(pre[i-1]+1ll*(s[i]-'a'+1)*p[i]%mod)%mod;
        suf[n-i+1]=(suf[n-i+2]+1ll*(s[n-i+1]-'a'+1)*p[i]%mod)%mod;
    }
    for(int i=1;i<n;++i)
    {
        int val=(1ll*(pre[n]-pre[i]+mod)%mod*inv[i]%mod+1ll*pre[i]*p[n-i]%mod)%mod;
        if(val==pre[n])
            continue;
        int tmp=(1ll*(suf[1]-suf[i+1]+mod)%mod*inv[n-i]%mod+1ll*suf[i+1]*p[i]%mod)%mod;
        if(val==tmp)
        {
            puts("1");
            return 0;
        }
    }
    puts("2");
    return 0;
}