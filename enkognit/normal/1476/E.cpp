#include <bits/stdc++.h>
//#include <random>
//#include <ctime>
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
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
//mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

int n, m, k, T, Z, zz[100005], ans[100005], kl[100005];
bool tt[100005];
string p[100005], s[100005];
vector<int> c[100005], g[100005];
vector<pair<string,int> > vv[16];

//void add()

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

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        ll o=0;
        string z="";
        for (int j = 0; j < k; j++)
        {
            o*=2;
            if (p[i][j]!='_') o++, z+=p[i][j];
        }
        vv[o].pb(mp(z, i));
    }
    for (int i = 0; i < 16; i++)
    {
        sort(all(vv[i]));
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i];
        cin >> zz[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x=zz[i];
        for (int j = 0; j < (1<<k); j++)
            if (vv[j].size())
            {
                ll y=j;
                string h="";
                for (int u = k-1; u > -1; u--)
                {
                    if (y%2) h+=s[i][u];
                    y/=2;
                }
                reverse(all(h));
                ll l=0, r=vv[j].size()-1;
                while (l<r)
                {
                    int w=(l+r+1)/2;
                    if (vv[j][w].fi<=h) l=w; else r=w-1;
                }
                if (vv[j][l].fi==h)
                {
                    c[i].pb(vv[j][l].se);
                }
            }
        bool TT=0;
        for (int j = 0; j < c[i].size(); j++)
            if (c[i][j]!=x)
            {
                g[x].pb(c[i][j]);
                kl[c[i][j]]++;
            }else TT=1;
        if (!TT)
        {
            cout << "NO\n";
            return;
        }
    }
    set<pii> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(mp(kl[i], i));
    }
    ll T=0;
    while (s.size())
    {
        if ((*s.begin()).fi>0)
        {
            cout << "NO\n";
            return;
        }
        ll x=(*s.begin()).se;
        T++;
        ans[T]=x;
        s.erase(s.begin());
        for (int i = 0; i < g[x].size(); i++)
        {
            s.erase(mp(kl[g[x][i]], g[x][i]));
            kl[g[x][i]]--;
            s.insert(mp(kl[g[x][i]], g[x][i]));
        }
    }
    cout << "YES\n";
    ll l=1;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i]) cout << ans[i] << " "; else
        {
            while (tt[l]) l++;
            cout << l << " ";
            l++;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("stones.in","r",stdin);
    //freopen("stones.out","w",stdout);
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
6 4 13
1 2
2 3
3 4
4 5
*/