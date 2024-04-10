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

ll n, m, k, T, ans, a[105][105];

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

ll inv(ll h)
{
    if (h==0) return 1; else return 0;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j]=s[j-1]-'0';
        }
    }
    //cout << a[1][1] << "\n";
    vector<pair<pii,pair<pii,pii> > > v;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j]==1)
            {
                ll x1=i+1, y1=j, x2=i, y2=j+1;
                if (a[i][j+1]==0) x2++; else
                if (a[i+1][j]==0) y1++;
                v.pb(mp(mp(i,j), mp(mp(x1, y1), mp(x2, y2))));
                a[i][j]=0;
                a[x1][y1]=(inv(a[x1][y1]));
                a[x2][y2]=(inv(a[x2][y2]));
                //cout << a[1][1] << "\n";
            }
    for (int i = 1; i < n-1; i++)
    {
        if (a[i][m]==0 && a[i+1][m]==0)
        {
            continue;
        }
        if (a[i][m]==1 && a[i+1][m]==0)
        {
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m-1), mp(i, m))));
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m), mp(i, m))));
            v.pb(mp(mp(i+1,m-1), mp(mp(i+1, m), mp(i, m))));
            a[i][m]=0;
            continue;
        }
        if (a[i][m]==0 && a[i+1][m]==1)
        {
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m-1), mp(i+1, m))));
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m), mp(i, m))));
            v.pb(mp(mp(i+1,m-1), mp(mp(i+1, m), mp(i, m))));
            a[i+1][m]=0;
            continue;
        }
        if (a[i][m]==1 && a[i+1][m]==1)
        {
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m-1), mp(i, m))));
            v.pb(mp(mp(i,m-1), mp(mp(i+1, m-1), mp(i+1, m))));
            a[i][m]=0;
            a[i+1][m]=0;
            continue;
        }
    }
    for (int j = 1; j < m-1; j++)
    {
        if (a[n][j]==0 && a[n][j+1]==0)
        {
            continue;
        }
        if (a[n][j]==1 && a[n][j+1]==0)
        {
            v.pb(mp(mp(n, j), mp(mp(n-1, j), mp(n-1, j+1))));
            v.pb(mp(mp(n, j), mp(mp(n-1, j), mp(n, j+1))));
            v.pb(mp(mp(n, j), mp(mp(n-1, j+1), mp(n, j+1))));
            a[n][j]=0;
            continue;
        }
        if (a[n][j]==0 && a[n][j+1]==1)
        {
            v.pb(mp(mp(n, j+1), mp(mp(n-1, j), mp(n-1, j+1))));
            v.pb(mp(mp(n, j+1), mp(mp(n-1, j), mp(n, j))));
            v.pb(mp(mp(n, j+1), mp(mp(n-1, j+1), mp(n, j))));
            a[n][j+1]=0;
            continue;
        }
        if (a[n][j]==1 && a[n][j+1]==1)
        {
            v.pb(mp(mp(n-1, j), mp(mp(n, j), mp(n-1, j+1))));
            v.pb(mp(mp(n-1, j), mp(mp(n, j+1), mp(n-1, j+1))));
            a[n][j]=0;
            a[n][j+1]=0;
            continue;
        }
    }
    if (a[n][m]==1 && a[n-1][m]==0 && a[n][m-1]==0)
    {
        v.pb(mp(mp(n, m), mp(mp(n-1, m), mp(n-1, m-1))));
        v.pb(mp(mp(n, m), mp(mp(n-1, m), mp(n, m-1))));
        v.pb(mp(mp(n, m), mp(mp(n, m-1), mp(n-1, m-1))));
    }else
    if (a[n][m]==0 && a[n-1][m]==1 && a[n][m-1]==0)
    {
        v.pb(mp(mp(n-1, m), mp(mp(n,m), mp(n, m-1))));
        v.pb(mp(mp(n-1, m), mp(mp(n,m), mp(n-1, m-1))));
        v.pb(mp(mp(n-1, m-1), mp(mp(n-1,m), mp(n,m-1))));
    }else
    if (a[n][m]==0 && a[n-1][m]==0 && a[n][m-1]==1)
    {
        v.pb(mp(mp(n-1, m), mp(mp(n,m), mp(n, m-1))));
        v.pb(mp(mp(n, m-1), mp(mp(n,m), mp(n-1, m-1))));
        v.pb(mp(mp(n-1, m-1), mp(mp(n-1,m), mp(n,m-1))));
    }else
    if (a[n][m]==1 && a[n-1][m]==1 && a[n][m-1]==0)
    {
        v.pb(mp(mp(n, m), mp(mp(n-1, m-1), mp(n, m-1))));
        v.pb(mp(mp(n-1, m-1), mp(mp(n-1, m), mp(n, m-1))));
    }else
    if (a[n][m]==1 && a[n-1][m]==0 && a[n][m-1]==1)
    {
        v.pb(mp(mp(n, m), mp(mp(n-1, m-1), mp(n-1, m))));
        v.pb(mp(mp(n-1, m-1), mp(mp(n, m-1), mp(n-1, m))));
    }else
    if (a[n][m]==0 && a[n-1][m]==1 && a[n][m-1]==1)
    {
        v.pb(mp(mp(n, m), mp(mp(n-1, m-1), mp(n-1, m))));
        v.pb(mp(mp(n-1, m-1), mp(mp(n, m-1), mp(n, m))));
    }else
    if (a[n][m]==1 && a[n-1][m]==1 && a[n][m-1]==1)
    {
        v.pb(mp(mp(n, m), mp(mp(n-1, m), mp(n, m-1))));
    }
    //cout << a[1][1] << "\n";
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << a[i][j];
        cout << "\n";
    }*/
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se.fi.fi << " " << v[i].se.fi.se << " " << v[i].se.se.fi << " " << v[i].se.se.se << "\n";
    }
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