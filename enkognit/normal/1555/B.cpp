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

ll n, m, k, T, a[500001];
vector<ll> c[200001];

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
    ll W, H;
    cin >> W >> H;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w, h;
    cin >> w >> h;

    ll ans=1e18;
    if (!(w-x1>W-x2))
    {
        ans=min(ans, max(w-x1, 0ll));
        //cout << "- 1\n";
    }
    if (!(x1<x2-(W-w)))
    {
        ans=min(ans, max(x2-(W-w), 0ll));
        //cout << "- 2\n";
    }
    if (!(h-y1>H-y2))
    {
        ans=min(ans, max(h-y1, 0ll));
        //cout << "- 3\n";
    }
    if (!(y1<y2-(H-h)))
    {
        ans=min(ans, max(y2-(H-h), 0ll));
        //cout << "- 4\n";
    }
    cout.precision(10);
    if (ans==1e18)cout << "-1\n"; else cout <<fixed<< (ld)ans << "\n";
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