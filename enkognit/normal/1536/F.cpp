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

ll n, m, k, T, TT;
ll fact[(ll)1e6+5], infact[(ll)1e6+5];

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


ll C(ll n,ll k)
{
    if (n<k) return 0;
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n;
    ll ans=0;

    n--;

    for (int i = n%2; i <= n; i+=2)
    {
        if (n-i<=i) break;
        ll kl=C(n-i-1, i);
        ans=(ans+kl*fact[n-i]%MOD)%MOD;
    }

    n++;

    ans=(ans*2)%MOD;

    for (int i = n%2; i <= n; i+=2)
    {
        if (n-i<=i) break;
        ll kl=C(n-i-1, i);
        ans=(ans+kl*fact[n-i]%MOD)%MOD;
    }

    ans=(ans*2)%MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 1e6; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
    //cin >> t;
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