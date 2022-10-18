#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,m,fac[3000005],inv[3000005],val[3000005][2];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
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
const int inv3=pw(3,mod-2);
inline int c(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    n=read(),m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=3*n+3;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[3*n+3]=pw(fac[3*n+3],mod-2);
    for(int i=3*n+2;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    val[0][0]=val[0][1]=n+1;
    for(int i=1;i<=3*n;++i)
    {
        val[i][0]=1ll*((c(3*n+3,i+1)-2ll*val[i-1][0]%mod+mod)%mod-val[i-1][1]+mod)%mod*inv3%mod;
        val[i][1]=(val[i][0]+val[i-1][0])%mod;
    }
    while(m--)
        cout<<val[read()][0]<<'\n';
    return 0;
}