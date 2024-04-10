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

ll n, m, k, T, kl, sm;
vector<ll> z, a, v;
vector<pll> zp;

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

pair<pll, pll> d[1600005];

void f(pair<pll,pll> &h,pair<pll,pll> &x,pair<pll,pll> &y)
{
    h.se.se=x.se.se+y.se.se;
    h.se.fi=x.se.fi+y.se.fi;
    h.fi.fi=x.fi.fi+y.fi.fi+x.se.se*y.se.fi;
    h.fi.se=x.fi.se+y.fi.se+y.se.se*x.se.fi;
}

void build(int h,int l,int r)
{
    if (l==r)
    {
        while (T<n && v[l]>a[T]) T++;
        if (T<n && v[l]==a[T])
        {
            d[h]=mp(mp(v[l], v[l]), mp(v[l], 1));
            kl++;
        }else
        {
            d[h]=mp(mp(0, 0), mp(0, 0));
        }
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    f(d[h], d[h*2], d[h*2+1]);
}

ll get_left(int h,int l,int r,int x)
{
    if (x==0) return 0;
    if (l==r)
    {
        return d[h].se.fi;
    }
    int w=(l+r)/2;
    if (d[h*2].se.se<x) return d[h*2].se.fi+get_left(h*2+1,w+1,r,x-d[h*2].se.se); else
        return get_left(h*2,l,w,x);
}

ll get_right(int h,int l,int r,int x)
{
    if (x==0) return 0;
    if (l==r)
    {
        return d[h].se.fi;
    }
    int w=(l+r)/2;
    if (d[h*2+1].se.se<x) return d[h*2+1].se.fi+get_right(h*2,l,w,x-d[h*2+1].se.se); else
        return get_right(h*2+1,w+1,r,x);
}

ll get_pos_left(int h,int l,int r,int x)
{
    if (l==r) return l;
    int w=(l+r)/2;
    if (d[h*2].se.se<x) return get_pos_left(h*2+1,w+1,r,x-d[h*2].se.se); else
        return get_pos_left(h*2,l,w,x);
}

ll get_pos_right(int h,int l,int r,int x)
{
    if (l==r) return l;
    int w=(l+r)/2;
    if (d[h*2+1].se.se<x) return get_pos_right(h*2,l,w,x-d[h*2+1].se.se); else
        return get_pos_right(h*2+1,w+1,r,x);
}

pair<pll,pll> get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(mp(0, 0), mp(0, 0));
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    pair<pll,pll> o, o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    f(o, o1, o2);
    return o;
}

void update(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        if (k==1)
        {
            d[h]=mp(mp(v[l],v[l]), mp(v[l], 1));
        }else
        {
            d[h]=mp(mp(0,0), mp(0, 0));
        }
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    f(d[h],d[h*2],d[h*2+1]);
}

void get_ans()
{
    if (kl<2)
    {
        cout << "0\n";
        return;
    }
    ll l=1, r=kl/2;
    while (l<r)
    {
        int w=(l+r+1)/2;
        if (get_left(1,1,v.size()-1,w)>get_right(1,1,v.size()-1,w-1)) l=w; else r=w-1;
    }

    ll ans=0;

    //cout << kl << " " << l << " " << get_left(1,1,v.size()-1,l) << " " << get_right(1,1,v.size()-1,l-1) << "\n";

    bool ttt=0;

    if (kl%2)
    {
        ll o1=get_left(1,1,v.size()-1,kl/2+1), o2=get_right(1,1,v.size()-1,kl/2);
        //cout << "    " << o1 << " " << o2 << "\n";
        if (o1>o2)
        {
            ttt=1;
            ans+=o1-o2;
        }
    }

    //cout << " ! " << get(1,1,v.size()-1,1,get_pos_left(1,1,v.size()-1,l)).fi.se << " " << get_pos_left(1,1,v.size()-1,l) << "\n";

    ans+=2*(get(1,1,v.size()-1,1,get_pos_left(1,1,v.size()-1,l)).fi.se-(l>1?get(1,1,v.size()-1,get_pos_right(1,1,v.size()-1,l-1), v.size()-1).fi.fi:0));

    //cout << kl << " " << ttt << " " << sm << " " << ans << " " << l << " " << "\n";
    //cout << "      " << get(1,1,v.size()-1,1,get_pos_left(1,1,v.size()-1,l)).se.se << " " << get(1,1,v.size()-1,get_pos_right(1,1,v.size()-1,l-1), v.size()-1).se.se << "\n";

    ans=sm-ans;

    cout << ans << "\n";
}

void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.pb(x);
        z.pb(x);
        sm+=x;
    }
    sort(all(a));

    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        zp.pb(mp(t, x));
        z.pb(x);
    }

    sort(all(z));

    v.pb(0);

    v.pb(z[0]);

    for (int i = 1; i < z.size(); i++)
    {
        if (z[i]!=z[i-1]) v.pb(z[i]);
    }

    build(1,1,v.size()-1);

    //cout << kl << "\n";

    //cout << "\n";
    //cout << d[1].se.fi << "\n";
    //cout << "\n";

    get_ans();

    for (int i = 0; i < zp.size(); i++)
    {
        ll t=zp[i].fi, x=zp[i].se;
        if (t==1)
        {
            kl++;
            sm+=x;
            update(1,1,v.size()-1,lower_bound(all(v),x)-v.begin(),1);
        }else
        {
            kl--;
            sm-=x;
            update(1,1,v.size()-1,lower_bound(all(v),x)-v.begin(),0);
        }
        get_ans();
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
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