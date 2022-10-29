#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, l, r, dp[1000001], kol[100001], lst[100001], c[1000001], k[1000001];
string s, d;
vector <pll> v, an;
set <pair<ll, pll> > z;
bool tt[1000001];

struct dsu
{
    ll d[100001], mn[100001];

    void make_set(ll h)
    {
        d[h]=h;
        mn[h]=c[h];
    }

    ll find_set(ll h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    bool unite_sets(ll x,ll y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x!=y) {d[x]=y;return 1;} else return 0;
    }
};

dsu g;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.pb(mp(0,0));
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        ans+=c[i];
        g.make_set(i);
        tt[i]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            z.insert(mp((k[i]+k[j])*(abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se)),mp(i,j)));
    while (!z.empty())
    {
        ll o=(*z.begin()).se.fi, p=(*z.begin()).se.se;
        ll x=g.find_set(o), y=g.find_set(p), h=(*z.begin()).fi;
        z.erase(z.begin());
        if (x==y) continue;
        if (h>=max(g.mn[x],g.mn[y])) continue;
        ans+=h-max(g.mn[x],g.mn[y]);
        an.pb(mp(o,p));
        if (g.mn[x]<g.mn[y])g.unite_sets(y,x),tt[y]=0; else g.unite_sets(x,y),tt[x]=0;
    }
    cout << ans << "\n";
    vector <ll> u;
    for (int i = 1; i <= n; i++)if (tt[i]) u.pb(i);
    cout << u.size() << "\n";
    for (int i = 0; i < u.size(); i++) cout << u[i] << " ";
    cout << "\n";
    cout << an.size() << "\n";
    for (int i = 0; i < an.size(); i++)cout << an[i].fi << " " << an[i].se << "\n";
    return 0;
}