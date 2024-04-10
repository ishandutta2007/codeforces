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

bool tt[1001];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n*2; i++) tt[i]=0;
    vector<pll> v;
    vector<ll> z;
    for (int i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        tt[x]=1;
        tt[y]=1;
        if (x>y) swap(x, y);
        v.pb(mp(x, y));
    }
    ll ans=0;
    for (int i = 1; i <= 2*n; i++)
    {
        if (!tt[i]) z.pb(i);
    }
    for (int i = 0; i < z.size()/2; i++)
    {
        v.pb(mp(z[i], z[i+z.size()/2]));
    }
    for (int i = 0; i < v.size(); i++)
        for (int j = i+1; j < v.size(); j++)
        {
            if ((v[i].fi<=v[j].fi && v[i].se>=v[j].fi) ^ (v[i].fi<=v[j].se && v[i].se>=v[j].se))
            {
                ans++;
            }
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}