#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

const ll MOD=1000000007;

ll n, m, k, q, T, ans[200005];
ll a[200001];
bool tt[100005];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

string s;

pair<pll, ll> d[800001];

pair<pll, ll> operator + (pair<pll, ll> x,pair<pll, ll> y)
{
    return mp(mp(max(x.fi.fi, x.se+y.fi.fi), min(x.fi.se,x.se+y.fi.se)), y.se+x.se);
}

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=mp(mp(0,0), 0);
        if (s[l]=='+') d[h].fi.fi++, d[h].se++; else d[h].fi.se--, d[h].se--;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]+d[h*2+1];
}

pair<pll, ll> get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(mp(0,0), 0);
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void solve()
{
    cin >> n >> m;
    cin >> s;
    s=' '+s;
    build(1,1,n);
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        pair<pll, ll> o=get(1,1,n,1,x-1)+get(1,1,n,y+1,n);
        cout << o.fi.fi-o.fi.se+1 << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
11
CCCTTTTTTCC
3
1 11
4 9
1 6
*/