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
pll a[1000001];


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
    ll t;
    cin >> t;
    vector<ll> v;
    v.pb(3);
    v.pb(6);
    v.pb(5);
    v.pb(7);
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a >= 4 && b >= 4 && c >= 4) cout << "7\n"; else
        {
            ll ans = 0;
            vector<ll> w = v;
            for (int i = 0; i < 40320; i++)
            {
                ll an=0, x=a, y=b, z=c;
                if (x > 0) x--, an++;
                if (y > 0) y--, an++;
                if (z > 0) z--, an++;
                for (int i = 0; i < w.size(); i++)
                {
                    if (w[i] == 1)
                    {
                        if (x > 0) x--, an++;
                    }
                    if (w[i] == 2)
                    {
                        if (y > 0) y--, an++;
                    }
                    if (w[i] == 3)
                    {
                        if (x > 0 && y > 0) y--, x--, an++;
                    }
                    if (w[i] == 4)
                    {
                        if (z > 0) z--, an++;
                    }
                    if (w[i] == 5)
                    {
                        if (x > 0 && z > 0) x--, z--, an++;
                    }
                    if (w[i] == 6)
                    {
                        if (y > 0 && z > 0) y--, z--, an++;
                    }
                    if (w[i] == 7)
                    {
                        if (x > 0 && y > 0 && z > 0) x--, y--, z--, an++;
                    }
                }
                ans = max(ans, an);
                next_permutation(all(w));
            }
            cout << ans << "\n";
        }
    }
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