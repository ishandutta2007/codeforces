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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, a[101][101], nm[101][101];

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

ll inverse(ll h)
{
    return binpow(h, md-2, md);
}
/*
void dfs(int x,int y,int k)
{
    nm[x][y]=k;
    for (int i = 0; i < c[x][y].size(); i++)
    {
        ll xx=c[x][y][i].fi.fi;
        ll yy=c[x][y][i].fi.se;
        ll u=c[x][y][i].se;
        ll o=(k-1+u)%2+1;
        if (!nm[xx][yy])
        {
            dfs(xx,yy,o);
        }
        if (nm[xx][yy]!=o)
        {
            T=1;
        }
    }
}*/

void solve()
{
    T=0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ll o=a[i][j];
            if ((i+j)%2!=o%2) o++;
            cout << o << " ";
        }
        cout << "\n";
    }
    /*vector<pii> vv;
    vv.pb(mp(0, -1));
    vv.pb(mp(-1, 0));
    vv.pb(mp(0, 1));
    vv.pb(mp(1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int u = 0; u < 4; u++)
            {
                ll ii=i+vv[u].fi, jj=j+vv[u].se;
                if (ii>0 && ii<=n && jj>0 && jj<=m)
                {
                    if (abs(a[i][j]-a[ii][jj])==1)
                    {
                        c[i][j].pb(mp(mp(ii, jj), 1));
                        c[ii][jj].pb(mp(mp(i, j), 1));
                    }else
                    if (a[ii][jj]==a[i][j])
                    {
                        c[i][j].pb(mp(mp(ii, jj), 0));
                        c[ii][jj].pb(mp(mp(i, j), 0));
                    }
                }
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!nm[i][j])
            {
                dfs(i, j, 1);
            }*/
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
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
2 2 1
ab
ba
ba
ab

2 2 1
ab
cd
dc
ba

3 3 1
abc
acc
adc
cda
acc
cba

*/