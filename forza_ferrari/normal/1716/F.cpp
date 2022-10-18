#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int t,n,m,k,s[2001][2001],ans;
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
    s[1][1]=1;
    for(int i=2;i<=2000;++i)
        for(int j=1;j<=i;++j)
            s[i][j]=(1ll*j*s[i-1][j]%mod+s[i-1][j-1])%mod;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int x=(m+1)>>1,w=pw(m,n),inv=pw(m,mod-2);
        ans=0;
        for(int i=1;i<=k;++i)
        {
            w=1ll*w*x%mod*inv%mod*(n-i+1)%mod;
            ans=(ans+1ll*s[k][i]*w%mod)%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}