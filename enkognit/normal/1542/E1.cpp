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

ll K=125250;

ll n, m, k, ans, a[505], c[505][505], md, dp1[300001], pr[300001], dp2[300001], fact[505], infact[505];

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

void make(int h)
{
    if (h>=n) return;

    ll y=0;

    for (int i = 1; i <= h; i++)
    {
        ll o=0;
        for (int p = i+1; p <= h*(h-1)/2; p++)
        {
            o=(o+dp1[p]*pr[p-i-1]%md)%md;
        }
        o=(o*(h-i+1))%md;
        y=(y+o)%md;
    }

    y=(y*c[n][h+1]%md*fact[n-h-1]%md)%md;

    //cout << h << " " << y << "\n";

    ans=(ans+y)%md;
}

void solve()
{
    cin >> n >> md;

    fact[0]=1;
    infact[0]=1;

    MOD=md;

    for (int i = 1; i <= n; i++)
    {
        fact[i]=fact[i-1]*i%md;
        infact[i]=binpow(fact[i], md-1, md);
    }

    for (int i = 0; i <= n; i++)
        c[i][0]=1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
        }

    dp1[0]=1;
    pr[0]=1;
    pr[1]=1;

    make(1);

    for (ll i = 2; i < n; i++)
    {
        for (int j = 0; j <= i*(i-1)/2; j++)
        {
            dp1[j]=pr[j];
            if (j-i>=0) dp1[j]=dp1[j]-pr[j-i]+md, dp1[j]%=md;
        }
        //cout << i << " :\n";
        for (int j = 0; j <= i*(i+1)/2; j++)
        {
            pr[j]=((j==0?0:pr[j-1])+dp1[j])%md;
            //cout << " " << j << " " << dp1[j] << " " << pr[j] << "\n";
        }
        make(i);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}