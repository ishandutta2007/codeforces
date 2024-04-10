#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;

int n,m;
int s[200005],t[200005];

class BIT
{
    public:
    int data[200005];
    int lowbit(int x)
    {
        return x&(-x);
    }
    void Add(int x,int y)
    {
        while(x<=200000)
        {
            data[x]+=y;
            x+=lowbit(x);
        }
    }
    int Query(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=data[x];
            x-=lowbit(x);
        }
        return res;
    }
}T;

long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
long long Inv(long long x)
{
    return qpow(x,mod-2);
}

int cnt[200005];
long long fac[200005],inv[200005];
int main()
{
    scanf("%d%d",&n,&m);
    fac[0]=1;
    inv[0]=1;
    for(int i=1;i<=200000;i++) 
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=Inv(fac[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        cnt[s[i]]++;
        T.Add(s[i],1);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t[i]);
    }
    long long Now=fac[n],ans=0;
    for(int i=1;i<=200000;i++) Now=Now*inv[cnt[i]]%mod;
    for(int i=1;i<=min(n,m);i++)
    {
        ans=(ans+T.Query(t[i]-1)*Now%mod*Inv(n-i+1))%mod;
        if(i==n && n<m) ans=(ans+(T.Query(t[i])-T.Query(t[i]-1))*Now%mod*Inv(n-i+1))%mod;
        if(!cnt[t[i]]) break;
        Now=Now*cnt[t[i]]%mod*Inv(n-i+1)%mod;
        T.Add(t[i],-1);
        cnt[t[i]]--;
    }
    printf("%lld\n",ans);
}