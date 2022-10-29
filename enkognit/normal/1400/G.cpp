#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, T, TT, ans, kl[101], kll[300005], kol2[101], ps[300005], kol[101], fact[300005], infact[300005];
bool dp[22][(1<<22)];
vector<ll> g, zz, c[300005];
vector<pair<pii, bool> > v[300005];
bool tt[300005];

ll C(ll n,ll k)
{
    if (n<k) return 0;
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x,ll y)
{
    while (x>0 && y>0)
    {
        if (x>y) swap(x, y);
        y%=x;
    }
    return x+y;
}

void dfs(int h)
{
    tt[h]=1;
    ps[h]=g.size();
    g.pb(h);
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            dfs(c[h][i]);
        }
}

void solve()
{
    cin >> n >> m;
    vector<pll> vv;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        kll[x]++;
        kll[y+1]--;
        vv.pb(mp(x, y));
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;y--;
        ll l=max(vv[x].fi,vv[y].fi), r=min(vv[x].se,vv[y].se);
        if (l>r) continue;
        v[l].pb(mp(mp(x, y), 1));
        v[r+1].pb(mp(mp(x, y), 0));
    }
    ll k=0;
    kol[0]=1;
    for (int i = 1; i <= n; i++)
    {
        k+=kll[i];
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].se==1)
            {
                if (c[v[i][j].fi.fi].size()==0) zz.pb(v[i][j].fi.fi);
                if (c[v[i][j].fi.se].size()==0) zz.pb(v[i][j].fi.se);
                c[v[i][j].fi.fi].pb(v[i][j].fi.se);
                c[v[i][j].fi.se].pb(v[i][j].fi.fi);
            }else
            {
                ll p;
                p=0;
                for (int u = 0; u < c[v[i][j].fi.fi].size(); u++)
                    if (c[v[i][j].fi.fi][u]==v[i][j].fi.se)
                    {
                        p=u;
                        break;
                    }
                c[v[i][j].fi.fi].erase(c[v[i][j].fi.fi].begin()+p);
                p=0;
                for (int u = 0; u < c[v[i][j].fi.se].size(); u++)
                    if (c[v[i][j].fi.se][u]==v[i][j].fi.fi)
                    {
                        p=u;
                        break;
                    }
                c[v[i][j].fi.se].erase(c[v[i][j].fi.se].begin()+p);
            }
        }
        if (v[i].size())
        {
            vector<ll> u;
            for (int j = 0; j < zz.size(); j++)
                if (c[zz[j]].size()>0) u.pb(zz[j]);
            zz=u;
            for (int j = 0; j < zz.size(); j++) tt[zz[j]]=0;
            for (int u = 0; u <= zz.size(); u++) kol[u]=0;
            kol[0]=1;
            ll o=0;
            for (int j = 0; j < zz.size(); j++)
                if (!tt[zz[j]])
                {
                    o++;
                    dfs(zz[j]);
                    for (int i = 0; i <= g.size(); i++) kl[i]=0;
                    for (int i = 0; i <= zz.size(); i++) kol2[i]=0;
                    for (int u = 0; u < g.size(); u++)
                        for (int p = 0; p < (1<<((int)g.size())); p++) dp[u][p]=0;
                    dp[0][0]=1;
                    dp[0][1]=1;
                    for (int u = 0; u < g.size()-1; u++)
                        for (int p = 0; p < (1<<(u+1)); p++)
                            if (dp[u][p])
                            {
                                bool t=0;
                                for (int y = 0; y < c[g[u+1]].size(); y++)
                                    if ((1<<ps[c[g[u+1]][y]])&p) t=1;
                                //cout << " - " << u << " " << p << " " << dp[u][p] << "\n";
                                dp[u+1][p]|=dp[u][p];
                                if (!t) dp[u+1][p+(1<<(u+1))]|=dp[u][p];
                            }
                    for (int p = 0; p < (1<<g.size()); p++)
                        if (dp[g.size()-1][p]) kl[__builtin_popcount(p)]++;
                    //cout << dp[1][0] << " " << dp[1][1] << " " << dp[1][2] << " " << dp[1][3] << "\n";
                    for (int i = 0; i <= g.size(); i++)
                        if (kl[i])
                        {
                            //cout << " " << i << " " << kl[i] << "\n";
                            for (int j = zz.size()-i; j > -1; j--)
                                kol2[j+i]+=kol[j]*kl[i];
                        }
                    for (int i = 0; i < g.size(); i++) ps[g[i]]=0;
                    for (int i = 0; i <= zz.size(); i++) kol[i]=kol2[i];
                    g.clear();
                }
            //cout << "  ! " << o << "\n";
        }
        //cout << i << " " << k << " " << zz.size() << ":\n";
        for (int j = 0; j <= min((ll)i, (ll)zz.size()); j++)
        {
            //cout << " " << j << " " << kol[j] << " " << k-zz.size() << " " << i-j << "\n";
            ans=(ans+kol[j]*C(k-zz.size(), i-j)%MOD)%MOD;
        }
        //cout << " " << ans << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 3e5; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
3
1 2 4
1 3 6

6
1 2 4
3 4 3
1 4 10
5 1 2
4 6 5
*/