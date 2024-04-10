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

const ll MOD=1e9+7;

ll n, m, k, T, TT, a[1000001], b[1000001];

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

ll d[1000001];

void make_sets(int h)
{
    for (int i = 1; i <= h; i++) d[i]=i;
}

ll find_set(int h)
{
    if (h==d[h]) return h; else return d[h]=find_set(d[h]);
}

bool unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x!=y)
    {
        d[x]=y;
        return 1;
    }
    return 0;
}

bool tt[1000001];
vector<pll> v;

void dfs(int h)
{
    tt[h]=1;
    if (h!=1)
    {
        cout << "? " << h << "\n";
        for (int i = 1; i <= n; i++) cin >> a[i];
        fflush(stdout);
    }
    for (int i = 1; i <= n; i++)
        if (a[i]==1) v.pb(mp(i, h));
}

void solve()
{
    cin >> n;
    ll kl0=0, kl1=0, p0=0, p1=0;
    cout << "? 1\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]%2) kl1++, p1=i; else kl0++, p0=i;
    }
    fflush(stdout);
    ll p=0;
    vector<ll> z;
    if (kl1>=kl0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i]%2==0) z.pb(i);
        }
    }else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i]%2) z.pb(i);
        }
    }
    for (int i = 0; i < z.size(); i++)
        dfs(z[i]);
    cout << "!\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i].fi << " " << v[i].se << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
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
*/