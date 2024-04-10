#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
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

ll n, m, k, kol[100005];
ll fact[200005], infact[200005];

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


ll C(ll n,ll k)
{
    if (n<k) return 0;
    //cout << n << " " << k << " " << fact[n]*infact[k]%MOD*infact[n-k]%MOD << "\n";
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n >> k;
    ll ans=0;
    for (ll i = 0; i <= (n+k-1)/k; i++)
    {
        ans=(ans+C(n+k-1-k*i+i, i)*binpow(C(n, i),MOD-2, MOD)%MOD)%MOD;
    }
    cout << ans << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 2e5; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
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