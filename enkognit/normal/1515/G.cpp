#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
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

const ll MOD=1e9+7;

ll n, X, m, k, L, a[300001], hh[300001];
vector<ll> cc[300001], gg[300001];
vector<pll> c[300001];
ll ww[300001];
bool tt[300001];
vector<ll> vv;

struct segment_tree
{
    ll d[1000001];

    void make_sets(int h)
    {
        for (int i = 1; i <= h; i++) d[i]=i;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[x]=y;
    }
} g;

void dfs(int h)
{
    tt[h]=1;
    for (int i = 0; i < cc[h].size(); i++)
        if (!tt[cc[h][i]])
        {
            dfs(cc[h][i]);
        }
    vv.pb(h);
}

void dfs2(int h,int p)
{
    tt[h]=1;
    g.unite_sets(h, p);
    for (int i = 0; i < gg[h].size(); i++)
        if (!tt[gg[h][i]])
        {
            dfs2(gg[h][i], p);
        }
}

void dfs3(int h)
{
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi])
        {
            hh[c[h][i].fi]=hh[h]+c[h][i].se;
            dfs3(c[h][i].fi);
        }
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
    cin >> n >> m;
    vector<pair<pll, ll> > ed, e;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        cc[x].pb(y);
        gg[y].pb(x);
        ed.pb(mp(mp(x, y), h));
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs(i);
        }

    reverse(all(vv));
    g.make_sets(n);
    for (int i = 1; i <= n; i++) tt[i]=0;
    for (int i = 0; i < vv.size(); i++)
        if (!tt[vv[i]]) dfs2(vv[i], vv[i]);


    for (int i = 0; i < ed.size(); i++)
        if (g.find_set(ed[i].fi.fi)==g.find_set(ed[i].fi.se))
        {
            e.pb(ed[i]);
            c[ed[i].fi.fi].pb(mp(ed[i].fi.se, ed[i].se));
            //c[ed[i].fi.se].pb(mp(ed[i].fi.fi, -ed[i].se));
        }

    for (int i = 1; i <= n; i++) tt[i]=0;

    //cout << "--\n";

    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs3(i);
        }

    //cout << "---\n";
    for (int i = 0; i < e.size(); i++)
    {
        ll u=abs(hh[e[i].fi.fi]-hh[e[i].fi.se]+e[i].se);
        ww[g.find_set(e[i].fi.fi)]=gcd(ww[g.find_set(e[i].fi.fi)], u);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll x, s, t;
        cin >> x >> s >> t;
        if (s%gcd(ww[g.find_set(x)], t)==0) cout << "YES\n"; else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
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
*/