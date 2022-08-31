#include<bits/stdc++.h>
#define maxn 10000020

using namespace std;
typedef long long ll;

ll prime[maxn],sum[maxn],p[maxn],a[maxn],miu[maxn],cnt,n,a1,a2,a3,m,t;
bool f[maxn];

int main()
{
    scanf("%d",&n);cnt=0;
    memset(p,0,sizeof(p));
    for (int i=2;i<=n;i++)
    {
        if (!p[i]) prime[cnt++]=p[i]=i;
        for (int j=0;j<cnt;j++)
        {
            if (prime[j]*i>n) break;
            p[i*prime[j]]=prime[j];
            if (i%prime[j]==0) break;
        }
    }
    for (int i=2;i<=n;i++)
    {
        t=i/p[i];
        if (t==1) miu[i]=-1;
        else if (t%p[i]==0) miu[i]=0;
        else miu[i]=miu[p[i]]*miu[t];
    }
    memset(f,true,sizeof(f));
    m=n-1;
    for (int i=n/2+1;i<=n;i++)
        if (p[i]==i) m--,f[i]=false;
    a3=0;a1=0;a2=0;
    for (int i=2;i<=n;i++) if (f[i]) a[p[i]]++; sum[1]=0;
    for (int i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=0;i<cnt;i++)
    {
        t=max(prime[i],n/prime[i]);
        a3+=(sum[n]-sum[t])*a[prime[i]];
    }
    for (int i=2;i*2<=n;i++)
    {
        t=n/i;
        a1+=miu[i]*t*(t-1)/2;
    }
    printf("%I64d\n",m*(m-1)+a1+a3);
    return 0;
}