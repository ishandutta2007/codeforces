#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define int long long
const int mod=1e9+7,lim=1e6;
int n,m,a[500001],ans,cnt,sum[1000001],fac[1000001],d[2000005];
priority_queue<pair<int,int> > q;
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
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
signed main()
{
    m=read();
    fac[0]=1;
    for(int i=1;i<=lim;++i)
        fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<=m;++i)
    {
        a[i]=read();
        ++sum[a[i]];
    }
    cnt=1;
    for(int i=1;i<=lim;++i)
        if(sum[i])
        {
            d[1-i+lim]+=sum[i];
            d[i-1+lim+2]-=sum[i];
        }
    for(int i=1;i<=lim+lim;++i)
    {
        if(i-2>=0)
            d[i]+=d[i-2];
        ans=(ans+(n+n+d[i]-1)%mod*d[i]%mod*((mod+1)>>1)%mod*((i-lim+mod)%mod)%mod)%mod;
        n+=d[i];
        cnt=cnt*fac[d[i]]%mod;
    }
    cout<<ans<<" "<<cnt<<'\n';
    return 0;
}