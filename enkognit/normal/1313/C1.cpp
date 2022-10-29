#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = (1ll << 30) + 1;
//mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k;
ll a[1000001], pr[1000001], rp[1000001];


ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0, p = 0, mn = a[1];

    vector<pll> v;
    v.pb(mp(0,0));
    for (int i = 1; i <= n; i++)
    {
        while (v.back().fi >= a[i])
        {
            v.pop_back();
        }
        pr[i] = pr[v.back().se] + (i - v.back().se) * a[i];
        v.pb(mp(a[i],i));
    }
    v.clear();
    v.pb(mp(0,n+1));
    for (int i = n; i > 0; i--)
    {
        while (v.back().fi >= a[i])
        {
            v.pop_back();
        }
        rp[i] = rp[v.back().se] + (v.back().se - i) * a[i];
        v.pb(mp(a[i],i));
    }

    ans = 0, p = -1;
    for (int i = 1;i <= n; i++)
    {
        if (pr[i] + rp[i] - a[i] > ans)
        {
            ans = pr[i] + rp[i] - a[i];
            p = i;
        }
    }
    mn = 1e9;
    for (int i = p; i > 0; i--)
    {
        mn = min(mn, a[i]);
        a[i] = mn;
    }
    mn = 1e9;
    for (int i = p; i <= n; i++)
    {
        mn = min(mn, a[i]);
        a[i] = mn;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/