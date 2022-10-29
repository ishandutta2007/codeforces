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

ll n, m, k, T;

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

ll d[4000001];
ll tt[4000001];

void push(int h)
{
    if (tt[h])
    {
        d[h*2]+=tt[h];
        tt[h*2]+=tt[h];
        d[h*2+1]+=tt[h];
        tt[h*2+1]+=tt[h];
        tt[h]=0;
    }
}

void update(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return;
    if (l==x && y==r)
    {
        d[h]+=k;
        tt[h]+=k;
        return;
    }
    push(h);
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    d[h]=min(d[h*2],d[h*2+1]);
}

void solve()
{
    cin >> n >> m;
    vector<pair<ll, pll> > v;
    for (int i = 1; i <= n; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        v.pb(mp(x, mp(l, r)));
    }
    sort(all(v));
    ll z=0, ans=1e18;
    for (int i = 0; i < v.size(); i++)
    {
        update(1,1,m-1,v[i].se.fi,v[i].se.se-1,1);
        //cout << "+ " << v[i].se.fi << " " << v[i].se.se-1 << "\n";
        while (z<i && d[1]>0)
        {
            ans=min(ans, v[i].fi-v[z].fi);
            update(1,1,m-1,v[z].se.fi,v[z].se.se-1,-1);
            //cout << "- " << v[i].se.fi << " " << v[i].se.se-1 << "\n";
            z++;
        }
        if (d[1]>0) ans=0;
    }
    //cout << " " << w << " " << z << " " << p << " " << T << "\n";
    cout << ans << "\n";
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