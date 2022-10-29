#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, l, r, i, j, x, y, ans[1000001];
ll d[8000001], z[8000001], t[8000001];
vector <ll> v;

void push(ll h)
{
    t[h*2]+=t[h];
    t[h*2+1]+=t[h];
    d[h*2]+=t[h];
    d[h*2+1]+=t[h];
    t[h]=0;
}

void update(ll h,ll l,ll r,ll x,ll y,ll k)
{
    push(h);
    if (x>y) return;
    if (l==x && y==r)
    {
        t[h]+=k;
        d[h]+=k;
        return;
    }
    ll w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
}

ll get(ll h,ll l,ll r,ll x)
{
    push(h);
    if (l==r) return d[h];
    ll w=(l+r)/2;
    if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
}

void bld(ll h,ll l,ll r)
{
    if (l==r)
    {
        z[h]=v[l];
        return;
    }
    ll w=(l+r)/2;
    bld(h*2,l,w);
    bld(h*2+1,w+1,r);
    z[h]=max(z[h*2],z[h*2+1]);
}

ll gt(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return -1e18;
    if (l==x && y==r)
    {
        return z[h];
    }
    ll w=(l+r)/2;
    return max(gt(h*2,l,w,x,min(y,w)),gt(h*2+1,w+1,r,max(x,w+1),y));
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int it = 0; it < n; it++)
    {
        cin >> k;
        ll p=0;
        v={};
        v.pb(0);
        for (int j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            p=max(x,p);
            v.pb(x);
        }
        bld(1,1,k);
        //cout << it << "\n";
        update(1,1,m,k+1,m-k,p);
        //cout << it << "\n";
        for (int i = 1; i <= k; i++)
        {
            ll p=0, l=max(1ll, i-(m-k)), r=i;
            if (m-k<i) p=-1e18;
            ans[i]+=max(gt(1,1,k,l,r),p);
        }
        //cout << it << "\n";
        for (int j = m; j > max(m-k,k); j--)
        {
            ll i=j-m+k;
            ll p=0, l=i, r=k;
            ans[j]+=max(gt(1,1,k,l,r),p);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i]+get(1,1,m,i) << " ";
    }
    return 0;
}