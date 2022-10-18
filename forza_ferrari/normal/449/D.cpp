#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,sum[1<<21],ans;
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
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        ++sum[read()];
    for(int i=0;i<20;++i)
        for(int s=0;s<1<<20;++s)
            if(s>>i&1^1)
                sum[s]+=sum[s|(1<<i)];
    for(int s=0;s<1<<20;++s)
        ans=(ans+1ll*(__builtin_parity(s)? mod-1:1)*pw(2,sum[s])%mod)%mod;
    cout<<ans<<'\n';
    return 0;
}