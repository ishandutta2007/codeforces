#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, s, f, o, T, a[300005];
vector<ll> c[300005];

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}


void solve()
{
    ll u, v;
    cin >> n >> u >> v;
    vector<pll> vv;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vv.pb(mp(a[i], i));
    }
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i]-a[i-1])>1)
        {
            cout << "0\n";
            return;
        }
    }
    ll ans=1e18;
    for (int i = 2; i <= n; i++)
    {
        if (a[i-1]<a[i])
        {
            ans=min(ans, u);
            ans=min(ans, v);
        }
        if (a[i-1]>a[i])
        {
            ans=min(ans, v);
            ans=min(ans, u);
        }
        if (a[i-1]==a[i])
        {
            ans=min(ans, u+v);
            //if (a[i]<1e6)
            {
                ans=min(ans, v*2);
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
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
10 10
1 3
3 5
5 7
7 9
2 9
1 4
4 6
6 8
8 10
2 10
*/