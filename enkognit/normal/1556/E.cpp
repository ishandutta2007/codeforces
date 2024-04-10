#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll n, m, k, T, a[200005], b[4][4], c[4][4];

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

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

ll d[1000005], g[1000005];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=a[l];
        g[h]=a[l];
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=min(d[h*2], d[h*2+1]);
    g[h]=max(g[h*2], g[h*2+1]);
}

ll get_min(int h,int l,int r,int x,int y)
{
    if (x>y) return 1e18;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return min(get_min(h*2,l,w,x,min(y,w)), get_min(h*2+1,w+1,r,max(x,w+1),y));
}

ll get_max(int h,int l,int r,int x,int y)
{
    if (x>y) return -1e18;
    if (l==x && y==r) return g[h];
    int w=(l+r)/2;
    return max(get_max(h*2,l,w,x,min(y,w)), get_max(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[i]=x-a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        a[i]+=a[i-1];
    }

    build(1,1,n);

    for (int it = 1; it <= k; it++)
    {
        ll x, y;
        cin >> x >> y;
        ll mn=get_min(1,1,n,x,y), mx=get_max(1,1,n,x,y);
        //cout << a[x-1] << " " << mn << " " << mx << "\n";
        if (mn<a[x-1] || a[x-1]!=a[y]) cout << "-1\n"; else cout << mx-a[x-1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}