#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 500010
#define ll long long
using namespace std;
ll a[N],s[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1,greater<ll>());
    ll ans=0;
    for(int i=1;i<=n;i++) ans=ans+a[i]*(n-i);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll res=ans;
    for(int i=n;i>=1;i--)
    if((n-i)%(k+1)) res-=s[i],ans=max(ans,res);
    printf("%lld\n",ans);
    return 0;
}