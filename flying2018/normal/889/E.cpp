#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define N 200010
#define fi first
#define se second
#define ll long long
using namespace std;
map<ll,ll>f;
ll a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    f[a[1]-1]=0;
    for(int i=2;i<=n;i++)
        for(auto p=f.lower_bound(a[i]);p!=f.end();f.erase(p++))
        {
            ll v=p->fi;
            f[v%a[i]]=max(f[v%a[i]],p->se+(i-1)*(v-v%a[i]));
            f[a[i]-1]=max(f[a[i]-1],p->se+(i-1)*((v+1)/a[i]-1)*a[i]);
        }
    ll ans=0;
    for(auto p:f) ans=max(ans,p.fi*n+p.se);
    printf("%lld\n",ans);
    return 0;
}