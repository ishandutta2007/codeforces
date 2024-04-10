#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=1000000007;
int n,a[500001],ans,mu[10000001],minn[10000001],cnt,p[1000001],sum[10000001],pval[500001];
bool prime[10000001];
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
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
inline void sieve()
{
    mu[1]=mod-1;
    prime[1]=1;
    for(int i=2;i<=10000000;++i)
    {
        if(!prime[i])
        {
            mu[i]=1;
            p[++cnt]=i;
            minn[i]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<=10000000;++j)
        {
            prime[i*p[j]]=1;
            minn[i*p[j]]=min(minn[i],p[j]);
            if(i%p[j]==0)
                break;
            mu[i*p[j]]=mod-mu[i];
        }
    }
}
int main()
{
    sieve();
    n=read();
    pval[0]=1;
    for(int i=1;i<=n;++i)
    {
        ++sum[a[i]=read()];
        pval[i]=Mod(pval[i-1]<<1);
    }
    for(int i=2;i<=10000000;++i)
        for(int j=i+i;j<=10000000;j+=i)
            sum[i]+=sum[j];
    for(int i=2;i<=10000000;++i)
        if(sum[i]&&mu[i])
            ans=Mod(ans+1ll*mu[i]*Mod(1ll*n*Mod(pval[sum[i]]+mod-1)%mod-1ll*sum[i]*pval[sum[i]-1]%mod+mod)%mod);
    for(int i=1;i<=n;++i)
    {
        vector<int> v,num;
        int val=a[i],m=0;
        while(val^1)
        {
            int w=minn[val];
            ++m;
            v.emplace_back(w);
            while(val%w==0)
                val/=w;
        }
        num.resize(1<<m);
        num[0]=1;
        for(int s=1;s<1<<m;++s)
        {
            num[s]=num[s^(s&-s)]*v[__builtin_ctz(s)];
            ans=Mod(ans-1ll*mu[num[s]]*Mod(pval[sum[num[s]]-1]+mod-1)%mod+mod);
        }
    }
    cout<<ans<<'\n';
    return 0;
}