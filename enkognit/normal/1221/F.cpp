#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, a[500001], T, o, an=0, b[500001], q[500001];
pll d[3000001];ll tt[3000001];
vector <pll> v, z;
vector <ll> pr;

void push(ll h)
{
    if (tt[h])
    {
        tt[h*2]+=tt[h];
        tt[h*2+1]+=tt[h];
        d[h*2].fi+=tt[h];
        d[h*2+1].fi+=tt[h];
        tt[h]=0;
    }
}

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h]=mp(pr[l]-z[l].fi,z[l].fi);
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    if (d[h*2].fi>d[h*2+1].fi) d[h]=d[h*2]; else d[h]=d[h*2+1];
}

void update(ll h,ll l,ll r,ll x,ll y,ll k)
{
        push(h);
    if (x>y) return;
    //cout << h << " " << l << " " << r << " " << x << " " << y << "\n";
    if (l==x && y==r)
    {
        d[h].fi-=k;
        tt[h]-=k;
        push(h);
        return;
    }
    ll w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    if (d[h*2].fi>d[h*2+1].fi) d[h]=d[h*2]; else d[h]=d[h*2+1];
}

bool comp(pll x,pll y)
{
    if (x.fi<y.fi || (x.fi==y.fi && q[x.se]>q[y.se])) return 1; else return 0;
}

pll get(ll h,ll l,ll r,ll x,ll y)
{
    push(h);
    if (x>y) return mp(-1e18,0);
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;
    pll o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (o1.fi>o2.fi) return o1; else return o2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        if (x>y) swap(x,y);
        a[i]=h;
        q[i]=y;
        v.pb(mp(x, i));
        z.pb(mp(y, i));
    }
    sort(v.begin(), v.end(), comp);
    sort(z.begin(), z.end());
    vector <pll> u;
    vector <ll> r;
    pr.pb(a[z[0].se]);
    for (int i = 1; i < z.size(); i++)
    {
        pr.pb(pr[i-1]+a[z[i].se]);
    }
    for (int i = 0; i < z.size(); i++)
    {
        if (z.size()-1==i || z[i+1].fi>z[i].fi) {u.pb(z[i]);r.pb(pr[i]);}
    }
    z=u;
    pr=r;
    build(1,0,z.size()-1);
    //for (int i = 0; i < z.size(); i++) cout << pr[i] << " ";
    //cout << "\n";
    ll ans=0;
    pll w=mp(1e9+5,1e9+5);
    vector <ll> o;
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i].fi << "-" << q[v[i].se] << " " << p << " " << a[v[i].se] << ":\n";
        o.pb(i);
        if (i<v.size()-1 && v[i].fi==v[i+1].fi)
        {
            continue;
        }
        //cout << v[i].fi+d[1].fi << " " << v[i].fi << " " << d[1].se << "\n";
        ll p=0, l=0, r=z.size()-1;
        while (l<r)
        {
            ll w=(l+r)/2;
            if (z[w].fi<v[i].fi) l=w+1; else r=w;
        }
        p=l;
        //update(1,0,z.size()-1,0,p,1e18);
        pll f=get(1,0,z.size()-1,p,z.size()-1);
        //cout << f.fi << " " << f.se << " " << v[i].fi << " " << p << "\n";
        if (f.fi+v[i].fi>ans) ans=v[i].fi+f.fi, w=mp(v[i].fi, f.se);
        for (int j = 0; j < o.size(); j++)
        {
            ll p=0, l=0, r=z.size()-1;
            while (l<r)
            {
                ll w=(l+r)/2;
                if (z[w].fi<q[v[o[j]].se]) l=w+1; else r=w;
            }
            p=l;
            update(1,0,z.size()-1,p,z.size()-1,a[v[o[j]].se]);
        }
        o.clear();
    }
    cout << ans << "\n";
    cout << w.fi << " " << w.fi << " " << w.se << " " << w.se << "\n";
    return 0;
}
/*
8 7
1 1 30 5 5 1 1 1
1 2
2 3
2 4
4 5
2 6
6 7
6 8
2
*/