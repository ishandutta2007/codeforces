#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=998244353;
int t,a,b,n,fac[100001],inv[100001];
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
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=1e5;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[100000]=pw(fac[100000],mod-2);
    for(int i=99999;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        a=b=0;
        int len=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
                ++len;
            else
            {
                a+=len>>1;
                ++b;
                len=0;
            }
        }
        a+=len>>1;
        cout<<c(a+b,b)<<'\n';
    }
    return 0;
}