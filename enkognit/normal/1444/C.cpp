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

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, q, T0, T1, Z, nm[500001], a[500001], L0, R0, L1, R1;
vector<pii> c[500001];
vector<pii> vv[500001];
bool tt[1000001], tl[1000001];

ll binpow(ll h, ll r, ll md=MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

struct dsu
{
    ll d[500001];

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
};

dsu g;

void dfs(int h,int k = 1)
{
    nm[h]=k;
    tt[h]=1;
    if (k==1) g.unite_sets(h, T0); else g.unite_sets(h, T1);
    for (int i = 0; i < c[h].size(); i++)
    {
        if (nm[c[h][i].se]==nm[h]) Z=1;
        if (!tt[c[h][i].se]) dfs(c[h][i].se, (k==1?2:1));
    }
}

vector<ll> w;

void dfs2(int h,int k=1)
{
    nm[h]=k;
    w.pb(h);
    tt[h]=1;
    //cout << "   " << h << " " << nm[h] << "\n";
    for (int i = upper_bound(all(c[h]), mp((int)T1, 0))-c[h].begin(); i < c[h].size() && c[h][i].fi==T1; i++)
        {
            if (nm[c[h][i].se]==nm[h]) Z=1;
            if (!tt[c[h][i].se]) dfs2(c[h][i].se, (k==1?2:1));
        }
    for (int i = upper_bound(all(c[h]), mp((int)T0, 0))-c[h].begin(); i < c[h].size() && c[h][i].fi==T0; i++)
        {
            if (nm[c[h][i].se]==nm[h]) Z=1;
            if (!tt[c[h][i].se]) dfs2(c[h][i].se, (k==1?2:1));
        }
}


void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    g.make_sets(n);
    vector<pll> v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (a[x]==a[y])
        {
            c[x].pb(mp(a[y], y));
            c[y].pb(mp(a[x], x));
        }else v.pb(mp(x, y));
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i] && !tl[a[i]])
        {
            if (c[i].size()==0)
            {
                tt[i]=1;
                continue;
            }else
            {
                Z=0;
                T0=i, T1=c[i][0].se;
                v.pb(mp(T0, T1));
                dfs(i);
                if (Z==1) tl[a[i]]=1;
            }
        }
    for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0, nm[i]=0;
    //for (int i = 1; i <= n; i++) cout << g.find_set(i) << " ";
    //cout << "\n";
    for (int i = 0; i < v.size(); i++)
        if (!tl[a[v[i].fi]] && !tl[a[v[i].se]])
        {
            if (a[v[i].fi]<a[v[i].se])
            {
                //cout << " " << a[v[i].fi] << " -> " << a[v[i].se] << "\n";
                vv[a[v[i].fi]].pb(mp(a[v[i].se], g.find_set(v[i].fi)));
            }else
            {
                //cout << " " << a[v[i].se] << " -> " << a[v[i].fi] << "\n";
                vv[a[v[i].se]].pb(mp(a[v[i].fi], g.find_set(v[i].se)));
            }
            //cout << g.find_set(v[i].fi) << " <-> " << g.find_set(v[i].se) << "\n";
            c[g.find_set(v[i].fi)].pb(mp(a[v[i].se], g.find_set(v[i].se)));
            c[g.find_set(v[i].se)].pb(mp(a[v[i].fi], g.find_set(v[i].fi)));
        }
    ll ans=0, kl=0;
    for (int i = 1; i <= k; i++) kl+=(!tl[i]);
    for (int i = 1; i <= n; i++)
        if (i==g.find_set(i)) sort(all(c[i]));
    for (int i = 1; i <= k; i++)
        if (!tl[i])
    {
        kl--;
        sort(all(vv[i]));
        //cout << i << " - " << vv[i].size() << "\n";
        ans+=kl;
        while (vv[i].size())
        {
            ll U=vv[i].back().fi;
            if (U==i)
            {
                while (vv[i].size() && vv[i].back().fi==U) vv[i].pop_back();
                continue;
            }
            //cout << " " << U << "\n";
            Z=0;
            T0=U;T1=i;
            while (vv[i].size() && vv[i].back().fi==U)
            {
                if (!tt[vv[i].back().se]) dfs2(vv[i].back().se);
                vv[i].pop_back();
            }
            //cout << "  " << Z << "\n";
            for (auto j : w) tt[j]=0, nm[j]=0;
            w.clear();
            ans-=Z;
        }
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }*/
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}