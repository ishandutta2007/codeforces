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

ll n, m, k, T, a[200005], b[200005];

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

char rev(char c)
{
    if (c=='R') return 'B'; else return 'R';
}

struct dsu
{
    ll d[100001];

    void make_sets(int h)
    {
        for (int i = 1; i <= h; i++) d[i]=i;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[x]=y;
    }
} g1, g2;

void solve()
{
    ll m1, m2;
    cin >> n >> m1 >> m2;
    g1.make_sets(n);
    g2.make_sets(n);
    for (int i = 1; i <= m1; i++)
    {
        ll x, y;
        cin >> x >> y;
        g1.unite_sets(x, y);
    }

    for (int i = 1; i <= m2; i++)
    {
        ll x, y;
        cin >> x >> y;
        g2.unite_sets(x, y);
    }

    vector<pll> v;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (g1.find_set(i)!=g1.find_set(j) && g2.find_set(i)!=g2.find_set(j))
                g1.unite_sets(i, j), g2.unite_sets(i, j), v.pb(mp(i, j));
        }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].fi << " " << v[i].se << "\n";
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