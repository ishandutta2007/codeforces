#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj, a[100001], dist[100001][51];
vector<pll> c[100001];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
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
    set<pair<ll, pii> > s;
    s.insert(mp(0, mp(1, 0)));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 50; j++) dist[i][j]=1e18;
    dist[1][0]=0;
    while (!s.empty())
    {
        ll x=(*s.begin()).se.fi, y=(*s.begin()).se.se;
        s.erase(s.begin());
        for (int i = 0; i < c[x].size(); i++)
            if (dist[c[x][i].fi][(y==0?c[x][i].se:0)] > dist[x][y] + c[x][i].se*(c[x][i].se+2*y))
            {
                s.erase(mp(dist[c[x][i].fi][(y==0?c[x][i].se:0)], mp(c[x][i].fi, (y==0?c[x][i].se:0))));
                dist[c[x][i].fi][(y==0?c[x][i].se:0)] = dist[x][y] + c[x][i].se*(c[x][i].se+2*y);
                s.insert(mp(dist[c[x][i].fi][(y==0?c[x][i].se:0)], mp(c[x][i].fi, (y==0?c[x][i].se:0))));
            }
    }
    for (int i = 1; i <= n; i++)
        if (dist[i][0]==1e18) cout << "-1 "; else cout << dist[i][0] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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

10
4 1 7 6 5 5 4 2 3 1
*/