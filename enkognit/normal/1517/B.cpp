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

ll n, m, k, sz, b[105][105], ans[105][105];
pll a[105];
ll d[105];
string s;
bool tt[105][105];

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

void solve()
{
    cin >> n >> m;
    vector<pair<ll,pll> > v;
    for (int i = 1; i <= n; i++)
    {
        d[i]=1;
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
            v.pb(mp(b[i][j], mp(i, j)));
            tt[i][j]=0;
        }
        //sort(b[i]+1,b[i]+m+1);
    }
    sort(all(v));
    for (int i = 0; i < m; i++)
    {
        a[i+1]=mp(v[i].se.fi, v[i].se.se);
        tt[v[i].se.fi][v[i].se.se]=1;
    }
    for (int it = 1; it <= m; it++)
    {
        for (int i = 1; i <= n; i++)
        {
            while (tt[i][d[i]]) d[i]++;
            if (a[it].fi==i)
            {
                ans[i][it]=b[i][a[it].se];
            }else
            {
                tt[i][d[i]]=1;
                ans[i][it]=b[i][d[i]];
            }
        }
        //cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/