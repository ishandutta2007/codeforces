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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj, a[200001];
vector<pll> v;

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

ll d[2000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=v[l].se;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=min(d[h*2], d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 1e18;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return min(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),r));
}

void solve()
{
    cin >> n >> m;
    ll sm=0;
    v.clear();
    v.pb(mp(0, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sm+=a[i];
        v.pb(mp(sm, i));
    }
    sort(all(v));
    //cout << sm << "\n";
    build(1,0,n);
    while (m--)
    {
        ll x, ans=1e18;
        cin >> x;
        if (v.back().fi>=x)
        {
            ll p=0, s=0;
            ll l=0, r=n;
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w].fi>=x-s) r=w; else l=w+1;
            }
            ans=min(ans, p+get(1,0,n,l,n)-1);
        }else
        if (sm>0)
        {
            ll p=(x-v.back().fi)/sm*n, s=p/n*sm;
            if (s+v.back().fi<x) s+=sm, p+=n;
            ll l=0, r=n;
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w].fi>=x-s) r=w; else l=w+1;
            }
            ans=min(ans, p+get(1,0,n,l,n)-1);
        }else
        {
            ans=-1;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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

10
4 1 7 6 5 5 4 2 3 1
*/