#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, h, w, a[1001][1001], b[1001][1001], ps[100001];

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

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    }
    vector<pll> v;
    for (int j = 1; j <= n; j++) v.pb(mp(b[1][j], j));
    sort(all(v));
    vector<ll> ans;
    for (int i = 1; i <= m; i++)
    {
        //cout << i << "\n";
        vector<pll> q;
        for (int j = 1; j <= n; j++)
        {
            q.pb(mp(a[j][i],j));
        }
        sort(all(q));
        bool tt=1;
        for (int j = 0; j < q.size(); j++)
        {
            //cout << j << "\n";
            if (q[j].fi!=v[j].fi)
            {
                {
                    tt=0;
                    break;
                }
            }
        }
        //cout << "-\n";
        if (tt)
        {
            for (int j = 0; j < n; j++)
            {
                //cout << v[j].se << " " << q[j].se << "\n";
                ps[v[j].se]=q[j].se;
            }
            //cout << "---\n";
            for (int u = 1; u <= n; u++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[ps[u]][j] << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
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

10
4 1 7 6 5 5 4 2 3 1
*/