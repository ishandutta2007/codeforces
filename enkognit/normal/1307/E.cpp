#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, T, Q, a[5001];
vector<ll> v[5001];
vector<pll> q[5001];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll gt(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].pb(i);
    }
    vector<pll> g;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (v[x].size() < y) continue;
        g.pb(mp(x,v[x][y-1]));
        q[x].pb(mp(v[x][y-1], v[x][v[x].size()-y]));
    }
    pll ans = mp(0, 1);
    for (int i = 1; i <= n; i++)
        if (q[i].size())
    {
        ans.first++;
        ans.second *= q[i].size();
        ans.second %= MOD;
    }
    //cout << ans.first << " " << ans.second << "\n";
    for (int i = 0; i < g.size(); i++)
    {
        pll an = mp(1,1);
        for (int j = 1; j <= n; j++)
        {
            ll p1 = 0, p2 = 0, p3 = 0;
            for (int u = 0; u < q[j].size(); u++)
            {
                if (j == g[i].fi)
                {
                    if (q[j][u].second > g[i].se && q[j][u].first!=g[i].se) p1++;
                }
                else
                {
                    if (g[i].se > q[j][u].first&& g[i].se < q[j][u].second) p3++; else
                        if (g[i].se > q[j][u].fi) p1++; else
                            if (g[i].se < q[j][u].se) p2++;
                }
            }
            if (j == g[i].fi && p1)
            {
                an.fi++;
                an.second *= p1;
                an.second %= MOD;
            }else 
            {
                if (p1 == 0 && p2 == 0 && p3 == 0) continue; else
                    if (p1 > 0 && p2 == 0 && p3 == 0)
                    {
                        an.first++;
                        an.second *= p1;
                        an.second %= MOD;
                    }
                    else
                    if (p3 == 1 && p1 == 0 && p2 == 0) an.first++, an.second*=2, an.second%=MOD; else 
                    if (p1 == 0 && p2 > 0 && p3 == 0)
                    {
                        an.first++;
                        an.second *= p2;
                        an.second %= MOD;
                    }
                    else
                    {
                        //cout << " " << p1 << " " << p2 << " " << p3 << "\n";
                        an.first += 2, an.second = (an.second*((p1 * p2 + p1 * p3 + p2 * p3 + p3 * (p3 - 1)) % MOD))%MOD;
                    }
            }
        }
        if (an.first > ans.fi) ans = an; else
           if (an.first == ans.fi) ans.second += an.second, ans.second %= MOD;
    }
    cout << ans.first << " " << ans.second%MOD << "\n";
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