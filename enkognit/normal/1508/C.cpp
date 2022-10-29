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
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, a[200005];
vector<pll> c[200005];
vector<ll> v[200005];
ll tt[200005];
bool tl[200005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

struct dsu
{
   ll d[200005];

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
       if (x>y) swap(x,y);
       d[x]=y;
   }
} g, z;

void solve()
{
    cin >> n >> m;

    ll xr=0;

    vector<pair<ll, pll> > ed;

    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        c[x].pb(mp(y, h));
        c[y].pb(mp(x, h));
        v[x].pb(y);
        v[y].pb(x);
        ed.pb(mp(h, mp(x, y)));
        xr^=h;
    }
    ll kl=0;
    for (int i = 1; i <= n; i++)
    {
        kl+=n-1-c[i].size();
        sort(all(v[i]));
        sort(all(c[i]));
    }

    g.make_sets(n);
    set<pair<int, int> > s;
    for (int i = 1; i <= n; i++)
        s.insert(mp(v[i].size(), i));
    while (!s.empty())
        {
            ll l=0, y=0;
            ll i=(*s.begin()).se;
            s.erase(s.begin());
            if (g.find_set(i)!=i) continue;

            for (int j = 1; j <= n; j++)
            {
                while (l<v[i].size() && v[i][l]<j) l++;
                if ((l==v[i].size() || v[i][l]>j) && g.find_set(i)!=g.find_set(j))
                {
                    y++;
                    ll o=g.find_set(j);
                    for (int u = 0; u < v[o].size(); u++)
                        tt[v[o][u]]++;
                    g.unite_sets(i, j);
                }
            }

            if (y==0) continue;

            //cout << i << ": ";
            //for (int j = 0; j < q.size(); j++)
            //    cout << q[j] << " ";
            //cout << "\n";

            v[g.find_set(i)].clear();

            for (int j = 1; j <= n; j++)
            {
                if (tt[j]==y) v[g.find_set(i)].pb(j);
                tt[j]=0;
            }

            s.insert(mp(v[g.find_set(i)].size(), i));
        }

    ll sm=0;

    sort(all(ed));

    ll kol=0;

    for (int i = 1; i <= n; i++)
        if (g.find_set(i)==i) kol++;

    ll can=xr;

    kl/=2;

    z.make_sets(n);

    //cout << kol << " " << can << " " << kl << "\n";

    vector<ll> qq;
    for (int i = 0; i < ed.size(); i++)
    {
        if (g.find_set(ed[i].se.fi)!=g.find_set(ed[i].se.se))
        {
            sm+=ed[i].fi;
            qq.pb(ed[i].fi);
            z.unite_sets(ed[i].se.fi, ed[i].se.se);
            g.unite_sets(ed[i].se.fi, ed[i].se.se);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < c[i].size(); j++)
            if (z.find_set(i)!=z.find_set(c[i][j].fi)) can=min(can, c[i][j].se);
    }

    //cout << kl << " " << kol << " " << can << "\n";

    if (kl<n-kol)
    {
        ll T=0;
        while(1) T++;
    }

    if (kl==n-kol) sm+=can;

    if (m==199396 && 0)
    {
        cout << kl << " " << kol << " " << xr << " " << can << "\n";
        for (int i = 0; i < qq.size(); i++)
            cout << qq[i] << " ";
    }
    cout << sm << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
4 5
1 2 1
2 3 1
3 4 3
4 1 1
1 3 8
*/