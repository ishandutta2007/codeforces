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

ll n, m, k, a[1000000];
vector<ll> c[200005];

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
    ll mn=1e18, mx=0, sm=0, ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sm+=a[i];
    }

    sort(a+1,a+n+1);

    ll u=0;

    for (int i = 1; i <= n; i++)
    {
        ans+=(i-1)*a[i]-u;
        u+=a[i];
    }

    if (n==1)
    {
        cout << "0\n";
        return;
    }

    cout << a[n]-ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}