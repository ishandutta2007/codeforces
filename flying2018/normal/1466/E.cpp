#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
#define mod 1000000007
#define ll long long
using namespace std;
ll a[N];
int c[64],_2[N];
int main()
{
    int t;
    scanf("%d",&t);
    _2[0]=1;
    for(int i=1;i<=61;i++) _2[i]=2ll*_2[i-1]%mod;
    while(t --> 0)
    {
        memset(c,0,sizeof(c));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=60;j++)
            if((a[i]>>j)&1) c[j]++;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ll m1=0,m2=0;
            for(int j=0;j<=60;j++)
            if((a[i]>>j)&1) m1=(m1+1ll*n*_2[j]%mod)%mod;
            else m1=(m1+1ll*c[j]*_2[j]%mod)%mod;
            for(int j=0;j<=60;j++)
            if((a[i]>>j)&1) m2=(m2+1ll*c[j]*_2[j]%mod)%mod;
            ans=(ans+1ll*m1*m2%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}