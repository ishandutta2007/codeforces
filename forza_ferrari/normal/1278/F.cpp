#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,k,s[5001][5001],inv,val,ans;
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
    cin>>n>>m>>k;
    inv=pw(m,mod-2),val=pw(m,n);
    s[1][1]=1;
    for(int i=2;i<=k;++i)
        for(int j=1;j<=i;++j)
            s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j]%mod)%mod;
    for(int i=1;i<=k;++i)
    {
        val=1ll*val*inv%mod*(n-i+1)%mod;
        ans=(ans+1ll*s[k][i]*val%mod)%mod;
    }
    cout<<1ll*ans*pw(pw(m,n),mod-2)%mod<<'\n';
    return 0;
}