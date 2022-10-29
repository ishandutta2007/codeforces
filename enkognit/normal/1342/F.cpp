#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, T, a[1000001];
pair<ll,pll> lst;
ll dp[16][33000][16];
pll fr[16][33000][16];
ll sm[33000];
ll nxt[33000][16];
vector<ll> v[33000];

ll binpow(ll h, ll r, ll md = MOD)
{

    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

string one_own_string(ll h)
{
    string d="";
    ll j=n;
    while (j--)
    {
        d+=(h%2+'0');
        h/=2;
    }
    reverse(all(d));
    return d;
}

struct fenwick_tree
{
    ll f[20];

    void clear()
    {
        for (int i = 0; i < 20; i++) f[i]=0;
    }

    void upd(int h)
    {
        for (int i = h; i < 20; i+=(i&(-i))) f[i]++;
    }

    ll get(int h)
    {
        ll ans=0;
        for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
        return ans;
    }
};

fenwick_tree f;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f.clear();
    ll m=(1ll<<n);
    v[0].clear();
    v[0].pb(0);
    for (int i = 1; i < m; i++)
    {
        v[i].clear();
        sm[i]=0;
        for (int j = 0; j <= 15; j++) nxt[i][j]=0;
        //cout << one_own_string(i) << "\n";
        ll x=i;
        vector<ll> ww;
        for (int j = 1; j <= n; j++)
        {
            if (x%2==1)
            {
                sm[i]+=a[j];
                ww.pb(j);
                v[i].pb(j);
            }
            x/=2;
        }
        ll r = 0;
        //cout << ww.size() << "\n";
        for (int j = 0; j <= n; j++)
        {
            //cout << j << " " << r << "\n";
            while (r<ww.size() && ww[r]<=j) r++;
            if (r==ww.size()) nxt[i][j]=-1; else nxt[i][j]=ww[r];
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            for (int u = 0; u <= n; u++) dp[i][j][u]=1e18, fr[i][j][u]=mp(-1,-1);
    dp[0][0][0]=0;
    //cout << nxt[21][2] << "\n";
    for (int i = 0; i < n; i++)
    {
        //cout << i << "\n";
        bool t=0;
        for (int j = 0; j < m; j++)
            for (auto u : v[j])
                if (dp[i][j][u]!=1e18)
                {
                    //cout << i << " " << one_own_string(j) << " " << j << " " << u << " " << dp[i][j][u] << "\n";
                    t=1;
                    if (j==m-1) lst=mp(i,mp(j,u));
                    ll msk=((1ll<<n)-1)^j;
                    for (ll nmsk = msk; nmsk > 0; nmsk = ((nmsk - 1)&msk))
                        if (nxt[nmsk][u]!=-1)
                    {
                        if (sm[nmsk]>dp[i][j][u] && dp[i+1][j|nmsk][nxt[nmsk][u]]>sm[nmsk])
                        {
                            dp[i+1][j|nmsk][nxt[nmsk][u]]=min(dp[i+1][j|nmsk][nxt[nmsk][u]], sm[nmsk]);
                            fr[i+1][j|nmsk][nxt[nmsk][u]]=mp(j,u);
                        }
                    }
                }
        if (!t)
        {
            cout << n-(i-1) << "\n";
            vector<pll> qq;
            ll i=lst.fi, j=lst.se.fi, u=lst.se.se;
            while (i>0)
            {
                vector<ll> w;
                ll msk=(j^fr[i][j][u].fi), o=0;
                while (msk)
                {
                    o++;
                    if (msk%2) w.pb(o);
                    msk/=2;
                }
                for (int e = 0; e < w.size(); e++)
                {
                    if (w[e]!=u) qq.pb(mp(u,w[e]));
                }
                ll jj, ii, uu;
                uu=fr[i][j][u].se;
                jj=fr[i][j][u].fi;
                ii=i-1;
                i=ii, j=jj, u=uu;
            }
            for (int i = 0; i < qq.size(); i++)
            {
                cout << qq[i].se-f.get(qq[i].se) << " " << qq[i].fi-f.get(qq[i].fi) << "\n";
                f.upd(qq[i].se);
            }
            return;
        }
    }
    for (int u = 1; u <= n; u++)
        if (dp[n][m-1][u]!=1e18)
        {
            lst=mp(n,mp(m-1,u));
        break;
        }
    cout << n-lst.fi << "\n";
    vector<pll> qq;
    ll i=lst.fi, j=lst.se.fi, u=lst.se.se;
    while (i>0)
    {
        vector<ll> w;
        ll msk=(j^fr[i][j][u].fi), o=0;
        while (msk)
        {
            o++;
            if (msk%2) w.pb(o);
            msk/=2;
        }
        for (int e = 0; e < w.size(); e++)
        {
            if (w[e]!=u) qq.pb(mp(u,w[e]));
        }
        ll jj, ii, uu;
        uu=fr[i][j][u].se;
        jj=fr[i][j][u].fi;
        ii=i-1;
        i=ii, j=jj, u=uu;
    }
    for (int i = 0; i < qq.size(); i++)
    {
        cout << qq[i].se-f.get(qq[i].se) << " " << qq[i].fi-f.get(qq[i].fi) << "\n";
        f.upd(qq[i].se);
    }
    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
3
7 10
1 7
7 3

10

816 94 166 114 475 699 974 462 61 337

816 94 166 114 475 699 462 61 1311

94 166 114 475 699 1278 61 1311

94 166 175 475 699 1278 1311

*/