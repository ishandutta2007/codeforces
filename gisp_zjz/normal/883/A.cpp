#include<bits/stdc++.h>
#define maxn 203040

using namespace std;
typedef long long ll;
ll a[maxn],n,m,h,d,t,p,s,q,o,u,oo;

ll nxt_pos(ll x)
{
    return min(n+1,x/h+1);
}

int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&h,&d); t=d/h+1;
    for (int i=1;i<=m;i++) scanf("%lld",&a[i]); p=0;
    for (int i=1;i<=m;i++)
    {
        if (a[i]<=p) continue;
        q=nxt_pos(p)*h; o=min(q,a[i]);
        oo=min(a[i],n*h);
        u=(oo-o)/(t*h);
        s+=u; o+=u*t*h;
        s++; p=o+d;
        if (p<a[i]) p=a[i]+d,s++;
    }
    q=nxt_pos(p);
    if (q<=n) s+=(n-q)/t+1;
    cout << s << endl;
}