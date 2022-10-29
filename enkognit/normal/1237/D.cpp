#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const ll MOD=1e9+7;

int n, m, it, i, p, k, T, j, A, B, C, y, kol, a[200001], ans[1000001];
bool tt[200001];

struct ver
{
    ver *l, *r;
    ll mn, mx;
    ver():mn(0),mx(0),l(nullptr),r(nullptr){};
};

ver *root=new ver();

void build(ver *h,ll l,ll r)
{
    if (l==r)
    {
        h->mn=a[l];
        h->mx=a[l];
        return;
    }
    ll w=(l+r)/2;
    h->l=new ver();
    h->r=new ver();
    build(h->l,l,w);
    build(h->r,w+1,r);
    h->mn=min(h->l->mn,h->r->mn);
    h->mx=max(h->l->mx,h->r->mx);
}

void update(ver *h,ll l,ll r,ll x,ll k)
{
    if (l==r)
    {
        h->mn=k;
        h->mx=k;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w) update(h->l,l,w,x,k); else update(h->r,w+1,r,x,k);
    h->mn=min(h->l->mn,h->r->mn);
    h->mx=max(h->l->mx,h->r->mx);
}

pll get(ver *h,ll l,ll r,ll x,ll y)
{
    if (x>y) return mp(1e18,0);
    if (l==x && y==r)
    {
        return mp(h->mn,h->mx);
    }
    ll w=(l+r)/2;
    pll o=get(h->l,l,w,x,min(y,w)), z=get(h->r,w+1,r,max(x,w+1),y);
    return mp(min(o.fi,z.fi),max(o.se,z.se));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector <pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    for (int i = n+1; i <= n*2; i++) a[i]=a[i-n];
    build(root,1,n*2);
    //cout << get(root,1,n*2,2,5).se << "\n";
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        ll l=v[i].se, r=n*2;
        //ll u=v[i].fi;
        while (l<r)
        {
            ll w=(l+r+1)/2;
            pll p=get(root,1,n*2,v[i].se,w);
            //cout << l << " " << r << ": " << w << " " << p.fi << " " << p.se << " " << v[i].fi << " " << ((p.fi*2)<v[i].fi) << "\n";
            if (p.se>v[i].fi) {r=w-1;continue;}else
            //cout << l << " " << r << "\n";
            if (p.fi*2<v[i].fi) {r=w-1;} else {l=w;}
        }
        //cout << v[i].se << " " << l << " " << r <<  "\n";
        if (l==n*2) ans[v[i].se]=-1;else
        if (a[l+1]>v[i].fi)
        {
            if (ans[l+1]!=-1)
            ans[v[i].se]=l+1-v[i].se+ans[l+1]; else ans[v[i].se]=-1;
        }else ans[v[i].se]=l+1-v[i].se;
        ans[v[i].se+n]=ans[v[i].se];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}