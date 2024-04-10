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

ll n, m, kol=1;
ll dist[1001][1001];
vector<pll> c[1001];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pll> vv, v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        c[x].pb(mp(y, k));
        c[y].pb(mp(x, k));
        vv.pb(mp(x, y));
    }
    for (int i = 1; i <= n; i++)
    {
        set<pii> s;
        for (int j = 1; j <= n; j++) dist[i][j]=1e9;
        dist[i][i]=0;
        s.insert(mp(0, i));
        while (!s.empty())
        {
            ll x=(*(s.begin())).se;
            s.erase(s.begin());
            for (int u = 0; u < c[x].size(); u++)
                if (dist[i][c[x][u].fi] > dist[i][x] + c[x][u].se)
                {
                    s.erase(mp(dist[i][c[x][u].fi], c[x][u].fi));
                    dist[i][c[x][u].fi] = dist[i][x] + c[x][u].se;
                    s.insert(mp(dist[i][c[x][u].fi], c[x][u].fi));
                }
        }
        //cout << i << " :\n";
        //for (int j = 1; j <= n; j++)
        //    cout << " " << j << " " << dist[i][j] << "\n";
    }
    for (int i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    ll ans=1e9;
    for (int i = 0; i < m; i++)
    {
        ll o=0;
        for (int j = 0; j < v.size(); j++)
        {
            //cout << " " << v[j].fi << " " << v[j].se << " :\n  " << dist[v[j].fi][vv[i].fi]+dist[v[j].se][vv[i].se] << "\n  "
            // << dist[v[j].se][vv[i].fi]+dist[v[j].fi][vv[i].se] << "\n  " << dist[v[j].fi][v[j].se] << "\n";
            o+=min(min(dist[v[j].fi][vv[i].fi]+dist[v[j].se][vv[i].se],
                       dist[v[j].se][vv[i].fi]+dist[v[j].fi][vv[i].se]),
                    dist[v[j].fi][v[j].se]);
        }
        //cout << i << " " << o << "\n";
        ans=min(ans, o);
    }
    cout << ans << "\n";
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/