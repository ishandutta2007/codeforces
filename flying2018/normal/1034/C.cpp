#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000010
#define ll long long
#define mod 1000000007
using namespace std;
int num[N],fa[N],f[N],cnt[N];
ll sum[N];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=2;i<=n;i++) scanf("%d",&fa[i]);
    for(int i=n;i;i--) sum[fa[i]]+=(sum[i]+=num[i]);
    for(int i=1;i<=n;i++)
    {
        ll s=sum[1]/gcd(sum[i],sum[1]);
        if(s<=n) cnt[s]++;
    }
    for(int i=1;i<=n;i++)
    if(cnt[i]) for(int j=i;j<=n;j+=i) f[j]+=cnt[i];
    for(int i=1;i<=n;i++) f[i]=f[i]==i;
    ll ans=0;
    for(int i=n;i>1;i--)
    if(f[i])
    {
        for(int j=i*2;j<=n;j+=i) f[i]=(f[i]+f[j])%mod;
        ans=(ans+f[i])%mod;
    }
    printf("%lld\n",ans+1);
    return 0;
}