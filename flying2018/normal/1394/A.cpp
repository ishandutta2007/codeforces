#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
ll a[N],b[N];
int ta,tb;
int main()
{
    int n;
    ll d,m;
    scanf("%d%lld%lld",&n,&d,&m);
    for(int i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        if(x>m) a[++ta]=x;
        else b[++tb]=x;
    }
    sort(a+1,a+ta+1,greater<ll>());
    sort(b+1,b+tb+1,greater<ll>());
    for(int i=1;i<=ta;i++) a[i]+=a[i-1];
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    ll ans=b[n];
    for(int i=1;i<=ta && (d+1)*(i-1)<n;i++)
    {
        int j=n-1-(d+1)*(i-1);
        if(j<0) j=0;
        ans=max(ans,a[i]+b[j]);
    }
    printf("%lld\n",ans);
    return 0;
}