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

void update(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        d[h]=k;
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=min(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 1e18;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return min(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

ll check(ll l,ll r)
{
    if (l==r) return -1;
    cout << "? " << l << " " << r << "\n";
    ll x;
    cin >> x;
    return x;
}

void solve()
{
    cin >> n;
    cout << "? 1 "<< n << "\n";
    ll p;
    cin >> p;
    fflush(stdout);
    ll l=1, r=n;
    while (l<r)
    {
        ll w=(l+r)/2;
        if (p<=w)
        {
            ll x=check(min(p,l),w);
            if (x==p) r=w; else l=w+1;
        }else
        {
            ll x=check(w+1,max(r,p));
            fflush(stdout);
            if (x==p) l=w+1; else r=w;
        }
    }
    cout << "! " << l << "\n";
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

10
4 1 7 6 5 5 4 2 3 1
*/