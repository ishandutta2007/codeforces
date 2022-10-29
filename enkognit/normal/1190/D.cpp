#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, p, ans, l, r, i, j, b[500005];
pll a[200005], d[2000005];
vector <ll> c[300001], v;

map<int,bool> t, q;

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h].fi=v[l];
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
}

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h].se=1;return;}
    ll w=(l+r)/2;
    if (d[h*2].fi<x) update(h*2+1,w+1,r,x); else update(h*2,l,w,x);
    d[h].se=d[h*2].se+d[h*2+1].se;
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r)
    {
        return d[h].se;
    }
    ll w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].se >> a[i].fi;
        if (!t[a[i].se])
        {
            t[a[i].se]=1;
            v.pb(a[i].se);
        }
    }
    sort(v.begin(),v.end());
    build(1,0,v.size()-1);
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0, p=0;
    vector <ll> u;
    for (int i = 0; i < n; i++)
    {
        if (!q[a[i].se])
        {
            p++;
            q[a[i].se]=1;
            update(1,0,v.size()-1,a[i].se);
        }
        u.pb(a[i].se);
        if (a[i].fi==a[i+1].fi) continue;
        //cout << a[i].fi << " " << u.size() << "\n";
        ans+=p*(p+1)/2;
        sort(u.begin(),u.end());
        ll z=lower_bound(v.begin(),v.end(),u[0])-v.begin()-1;
        ll y=get(1,0,v.size()-1,0,z);
        ans-=y*(y+1)/2;
        z=lower_bound(v.begin(),v.end(),u[u.size()-1])-v.begin()+1;
        y=get(1,0,v.size()-1,z,v.size()-1);
        ans-=y*(y+1)/2;
        for (int j = 1; j < u.size(); j++)
        {
            ll l=lower_bound(v.begin(),v.end(),u[j-1])-v.begin()+1,
               r=lower_bound(v.begin(),v.end(),u[j])-v.begin()-1;
            ll y=get(1,0,v.size()-1,l,r);
            ans-=y*(y+1)/2;
        }
        u={};
    }
    cout << ans << "\n";
    return 0;
}