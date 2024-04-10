#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, x[300001], c[300001], dp[51][51][51], pen[55];
pll a[300001];
ll tt[300001];

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

struct dsu
{
    ll d[200001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x<y) swap(x,y);
        d[x]=y;
    }
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].fi >> a[i].se >> x[i] >> c[i];
    }
    for (int q = 1; q <= n; q++)
        for (int i = 1; i <= n-q+1; i++)
        {
            ll j=i+q-1;
            for (int mid = i; mid <= j; mid++)
            {
                for (int ht = 0; ht <= h; ht++)
                    pen[ht]=0;

                for (int u = 1; u <= m; u++)
                    if (i<j) {if (a[u].fi>=i && a[u].fi<=mid && a[u].se>mid && a[u].se<=j) pen[x[u]+1]+=c[u];}else
                    if (a[u].fi==a[u].se && a[u].fi==i) pen[x[u]+1]+=c[u];

                ll mxl=0, mxr=0;
                for (int ht = 0; ht <= h; ht++)
                {
                    if (i==j)
                    {
                        dp[i][j][ht]=ht*ht-pen[ht];
                    }else
                    {
                        mxl=max(mxl, dp[i][mid][ht]);
                        mxr=max(mxr, dp[mid+1][j][ht]);
                        dp[i][j][ht]=max(mxr+mxl-pen[ht], dp[i][j][ht]);
                    }
                    pen[ht+1]+=pen[ht];
                    //cout << i << " " << j << " " << ht << " " << pen[ht] << " : " << dp[i][j][ht] << "\n";
                }
            }
        }
    ll ans=0;
    for (int i = 0; i <= h; i++) ans=max(ans, dp[1][n][i]);
    cout << ans << "\n";
    return 0;
}

/*

*/