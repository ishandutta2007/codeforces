#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, a[505][505], b[505][505], d[505][505][11], ans[505][505];
ll ds[505][505];
pll v1[505], v2[505];

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
    cin >> n >> m >> k;
    if (k%2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << "-1 ";
                cout << "\n";
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        /*a[i][0]=1e18;
        a[i][m]=1e18;*/
        for (int j = 1; j < m; j++)
        {
            //a[i][j]=rnd()%(ll)1e6+1;
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
        {
            /*if (i==1)
            {
                b[0][j]=1e18;
                b[n][j]=1e18;
            }*/
            //b[i][j]=rnd()%(ll)1e6+1;
            cin >> b[i][j];
        }
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++)
        {
            //ds[i][j]=1e18;
            for (int u = (i==0 || j==0 || i==n+1 || j==m+1?0:1); u <= k/2; u++)
                d[i][j][u]=1e18;
        }
    for (int u = 1; u <= k/2; u++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                d[i][j][u]=min(min(d[i-1][j][u-1]+b[i-1][j], d[i+1][j][u-1]+b[i][j]), min(d[i][j-1][u-1]+a[i][j-1], d[i][j+1][u-1]+a[i][j]));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << d[i][j][k/2]*2 << " ";
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
    //cin >> t;
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