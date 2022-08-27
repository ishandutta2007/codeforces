#include<bits/stdc++.h>
#define maxn 3040050

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],s[maxn],n,k,m,l,r,mid;

bool check(ll x)
{
    ll t=m; int u=min(n,k);
    for (int i=1;i<=u;i++) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++)
    {
        int lf=max(1ll,i-k)-1,rt=min(n,k+i);
        if (rt>u) s[rt]=s[rt-1]+a[rt],u=rt;
        if (s[rt]-s[lf]<x) t-=(x-(s[rt]-s[lf])),s[rt]+=x-(s[rt]-s[lf]);
        if (t<0) return false;
    }
    return true;
}

int main()
{
    scanf("%lld%lld%lld",&n,&k,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    l=-1; r=2000000000000000000ll;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) l=mid; else r=mid;
    }
    cout << l << endl;
}