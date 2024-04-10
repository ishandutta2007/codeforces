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

ll K=125250;

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

ld ans;
ld T;
ll TT=1;

void rec(ll k,ld c,ld m,ld p,ld ch)
{
    ans=(ans+(ld)ch*p*(ld)k);
    if (c>E)
    {
        ld o=min(T, c);
        if (m>E)
        {
            rec(k+1, c-o, m+o/2, p+o/2, ch*c);
        }else
        {
            rec(k+1, c-o, m, p+o, ch*c);
        }
    }
    if (m>E)
    {
        ld o=min(T, m);
        if (c>E)
        {
            rec(k+1, c+o/2, m-o, p+o/2, ch*m);
        }else
        {
            rec(k+1, c, m-o, p+o, ch*m);
        }
    }
}

void solve()
{
    ld cc, mm, pp, vv;
    ans=0;
    cin >> cc >> mm >> pp >> T;
    rec(1, cc, mm, pp, 1);
    cout.precision(10);
    cout <<fixed<< ans << "\n";
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