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

void solve()
{
    cin >> n;
    ll k1=0, k0=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]=a[i]%2;
        if (a[i]) k1++; else k0++;
    }
    if (k1==k0)
    {
        vector<ll> v;
        for (int i = 1; i <= n; i++)
        {
            if (a[i]==1) v.pb(i);
        }
        ll an1=0, an0=0;
        for (int i = 0; i < v.size(); i++)
        {
            an1+=abs(v[i]-(i*2+1));
            an0+=abs(v[i]-(i*2+2));
        }
        cout << min(an1,an0) << "\n";
    }else
    if (abs(k1-k0)==1)
    {
        vector<ll> v;
        if (k1<k0)
        {
            for (int i = 1; i <= n; i++) a[i]^=1;
        }
        for (int i = 1; i <= n; i++)
            if (a[i]==0) v.pb(i);
        ll an=0;
        for (int i = 0; i < v.size(); i++)
        {
            an+=abs(v[i]-(i*2+2));
        }
        cout << an << "\n";
    } else
    cout << "-1\n";
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