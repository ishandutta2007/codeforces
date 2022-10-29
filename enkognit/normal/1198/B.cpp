#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

const ll MOD=1e9+7;
ll n, m, i, j, k, t, I, a[500001], d[1000001];
vector <ll> v, q;

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h]=a[l];
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
}

void upd(ll h,ll l,ll r,ll x,ll u)
{
    if (l==r)
    {
        d[h]=u;
        return;
    }
    ll w=(l+r)/2;
    d[h*2]=max(d[h*2],d[h]);
    d[h*2+1]=max(d[h*2+1],d[h]);
    d[h]=0;
    if (x<=w)upd(h*2,l,w,x,u); else upd(h*2+1,w+1,r,x,u);
}

void gt(ll h,ll l,ll r)
{
    if (l==r)
    {
        a[l]=d[h];
        return;
    }
    ll w=(l+r)/2;
    d[h*2]=max(d[h*2],d[h]);
    d[h*2+1]=max(d[h*2+1],d[h]);
    d[h]=0;
    gt(h*2,l,w);
    gt(h*2+1,w+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> m;
    for (int it = 0; it < m; it++)
    {
        ll p, x, y;
        cin >> p;
        if (p==1)
        {
            cin >> x >> y;
            upd(1,1,n,x,y);
        }else
        {
            cin >> x;
            d[1]=max(x,d[1]);
        }
    }
    gt(1,1,n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}