#include<bits/stdc++.h>
#define maxn 1000030

using namespace std;
typedef long long ll;

struct seg{
    ll sum,mn,l,r;
};

seg a[maxn*4];
ll b[maxn],c[maxn],n,query;

void build(ll x,ll l,ll r)
{
    a[x].l=l;
    a[x].r=r;
    if (l==r) {a[x].sum=a[x].mn=b[l];return ;}
    ll mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    a[x].sum=a[x*2].sum+a[x*2+1].sum;
    a[x].mn=max(a[x*2].mn,a[x*2+1].mn);
}

void update(ll x,ll l,ll r)
{
    if (a[x].l>r||a[x].r<l) return;
    if (a[x].l>=l&&a[x].r<=r&&a[x].mn<=2) return;
    if (a[x].l==a[x].r) b[a[x].l]=c[b[a[x].l]],a[x].sum=a[x].mn=b[a[x].l];
    else {
        update(x*2,l,r);
        update(x*2+1,l,r);
        a[x].sum=a[x*2].sum+a[x*2+1].sum;
        a[x].mn=max(a[x*2].mn,a[x*2+1].mn);
    }
}

ll qry(ll x,ll l,ll r)
{
    if (a[x].l>r||a[x].r<l) return 0;
    if (a[x].l>=l&&a[x].r<=r) return a[x].sum;
    return qry(x*2,l,r)+qry(x*2+1,l,r);
}

int main()
{
    memset(c,0,sizeof(c));
    for (ll i=1;i<maxn;i++)
        for (ll j=1;i*j<maxn;j++)
            c[i*j]++;
    scanf("%I64d%I64d",&n,&query);
    for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
    build(1,1,n);
    while (query--)
    {
        ll o,u,v; scanf("%I64d%I64d%I64d",&o,&u,&v);
        if (o==1) update(1,u,v); else printf("%I64d\n",qry(1,u,v));
    }
    return 0;
}