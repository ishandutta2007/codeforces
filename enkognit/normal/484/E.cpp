#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm, u[100005], a[100005], kol[100005], b[100005];
vector<ll> d[100005];
bool tt[100005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

struct node
{
    node *l, *r;
    pair<pii, pii> z;
    node(bool x=0):l(nullptr),r(nullptr),z(mp(mp(x, x), mp(x, 1))){};
};

vector<pair<node*,int> > root;

pair<pii, pii> mk(pair<pii, pii> x,pair<pii, pii> y)
{
    pair<pii,pii> h;
    h.se.se=x.se.se+y.se.se;
    h.se.fi=max(max(x.se.fi,y.se.fi),x.fi.se+y.fi.fi);
    if (x.se.se==x.fi.fi) h.fi.fi=x.fi.fi+y.fi.fi; else h.fi.fi=x.fi.fi;
    if (y.se.se==y.fi.se) h.fi.se=x.fi.se+y.fi.se; else h.fi.se=y.fi.se;
    return h;
}

void build(node *h,int l,int r)
{
    if (l==r)
    {
        h->z.se.se=1;
        return;
    }
    int w=(l+r)/2;
    h->l=new node(0);
    h->r=new node(0);
    build(h->l,l,w);
    build(h->r,w+1,r);
    h->z=mk(h->l->z,h->r->z);
    //cout << l << " " << r << " " << h->z.se.se << " " << h->l->z.se.se << " " << h->r->z.se.se << "\n";
}

node* update(node *h,int l,int r,int x)
{
    if (l==r)
    {
        node *u=new node(1);
        return u;
    }
    int w=(l+r)/2;

    node* u=new node(0);

    if (x<=w)
    {
        u->r=h->r;
        u->l=update(h->l,l,w,x);
    }else
    {
        u->l=h->l;
        u->r=update(h->r,w+1,r,x);
    }

    u->z=mk(u->l->z, u->r->z);
    return u;
}

pair<pii,pii> get(node *h,int l,int r,int x,int y)
{
    if (x>y) return mp(mp(0, 0), mp(0, 0));
    if (l==x && y==r)
    {
        //cout << " ! " << l << " " << r << " " << h->z.se.fi << " " << h->z.se.se << "\n";
        return h->z;
    }
    int w=(l+r)/2;
    return mk(get(h->l,l,w,x,min(y,w)), get(h->r,w+1,r,max(x,w+1),y));
}

void solve()
{
    cin >> n;
    root.pb(mp(new node(), 1e9));
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i], i));
    }
    sort(all(v));
    reverse(all(v));
    build(root.back().fi,1,n);
    //cout << root[0].fi->z.se.se << " " << root[0].fi->z.se.fi << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i].fi << "\n";
        root.pb(mp(update(root.back().fi,1,n,v[i].se), v[i].fi));
    }


    ll q;
    cin >> q;

    while (q--)
    {
        ll l, r, w;
        cin >> l >> r >> w;
        ll lr=0, rr=root.size()-1;
        while (lr<rr)
        {
            int ww=(lr+rr)/2;
            //cout << lr << " " << ww << " " << rr << "\n";
            pair<pii,pii> q=get(root[ww].fi,1,n,l,r);
            //cout << " " << q.se.fi << " " << q.se.se << "\n";
            if (q.se.fi>=w) rr=ww; else lr=ww+1;
        }
        //cout << rr << "\n";
        cout << root[rr].se << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
12 19

8104756243030 6378153829074 7864481946698 7989644292977 6203792744877 7139461054198 7417193946416 6746398916257 7921954925499 8164742799871 6117430537523 7832265773212

2 7832265773212

1 8085437996816

2 7139461054198

1 6093518998518

2 7864481946698

2 7417193946416

2 6203792744877

2 6746398916257

1 7739700243907

2 7739700243907

1 7086445635445

1 6598712266235

2 6598712266235

1 6669032332134

2 7921954925499

1 6390459948701

2 7989644292977

2 8164742799871

1 5687905455139

*/