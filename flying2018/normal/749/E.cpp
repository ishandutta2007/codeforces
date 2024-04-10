#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define db double
#define ll long long
using namespace std;
int a[N],n;
struct tree_array{
    ll a[N];
    void add(int x,ll v){for(;x<=n;x+=(x&(-x))) a[x]+=v;}
    ll operator [](int x){ll ans=0;for(;x;x-=(x&(-x))) ans+=a[x];return ans;}
}b,s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    db ans=0;
    for(int i=n;i>=1;b.add(a[i],1),s.add(a[i],i),i--) ans+=2*s[a[i]]*i+b[a[i]]*(1ll*n*n+n-2ll*i-2ll*n*i);
    for(ll i=n,r=0;i>=1;i--) ans+=i*r,r+=n-i+1;
    printf("%.9f",ans/n/(n+1));
    return 0;
}