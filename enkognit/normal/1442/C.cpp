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

ll n, m, k, q, T, Z;
pii dist[200005][21][2];
vector<pair<int, int> > c[200005];
//ll fact[300001], infact[300001];

bool islarger(pii x,pii y)
{
    if (x.fi==y.fi)
    {
        return x.se>y.se;
    }else
    {
        if (y.fi<=19 && x.fi>19) return 1; else
        if (x.fi<=19 && y.fi>19) return 0; else
        if (x.fi>19 && y.fi>19)
        {
            return x.fi>y.fi;
        }else
        {
            return (1ll<<(x.fi))+x.se>(1ll<<(y.fi))+y.se;
        }
    }
}


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

struct CMP{
    bool operator() (pair<pii, pair<pii,int> > x, pair<pii, pair<pii,int> > y)
    {
        if (islarger(x.fi, y.fi)) return false; else
        if (islarger(y.fi, x.fi)) return true; else
        {
            return (x.se.fi<y.se.fi || x.se.fi==y.se.fi && x.se.se<y.se.se);
        }
    }
};

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(y, 0));
        c[y].pb(mp(x, 1));
    }
    set<pair<pii, pair<pii,int> >, CMP> s;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 20; j++)
        dist[i][j][0]=mp(1e9,0), dist[i][j][1]=mp(1e9,0);
    dist[1][0][0]=mp(0,0);
    s.insert(mp(dist[1][0][0], mp(mp(1, 0), 0)));
    while (!s.empty())
    {
        pair<pii, pair<pii,int> > x=(*s.begin());
        s.erase(s.begin());
        ll h=x.se.fi.fi;
        for (int i = 0; i < c[h].size(); i++)
        {
            pii to=c[h][i];
            pii dst=x.fi;
            dst.se++;
            if (to.se!=x.se.fi.se) dst.fi++;
            int y=min(dst.fi, 20);
            if (islarger(dist[to.fi][y][to.se], dst))
            {
                s.erase(mp(dist[to.fi][y][to.se], mp(to, y)));
                dist[to.fi][y][to.se]=dst;
                s.insert(mp(dist[to.fi][y][to.se], mp(to, y)));
            }
        }
    }
    pii dst=mp(1e9, 0);
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j < 2; j++)
        {
            if (islarger(dst, dist[n][i][j])) dst=dist[n][i][j];
        }
    //cout << dst.fi << " " << dst.se << "\n";
    ll ans=binpow(2,dst.fi)-1;
    if (ans<0) ans+=MOD;
    ans+=dst.se;
    ans%=MOD;
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