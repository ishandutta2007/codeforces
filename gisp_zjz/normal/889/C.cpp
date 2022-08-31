#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 2000020

using namespace std;
typedef long long ll;

ll a[maxn],s[maxn],n,k,ans;

ll pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tmp=pow_(x,y/2);
    tmp=tmp*tmp%mod;
    if (y%2) tmp=tmp*x%mod;
    return tmp;
}

ll rev(ll x)
{
    return pow_(x,mod-2);
}

int main()
{
    scanf("%d%d",&n,&k);
    ans=1; s[0]=0;
    for (int i=2;i<n;i++) ans=ans*i%mod;
    for (int i=1;i<=k;i++)
    {
        a[i]=ans;s[i]=(s[i-1]+a[i])%mod;
    }
    for (int i=k+1;i<n;i++)
    {
        a[i]=(s[i-1]-s[i-1-k])*rev(i)%mod;
        s[i]=(s[i-1]+a[i])%mod;
    }
    ans=ans*(n-1)%mod;
    ans=(ans-s[n-1]+mod)%mod;
    printf("%d\n",ans);
    return 0;
}