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

const ll MOD=1e9+7;

ll n, m, k, a[1000001];

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
    ll o=0, mx=0, mn=1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn=min(mn, a[i]);
        mx=max(mx, a[i]);
    }

    if (mn<0)
    {
        cout << "NO\n";
        return;
    }

    sort(a+1,a+n+1);

    for (int i = 1; i <= n; i++)
    {
        o=gcd(o, a[i]-a[i-1]);
    }

    if ((mx-min(o, mn))/o+1>300)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n" << (mx-min(o, mn))/o+1 << "\n";
    for (int i = min(o, mn); i <= mx; i+=o)
        cout << i << " ";
    cout << "\n";
}

int main(int argc, char **argv) {
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