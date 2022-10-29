#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

const ll MOD=1000000007;

ll n, m, k, T, dist[200001][2][2];
vector<pll> c[200005];

ll binpow(ll h,ll r)
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

set<pair<ll, pair<int, pair<bool, bool> > > > q;

void add(int h,bool f1,bool f2, ll x)
{
    if (dist[h][f1][f2]>x)
    {
        q.erase(mp(dist[h][f1][f2], mp(h, mp(f1, f2))));
        dist[h][f1][f2]=x;
        q.insert(mp(dist[h][f1][f2], mp(h, mp(f1, f2))));
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        c[x].pb(mp(y, h));
        c[y].pb(mp(x, h));
    }
    q.insert(mp(0, mp(1, mp(0, 0))));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int u = 0; u < 2; u++) dist[i][j][u]=1e18;
    dist[1][0][0]=0;
    while (!q.empty())
    {
        ll h=(*q.begin()).se.fi, f1=(*q.begin()).se.se.fi, f2=(*q.begin()).se.se.se;
        q.erase(q.begin());
        for (int i = 0; i < c[h].size(); i++)
        {
            add(c[h][i].fi, f1, f2, dist[h][f1][f2]+c[h][i].se);
            if (!f1)
            {
                add(c[h][i].fi, 1, f2, dist[h][f1][f2]);
                if (!f2)
                {
                    add(c[h][i].fi, 1, 1, dist[h][f1][f2]+c[h][i].se);
                }
            }
            if (!f2)
            {
                add(c[h][i].fi, f1, 1, dist[h][f1][f2]+c[h][i].se*2);
            }
        }
    }
    for (int i = 2; i <= n; i++) cout << dist[i][1][1] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
11
CCCTTTTTTCC
3
1 11
4 9
1 6
*/