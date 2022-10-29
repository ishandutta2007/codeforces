#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first

using namespace std;

ll n, m, k, l, r, i, j, a[1000001], d[10000001], ans[1000001];
bool tt[1000001];
vector <pll> v;
string s;

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=0;return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
}

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h]=1;return;}
    ll w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

ll get(ll h,ll l,ll r,ll x)
{
    if (l==r) return a[l];
    ll w=(l+r)/2;
    if (x<=d[h*2]) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x-d[h*2]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];v.pb(mp(a[i],n-i));}
    build(1,1,n);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i = 0; i < n; i++) v[i].se=n-v[i].se;
    vector <pair<pll, ll> > z;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        z.pb(mp(mp(x,y),i));
    }
    sort(z.begin(),z.end());
    ll l=-1;
    for (int i = 0; i < z.size(); i++)
    {
        while (z[i].fi.fi-1>l) {l++;update(1,1,n,v[l].se);}
        ans[z[i].se]=get(1,1,n,z[i].fi.se);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
    return 0;
}